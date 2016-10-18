#!/usr/bin/env python

import Image

im = Image.open("image.jpg")
print(im.format, im.size, im.mode)

box = (0, 0, 400, 400)
region = im.crop(box)

raw_input('')

