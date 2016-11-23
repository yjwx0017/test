#!/usr/bin/env python
# coding: utf-8

import socket
import threading

bind_ip = '0.0.0.0'
bind_port = 9999

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind((bind_ip, bind_port))

# 最大连接数5
server.listen(5)

print('[*] Listening on %s:%d' % (bind_ip, bind_port))

# 线程函数
def handle_client(client_socket):
    # 打印出接收到的数据
    request = client_socket.recv(1024)
    print('[*] Received: %s' % request)

    # 返还一个数据包
    client_socket.send('ACK!')

    client_socket.close()

# 服务端主循环
while True:
    client, addr = server.accept()
    print('[*] Accepted connection from: %s:%d' % (addr[0], addr[1]))

    # 创建一个线程处理客户端请求
    client_handler = threading.Thread(target=handle_client, args=(client,))
    client_handler.start()
