#!/usr/bin/env python
# coding: utf-8

import socket

target_host = 'www.baidu.com'
target_port = 80

# 建立一个socket对象
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 连接到服务器
client.connect((target_host, target_port))

# 发送HTTP请求
client.send('GET / HTTP/1.1\r\nHost: baidu.com\r\n\r\n')

# 接收一些数据
response = client.recv(4096)

print(response)
