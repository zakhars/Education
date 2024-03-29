import socket
import time


class ClientError(Exception):
    pass


class Client:
    def __init__(self, host, port, timeout=None):
        self.sock = socket.create_connection((host, port), timeout)

    def put(self, symbol, value, timestamp=None):
        try:
            if timestamp is None:
                timestamp = str(int(time.time()))
            request = f'put {symbol} {value} {timestamp}\n'.encode()
            print(request)
            self.sock.sendall(request)
            response = self.sock.recv(1024).decode()
            if response != 'ok\n\n':
                raise ClientError
            print(response)
        except Exception:
            raise ClientError

    def get(self, mask):
        try:
            response = {}
            request = f'get {mask}\n'.encode()
            print(request)
            self.sock.sendall(request)
            data = self.sock.recv(1024).decode()
            if 'ok' not in data:
                raise ClientError
            if data != 'ok\n\n':
                response = Client._dict_from_response(data)
            print(response)
            return response
        except Exception:
            raise ClientError

    def close(self):
        try:
            self.sock.close()
        except Exception:
            raise ClientError

    @staticmethod
    def _dict_from_response(response: str):
        metrics = {}
        lines = response.split('\n')
        for line in lines[1:-2]:
            symbol, value, timestamp = line.split(' ')
            metrics.setdefault(symbol, []).append((int(timestamp), float(value)))
        for val in metrics.values():
            val.sort(key=lambda x: x[0])
        return metrics


def _main1():
    client = Client("127.0.0.1", 10001, timeout=None)

    client.put('test', 0.5, 1)
    client.put('test', 2.0, 2)
    client.put('test', 0.4, 2)
    client.put('load', 301, 3)
    client.get('key_not_exists')
    client.get('test')
    client.get('get_client_error')
    client.get('*')


if __name__ == "__main__":
    _main1()


# Teacher"s solution

class ClientError1(Exception):
    """Общий класс исключений клиента"""
    pass


class ClientSocketError1(ClientError1):
    """Исключение, выбрасываемое клиентом при сетевой ошибке"""
    pass


class ClientProtocolError1(ClientError1):
    """Исключение, выбрасываемое клиентом при ошибке протокола"""
    pass


class Client1:
    def __init__(self, host, port, timeout=None):
        # класс инкапсулирует создание сокета
        # создаем клиентский сокет, запоминаем объект socket.socket в self
        self.host = host
        self.port = port
        try:
            self.connection = socket.create_connection((host, port), timeout)
        except socket.error as err:
            raise ClientSocketError1("error create connection", err)

    def _read(self):
        """Метод для чтения ответа сервера"""
        data = b""
        # накапливаем буфер, пока не встретим "\n\n" в конце команды
        while not data.endswith(b"\n\n"):
            try:
                data += self.connection.recv(1024)
            except socket.error as err:
                raise ClientSocketError1("error recv data", err)

        # не забываем преобразовывать байты в объекты str для дальнейшей работы
        decoded_data = data.decode()

        status, payload = decoded_data.split("\n", 1)
        payload = payload.strip()

        # если получили ошибку - бросаем исключение ClientError
        if status == "error":
            raise ClientProtocolError1(payload)

        return payload

    def put(self, key, value, timestamp=None):
        timestamp = timestamp or int(time.time())

        # отправляем запрос команды put
        try:
            self.connection.sendall(
                f"put {key} {value} {timestamp}\n".encode()
            )
        except socket.error as err:
            raise ClientSocketError1("error send data", err)

        # разбираем ответ
        self._read()

    def get(self, key):
        # формируем и отправляем запрос команды get
        try:
            self.connection.sendall(
                f"get {key}\n".encode()
            )
        except socket.error as err:
            raise ClientSocketError1("error send data", err)

        # читаем ответ
        payload = self._read()

        data = {}
        if payload == "":
            return data

        # разбираем ответ для команды get
        for row in payload.split("\n"):
            key, value, timestamp = row.split()
            if key not in data:
                data[key] = []
            data[key].append((int(timestamp), float(value)))

        return data

    def close(self):
        try:
            self.connection.close()
        except socket.error as err:
            raise ClientSocketError1("error close connection", err)


def _main2():
    # проверка работы клиента
    client = Client("127.0.0.1", 8888, timeout=5)
    client.put("test", 0.5, timestamp=1)
    client.put("test", 2.0, timestamp=2)
    client.put("test", 0.5, timestamp=3)
    client.put("load", 3, timestamp=4)
    client.put("load", 4, timestamp=5)
    print(client.get("*"))

    client.close()


if __name__ == "__main__":
    _main2()
