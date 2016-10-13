#!/usr/bin/env python
# -*- coding: UTF-8 -*-
# 题目：判断101-200之间有多少个素数，并输出所有素数
# 素数只能被1和本身整除

import math

count = 0

for number in range(101, 201):
    find = 1
    
    k = int(math.sqrt(number + 1))
    for i in range(2, k + 1):
        if number % i == 0:
            find = 0
            break

    if find:
        count += 1
        print number

print 'The total is ', count        

