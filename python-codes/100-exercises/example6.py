#!/usr/bin/env python
# -*- coding: UTF-8 -*-
# 题目：斐波那契数列，0 1 1 2 3 5 8 ...


def fib(n):
    fibs = [0, 1]
    if n == 1:
        return [0]
    if n == 2:
        return fibs

    for i in range(2, n):
        fibs.append(fibs[-1] + fibs[-2])
    return fibs

print fib(10)
