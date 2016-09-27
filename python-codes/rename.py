#!/usr/bin/env python
# rename *.h to *.cpp

import os

for dirpath, dirnames, filenames in os.walk('.'):
    for filename in filenames:
        parts = filename.split('.')
        basename = parts[0]
        ext = '.cpp'
        os.rename(filename, basename + ext)
        print(filename)
