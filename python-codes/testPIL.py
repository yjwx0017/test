#!/usr/bin/env python

import Image, ImageDraw, ImageFont

im = Image.open("image.jpg")
print(im.format, im.size, im.mode)

box = (0, 0, 400, 400)
region = im.crop(box)
# region.show()

draw = ImageDraw.Draw(im)
draw.line((0, 0, 200, 200), fill = 128)
draw.arc((0, 0, 200, 200), 0, 45, fill = (0, 255, 0))
draw.text((0, 0), "Hello PIL", fill=255)

font = ImageFont.truetype("arial.ttf", 20)
draw.text((20, 20), "Hello Boy!", font=font, fill=(0, 255, 0))

del draw

im.show()


