import socket
import threading
from collections import OrderedDict

class MetricsServer:
    def __init__(self, host, port):
        self.sock = socket.socket()
        self.sock.bind((host, port))
        self.sock.listen()
        self.threads = []
        self.connections = []
        self.metrics = {}
        self.resp_success = b'ok'
        self.resp_newline = b'\n'
        self.resp_failure = b'error\nwrong command\n\n'
        self.mutex = threading.RLock()

    def start(self):
        try:
            while True:
                conn, addr = self.sock.accept()
                th = threading.Thread(target=self.process_request, args=(conn,))
                th.start()
                self.threads.append(th)
        except Exception:
            pass

    def process_put(self, items):
        metric = items[1]
        value = float(items[2])
        timestamp = int(items[3])
        with self.mutex:
            self.metrics.setdefault(metric, OrderedDict())[timestamp] = value

    def process_get(self, items):
        response = self.resp_success + self.resp_newline
        with self.mutex:
            symbols = self.metrics.keys() if items[1] == '*' else [items[1]]
            for metric in symbols:
                if metric in self.metrics:
                    values = self.metrics[metric]
                    for ts, val in values.items():
                        response += f'{metric} {val} {ts}\n'.encode()
        response += self.resp_newline
        return response

    def process_request(self, conn):
        while True:
            items = MetricsServer.read_request(conn)
            if items is None:
                return
            if len(items) == 0 or items[0] not in ['put', 'get']:
                self._send_failure(conn)
            elif items[0] == 'put':
                try:
                    self.process_put(items)
                except Exception:
                    self._send_failure(conn)
                else:
                    conn.sendall(self.resp_success + (self.resp_newline * 2))
            else: # 'get'
                try:
                    response = self.process_get(items)
                except Exception as e:
                    self._send_failure(conn)
                else:
                    conn.sendall(response)

    def _send_failure(self, conn):
        if conn:
            conn.sendall(self.resp_failure)

    def close(self):
        for th in self.threads:
            th.join()
        for conn in self.connections:
            conn.close()
        self.sock.close()

    @staticmethod
    def read_request(conn):
        data = b''
        try:
            while not data.endswith(b'\n'):
                portion = conn.recv(1024)
                data += portion
        except Exception:
            return None
        decoded_data = data.decode()
        decoded_data = decoded_data.strip()
        return decoded_data.split()

def run_server(host, port):
    server = MetricsServer(host, port)
    server.start()
    server.close()


# Teacher's solution

'''
import asyncio


class Storage:
    """Класс для хранения метрик в памяти процесса"""

    def __init__(self):
        # используем словарь для хранения метрик
        self._data = {}

    def put(self, key, value, timestamp):
        if key not in self._data:
            self._data[key] = {}

        self._data[key][timestamp] = value

    def get(self, key):
        data = self._data

        # вовзращаем нужную метрику если это не *
        if key != "*":
            data = {
                key: data.get(key, {})
            }
        
        # для простоты мы храним метрики в обычном словаре и сортируем значения
        # при каждом запросе, в реальном приложении следует выбрать другую
        # структуру данных
        result = {}
        for key, timestamp_data in data.items():
            result[key] = sorted(timestamp_data.items())

        return result


class ParseError(ValueError):
    pass


class Parser:
    """Класс для реализации протокола"""
    
    def encode(self, responses):
        """Преобразование ответа сервера в строку для передачи в сокет"""
        rows = []
        for response in responses:
            if not response:
                continue
            for key, values in response.items():
                for timestamp, value in values:
                    rows.append(f"{key} {value} {timestamp}")

        result = "ok\n"

        if rows:
            result += "\n".join(rows) + "\n"

        return result + "\n"

    def decode(self, data):
        """Разбор команды для дальнейшего выполнения. Возвращает список команд для выполнения"""
        parts = data.split("\n")
        commands = []
        for part in parts:
            if not part:
                continue

            try:
                method, params = part.strip().split(" ", 1)
                if method == "put":
                    key, value, timestamp = params.split()
                    commands.append(
                        (method, key, float(value), int(timestamp))
                    )
                elif method == "get":
                    key = params
                    commands.append(
                        (method, key)
                    )
                else:
                    raise ValueError("unknown method")
            except ValueError:
                raise ParseError("wrong command")

        return commands


class ExecutorError(Exception):
    pass


class Executor:
    """Класс Executor реализует метод run, который знает как выполнять команды сервера"""
    
    def __init__(self, storage):
        self.storage = storage

    def run(self, method, *params):
        if method == "put":
            return self.storage.put(*params)
        elif method == "get":
            return self.storage.get(*params)
        else:
            raise ExecutorError("Unsupported method")


class EchoServerClientProtocol(asyncio.Protocol):
    """Класс для реализции сервера при помощи asyncio"""
    
    # Обратите внимание на то, что storage является атрибутом класса
    # Объект self.storage для всех экземмпляров класса EchoServerClientProtocol
    # будет являться одним и тем же объектом для хранения метрик.  
    storage = Storage()

    def __init__(self):
        super().__init__()

        self.parser = Parser()
        self.executor = Executor(self.storage)
        self._buffer = b''

    def process_data(self, data):
        """Обработка входной команды сервера"""
        
        # разбираем сообщения при помощи self.parser
        commands = self.parser.decode(data)

        # выполняем команды и запоминаем результаты выполнения
        responses = []
        for command in commands:
            resp = self.executor.run(*command)
            responses.append(resp)

        # преобразовываем команды в строку
        return self.parser.encode(responses)

    def connection_made(self, transport):
        self.transport = transport

    def data_received(self, data):
        """Метод data_received вызывается при получении данных в сокете"""
        self._buffer += data
        try:
            decoded_data = self._buffer.decode()
        except UnicodeDecodeError:
            return
      
        # ждем данных, если команда не завершена символом \n
        if not decoded_data.endswith('\n'):
            return
        
        self._buffer = b''

        try:
            # обрабатываем поступивший запрос
            resp = self.process_data(decoded_data)
        except (ParseError, ExecutorError) as err:
            # формируем ошибку, в случае ожидаемых исключений
            self.transport.write(f"error\n{err}\n\n".encode())
            return

        # формируем успешный ответ
        self.transport.write(resp.encode())


if __name__ == "__main__":
    # запуск сервера для тестирования
    loop = asyncio.get_event_loop()
    coro = loop.create_server(
        EchoServerClientProtocol,
        '127.0.0.1', 8888
    )
    server = loop.run_until_complete(coro)
    try:
        loop.run_forever()
    except KeyboardInterrupt:
        pass

    server.close()
    loop.run_until_complete(server.wait_closed())
    loop.close()
'''