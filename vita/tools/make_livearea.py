#!/usr/bin/env python3
"""Make the Vita LiveArea pictures from the art in vita/art (run by hand; the results are
kept in vita/sce_sys).

  art/poster.jpg  the box art: the "Conker's Bad Fur Day" logo, Conker and Berri, on black
  art/logo.jpg    the short "Conker's BFD" logo, on black

become:
  sce_sys/icon0.png                       128x128  bubble icon (Conker with his pint)
  sce_sys/pic0.png                        960x544  shown while the app starts (and under the
                                                   boot screen's update panel)
  sce_sys/livearea/contents/bg.png        840x500  LiveArea background, with the credits
  sce_sys/livearea/contents/startup.png   280x158  LiveArea start gate (the short logo)
All are 8-bit palette PNGs, as the LiveArea expects.

usage: vita/tools/make_livearea.py
Needs Pillow. The credits use Oswald (vita/fonts, SIL Open Font License).
"""
import os

from PIL import Image, ImageDraw, ImageFont

VITA = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FONT = os.path.join(VITA, 'fonts', 'Oswald.ttf')
SCE_SYS = os.path.join(VITA, 'sce_sys')

# No version here: an update made from the game replaces its files but not sce_sys, so it
# would go stale (the boot screen shows the running version).
CREDITS = [
    "Conker's Bad Fur Day for PS Vita  -  native port by HenryKun55, made with love",
    'Based on CBFD-Recompiled (N64Recomp). Conker (c) Rare / Microsoft. Not affiliated with them or Sony.',
    'Needs your own copy of the game (US N64 ROM).',
]


def fit(img, size, background=(0, 0, 0)):
    """img scaled to fit size (aspect kept), centred on background."""
    w, h = size
    s = min(w / img.width, h / img.height)
    scaled = img.resize((round(img.width * s), round(img.height * s)), Image.LANCZOS)
    out = Image.new('RGB', size, background)
    out.paste(scaled, ((w - scaled.width) // 2, (h - scaled.height) // 2))
    return out


def draw_credits(img):
    """The credit lines, centred at the bottom over a band that darkens from above."""
    font = ImageFont.truetype(FONT, 15)
    font.set_variation_by_name('Regular')
    img = img.convert('RGBA')
    w, h = img.size
    line, top = 20, h - 20 * len(CREDITS) - 8
    band = Image.new('L', (w, h), 0)
    bd = ImageDraw.Draw(band)
    for y in range(top - 24, h):
        bd.line([(0, y), (w, y)], fill=min(190, max(0, (y - (top - 24)) * 190 // 24)))
    img.paste(Image.new('RGBA', (w, h), (0, 0, 0, 255)), (0, 0), band)
    d = ImageDraw.Draw(img)
    for i, text in enumerate(CREDITS):
        tw = d.textlength(text, font=font)
        x, y = (w - tw) / 2, top + i * line
        d.text((x + 1, y + 1), text, font=font, fill=(0, 0, 0, 255))
        d.text((x, y), text, font=font, fill=(255, 190, 90, 255) if i == 0 else (225, 225, 225, 255))
    return img.convert('RGB')


def save_png8(img, path):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    img.quantize(colors=256, method=Image.MEDIANCUT, dither=Image.FLOYDSTEINBERG).save(path, optimize=True)
    print('wrote %s (%dx%d)' % (path, img.width, img.height))


def main():
    poster = Image.open(os.path.join(VITA, 'art', 'poster.jpg')).convert('RGB')
    logo = Image.open(os.path.join(VITA, 'art', 'logo.jpg')).convert('RGB')
    # The poster's art (everything else is black), with a little margin.
    art = poster.crop((0, 270, 1000, 1170))

    save_png8(fit(art, (960, 520)).crop((0, -12, 960, 532)), os.path.join(SCE_SYS, 'pic0.png'))
    bg = Image.new('RGB', (840, 500))
    bg.paste(fit(art, (840, 420)), (0, 4))
    save_png8(draw_credits(bg), os.path.join(SCE_SYS, 'livearea', 'contents', 'bg.png'))
    save_png8(fit(logo.crop((0, 0, 320, 173)), (280, 158)), os.path.join(SCE_SYS, 'livearea', 'contents', 'startup.png'))
    # Icon: Conker with his pint, from the poster's lower left.
    save_png8(poster.crop((70, 700, 410, 1040)).resize((128, 128), Image.LANCZOS), os.path.join(SCE_SYS, 'icon0.png'))


if __name__ == '__main__':
    main()
