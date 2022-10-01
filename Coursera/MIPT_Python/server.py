import socket


sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(('127.0.0.1', 10001))  # Max port is 65535. Address 127.0.0.1 means server listens only local connections. Empty '' or '0.0.0.0' means any interface
sock.listen(socket.SOMAXCONN)  # Parameter means size of queue for incoming connections. If overflow - "connection refused" is returned to client
while True:
    conn, addr = sock.accept()  # Blocks until client connects. conn is duplex channel which supports read (recv) and write (send)
    data = conn.recv(1024)  # 1024 is a buffer size
    if not data:  # Client closed connection
        break
    # Process data
    request = f"Processed on server {data.decode('utf-8')}"
    response = request.encode('utf-8')
    conn.sendall(response)
conn.close()
sock.close()
