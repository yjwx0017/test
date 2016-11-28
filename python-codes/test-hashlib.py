#!/usr/bin/env python
# coding: utf-8

# 摘要算法

import hashlib

# md5算法，另外还有sha1(), sha224(), sha256(), sha384(), sha512()
m = hashlib.md5()

# 传入需要计算md5码的文本
m.update('Hello,')

# 可以继续传入文本
m.update('World!')

# 返回md5码，二进制
# m.digest()

# md5码，十六进制字符串
print(m.hexdigest())
