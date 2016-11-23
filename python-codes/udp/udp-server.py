#!/usr/bin/env python
# coding: utf-8

import socket

bind_ip = '0.0.0.0'
bind_port = 9999

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server.bind((bind_ip, bind_port))
print('[*] Server is running...')

while True:
    data, addr = server.recvfrom(4096)
    print('[*] From %s:%s' % (addr[0], addr[1]))
    print('[*]     Received: %s' % data)
