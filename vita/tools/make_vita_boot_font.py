#!/usr/bin/env python3
"""Make the fonts of the Vita start-up screen (vita/src/vita_bootui.c, drawn before
vitaGL starts): Oswald (SIL Open Font License, vita/fonts/OFL.txt), Latin-1,
as 8-bit alpha glyphs, in two sizes. Run by CMake for the Vita build; the files are
packed into the .vpk as font/boot.font and font/boot_small.font.

usage: tools/make_vita_boot_font.py <output directory>
Needs Pillow.

Format, little endian:
    "VBF1", u16 line height, u16 ascent
    224 glyphs for the Latin-1 codes 32..255:
        u16 width, u16 height, i16 x offset, i16 y offset (from the line top),
        u16 advance, u32 offset of its rows in the bitmap data
    u32 bitmap size, then the bitmap data (width * height alpha bytes per glyph)
"""
import os
import struct
import sys

from PIL import Image, ImageDraw, ImageFont

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FONT = os.path.join(ROOT, 'fonts', 'Oswald.ttf')
SIZES = {'boot.font': 26, 'boot_small.font': 17}


def make(path, size):
    font = ImageFont.truetype(FONT, size)
    font.set_variation_by_name('Regular')
    ascent, descent = font.getmetrics()
    glyphs, data = [], bytearray()
    for code in range(32, 256):
        ch = bytes([code]).decode('latin-1')
        advance = int(round(font.getlength(ch)))
        box = font.getbbox(ch)
        if 0x7F <= code < 0xA0 or box[2] <= box[0] or box[3] <= box[1]:
            glyphs.append((0, 0, 0, 0, advance, len(data)))
            continue
        w, h = box[2] - box[0], box[3] - box[1]
        img = Image.new('L', (w, h), 0)
        ImageDraw.Draw(img).text((-box[0], -box[1]), ch, font=font, fill=255)
        glyphs.append((w, h, box[0], box[1], advance, len(data)))
        data += img.tobytes()
    with open(path, 'wb') as f:
        f.write(b'VBF1' + struct.pack('<HH', ascent + descent, ascent))
        for g in glyphs:
            f.write(struct.pack('<HHhhHI', *g))
        f.write(struct.pack('<I', len(data)))
        f.write(data)
    print('wrote %s (%d bytes, line %d)' % (path, os.path.getsize(path), ascent + descent))


def main():
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    os.makedirs(sys.argv[1], exist_ok=True)
    for name, size in SIZES.items():
        make(os.path.join(sys.argv[1], name), size)


if __name__ == '__main__':
    main()
