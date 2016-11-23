#!/usr/bin/env python
# coding: utf-8

import socket

target_host = '127.0.0.1'
target_port = 9999

# 创建一个套接字
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 连接到服务器
client.connect((target_host, target_port))

# 发送一些数据
client.send('Hello!')

# 接收一些数据
response = client.recv(4096)

print(response)
