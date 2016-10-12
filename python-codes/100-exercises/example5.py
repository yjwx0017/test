#!/usr/bin/env python
# -*- coding: UTF-8 -*-
# 题目：输入三个整数，请把这3个数由小到大输出

l = []
for i in range(3):
    x = int(raw_input('integer:\n'))
    l.append(x)

l.sort()
print l
