#!/usr/bin/env python
# -*- coding: UTF-8 -*-
# 题目：输出9*9乘法口诀表

for i in range(1, 10):
    for j in range(1, 10):
        result = i * j
        print '%d * %d = %d' % (i, j, result)

    print '' # 空行
