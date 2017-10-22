import socket
import time
import json

class Client:
    def __init__(self, host, port, timeout=None):
        self.sock = socket.create_connection((host, port), timeout)

    def put(self, symbol, value, timestamp=None):
        try:
            if timestamp is None:
                timestamp = str(int(time.time()))
            self.sock.sendall(f'put {symbol} {value} {timestamp}\n'.encode('utf-8'))
        except Exception as ex:
            print(ex.args[0])

    def get(self, mask):
        try:
            response = {}
            data = self.sock.recv(1024)
            data_str = data.decode('utf-8')
            return data_str
        except Exception as ex:
            print(ex.args[0])

client = Client('127.0.0.1', 10001)
client.put('RTT', 123)
print(client.get('*'))
