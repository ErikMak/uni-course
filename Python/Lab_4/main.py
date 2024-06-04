from functools import partial
import socket
import socketserver
import re
from pathlib import Path

class Buffer:
    def __init__(self):
        self.buffer = b""

    def get_line(self, recv, delim=b"\r\n\r\n"):
        if self.buffer.endswith(delim):
            line = self.buffer.decode()
            self.buffer = b""
            return line
        while delim not in self.buffer:
            data = recv(1024)
            if not data:
                return None
            self.buffer += data
        line, _, self.buffer = self.buffer.partition(delim)
        return line.decode()

class MyTCPHandler(socketserver.BaseRequestHandler):
    def handle(self):
        # HTTP REQUEST
        rdr = Buffer()
        request = rdr.get_line(self.request.recv)
        headers = request.split('\n')
        filename = headers[0].split()[1]
        # Другие страницы
        if filename == '/':
            filename = '/index.html'


        filename = filename[1:]
        try:
            fin = open(filename)
            content = fin.read()
            fin.close()

            response = 'HTTP/1.0 200 OK\n\n' + content
        except FileNotFoundError:
            response = 'HTTP/1.0 404 NOT FOUND\n\nFile Not Found'



        # HTTP RESPONSE
        self.request.sendall(response.encode())

if __name__ == "__main__":
    HOST, PORT = "localhost", 8000

    with socketserver.TCPServer((HOST, PORT), MyTCPHandler) as server:
        server.serve_forever()