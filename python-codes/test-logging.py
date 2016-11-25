#!/usr/bin/env python
# coding: utf-8

import logging

# level
# 大于指定级别的日志将被输出
# CRITICAL 50
# ERROR    40
# WARNING  30
# INFO     20
# DEBUG    10
# NOTSET   0

#logging.warning('Watch out!');
#logging.info('I told you so');

# Logging to a file
logging.basicConfig(filename='test-logging.log', level=logging.DEBUG)
logging.debug('This message should go to the log file')
logging.info('So should this')
logging.warning('And this, too')
