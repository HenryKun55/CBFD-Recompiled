#!/usr/bin/env python3
"""
Checks that every translated speech-bubble page fits its bubble, with the game's own sizing
(reversed from the US ROM, addresses below) and what host/src/text_translation.cpp does to a
page before the game sees it (encoding, swear symbols, wrapping):

  python3 vita/tools/check_bubbles.py [--lang pt_br,es,...] [--english REF] [--runtime new|old]
                                      [--rom conker/baserom.us.z64] [--cxx [COMPILER]] [-v]

For each language (vita/translation/<lang>.txt, and the hint-book pages of <lang>_ui.txt),
in both censorship settings, each page is encoded and wrapped as the runtime does, measured
as func_150428D4 measures it, and its bubble sized as func_1516A7B0 and func_1516B6BC size it.
A page fails when:
  - a line is wider than the bubble's text width (the bubble would leave the 4:3 view),
  - the text is taller than the tallest English page of its kind (the bubble would grow
    further from the speaker than the game ever does),
  - a line is longer than func_1516C934's line buffer (83 bytes; more overwrites its stack),
  - a byte has no glyph (func_15042C40 returns it as is and the metrics are read past the
    font's 95 glyphs: garbage width and height).
The English reference (ROM-derived, not committed) is checked too when given, for
reference only: it doesn't count for the exit code. Exit code 1 if any translated page fails.

--runtime old models the runtime before the bubble fix (wrap at 250 "pixels" of glyph width
+ 1, a symbol a letter), to compare.

THE MODEL (US ROM; game segment addresses, as in RecompiledFuncs/ and conker/conker/asm):

Measuring a text, func_150428D4(text, &w, &h, &spacing):
  per byte: 0xBC skips itself and the next byte; otherwise g = func_15042C40(byte):
    a..z made capitals, ' ' -> 0x60, else its index in the character table D_80085930
    (95 bytes), else the byte itself.
  g == 0x60 (space): w += 4, line height at least 12.
  0xA1 <= g < 0xA8 (colours, pulsing): nothing.
  0xA8 <= g < 0x100 (button icons, swearing symbols): func_150415E0 gives the icon's width,
    height, baseline and scale: w = (int)(w + iw * scale), line height at least
    (int)((int)(ih * scale) - baseline) + 1.
  byte == '\\n': the widest line is kept, w = 0, height += max(line height, 12).
  else a glyph: metrics D_80085994[font 0] + g*4 = (width, height, x offset, y offset):
    w += width + xoff - 1, line height at least height + yoff (0x15042B14..0x15042B64).
  end: w = max(w, widest line); h += last line's height (no 12 minimum: a last line of
  capitals is 11 tall); an empty text is 12 tall. Both times D_800380A0/A4 = 292/292 and
  216/216 = 1.0 (func_100039C0).
  The glyph metrics are the font's records in the ROM at 0x40F10..0x42450 (D_80082F80),
  each (width - 1, height - 1, xoff, yoff, next offset, RLE pixels), read by func_15015A38.
  func_150417AC draws with the same advance (xoff, then width - 1; a space 4).

The bubble, func_1516A7B0 (creating it, 0x1516A90C..0x1516A9FC):
  every page of the message is measured (through func_1516C878, which the runtime hooks:
  the translated pages are what's measured) and the widest and tallest kept:
    W = (max w + pad / 2) * 1.15 (D_800A6CD0), H = (max h + pad) * 1.04 (D_800A6CD4),
    pad = 25 if the message's flags & 2 (the D_8009056C bubble), else 18.
  So the bubble grows with its text: there's no fixed size per bubble kind, no clipping and
  no maximum in the game itself.
func_1516AA70 (opening, state 2): the shown page is measured again and its half size kept
  (+0x30, +0x34): the text is centred in the bubble.
func_1516B6BC (drawing): the body is the 64x64 sprite D_8009055C (D_8009056C if flags & 2)
  scaled to sx = (int)((2W + 1) / 64 * 2355.2 * open) (D_800A6D5C = 2048 * 1.15),
  sy = (int)((H + 1) / 64 * 4259.84 * open) (D_800A6D60 = 4096 * 1.04), open (+0x28) going
  0 -> 1; func_15095B08 lays it out 64 * sx * cam / 4096 wide, cam (+0x14 of the camera,
  set by func_1501A8C0) = view height / frame height = 214 / 216 for the full-screen camera.
  Unless flags & 4 a shadow is drawn 5 pixels right of it (0x1516BB0C..0x1516BB44).
  Then func_1516C934 draws the text: line by line into an 84-byte buffer at $sp + 0xC8
  ($sp + 0x11C holds its saved list pointer): 83 bytes a line at most.
The view: the full-screen camera's sprite bounds are 2..290 (+0x2C, +0x30), and
  host/src/widescreen.cpp moves a bubble inside them, 4 pixels in (it centres one wider than
  that, which leaves both edges out). So a bubble fits when 64 * sx * cam / 4096 + 5 <= 280.
  The message's flags aren't in the translation files: the check (and the runtime, so the
  two agree) takes the larger pad, 25. That gives the text width BUBBLE_TEXT_PX below,
  which host/src/text_translation.cpp wraps at (its bubble_text_px; checked here).
Height: nothing in the game limits it either; the bubble is put beside the speaker's head
  (+0x40, +0x44) and grows away from it, so a taller one reaches further up the screen. The
  limit is the tallest English page of the kind (dialogue: 5 lines, 60 px; the hint book:
  9 lines, 108 px): MAX_TEXT_H.
Censored swears: the runtime writes one symbol a letter, at most SWEAR_SYMBOLS (7) a word
  (the English's own runs are 4 to 7 symbols; a symbol is 12 px, wider than a letter).

The runtime (and this model of it): each line that doesn't fit (wider than BUBBLE_TEXT_PX or
  longer than 83 bytes) is broken at spaces; a page still taller than its MAX_TEXT_H is flowed
  again as one paragraph, kept if that's shorter. Pages can't be added (a message's page
  count is the game's: the bank descriptors' +8, or 0xBD breaks in a script's own string),
  so a page that still doesn't fit is the translation's to shorten: that's what fails here.
--cxx builds host/src/text_translation.cpp itself on the host (check_bubbles_harness.cpp) and
  checks it writes exactly the pages this model does.
"""
import argparse
import os
import re
import struct
import sys
import zlib

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
TRANSLATION = os.path.join(ROOT, "vita", "translation")
RUNTIME = os.path.join(ROOT, "host", "src", "text_translation.cpp")
DEFAULT_ROM = os.path.join(ROOT, "conker", "baserom.us.z64")
DEFAULT_ENGLISH = os.path.join(TRANSLATION, "en_reference.txt")
LANGUAGES = {"pt_br": 1, "es": 2, "fr": 3, "de": 4, "it": 5}


def f32(x):
    return struct.unpack("<f", struct.pack("<f", x))[0]


# ---------------------------------------------------------------- the font (font 0)

# D_80085930: the glyph for each character code.
FONT_CHARS = [
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46,
    0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56,
    0x57, 0x58, 0x59, 0x5A, 0x26, 0x5C, 0x5E, 0x3A, 0x2C, 0x24, 0x22, 0x3D, 0x21, 0x2E, 0x3E, 0x23,
    0x7B, 0x28, 0x5B, 0x3C, 0x2D, 0x25, 0x2B, 0x3F, 0x7D, 0x29, 0x5D, 0x3B, 0x2F, 0x7E, 0x27, 0xC4,
    0xE4, 0xD6, 0xF6, 0xDC, 0xFC, 0xDF, 0xC0, 0xE0, 0xC2, 0xE2, 0xC7, 0xE7, 0xC9, 0xE9, 0xC8, 0xEB,
    0xCA, 0xEA, 0xCB, 0xEA, 0xCE, 0xEE, 0xCF, 0xEF, 0xD4, 0xF4, 0xDB, 0xF4, 0xD9, 0xFA, 0x40,
]
# D_80085994[0]: (width, height, x offset, y offset) per glyph, as func_15015A38 decodes the
# ROM's records at 0x40F10 (checked against the ROM with --rom).
FONT_METRICS = [
    (8, 11, 0, 0), (6, 10, 0, 0), (7, 10, 0, 0), (7, 11, 0, 0), (8, 11, 0, 0), (7, 11, 0, 0),
    (8, 11, 0, 0), (9, 11, 0, 0), (8, 11, 0, 0), (8, 11, 0, 0), (10, 10, 0, 1), (9, 11, 0, 0),
    (9, 11, 0, 0), (10, 10, 0, 1), (7, 11, 0, 0), (8, 11, 0, 0), (12, 11, 0, 0), (9, 11, 0, 0),
    (4, 10, 0, 1), (9, 10, 0, 1), (8, 10, 0, 1), (8, 10, 0, 1), (11, 11, 0, 0), (9, 10, 0, 1),
    (10, 10, 0, 1), (9, 10, 0, 1), (10, 10, 0, 1), (8, 10, 0, 1), (9, 10, 0, 1), (8, 11, 0, 0),
    (9, 10, 0, 1), (9, 10, 0, 1), (12, 10, 0, 1), (9, 10, 0, 1), (8, 10, 0, 1), (10, 10, 0, 1),
    (8, 10, 0, 1), (4, 11, 0, 1), (7, 5, 0, 1), (4, 7, 0, 2), (4, 5, 0, 7), (6, 11, 0, 1),
    (4, 5, 0, 1), (6, 6, 0, 3), (3, 9, 0, 1), (3, 3, 1, 6), (6, 8, 0, 3), (7, 8, 0, 1),
    (5, 11, 0, 0), (4, 12, 0, 0), (4, 11, 0, 0), (6, 6, 0, 3), (5, 3, 0, 4), (10, 10, 0, 2),
    (7, 6, 0, 2), (7, 11, 0, 0), (5, 11, 0, 0), (4, 11, 0, 0), (10, 10, 0, 1), (4, 9, 0, 2),
    (5, 10, 0, 0), (6, 4, 0, 1), (3, 5, 2, 1), (8, 11, 0, 0), (8, 11, 0, 0), (9, 12, 0, 0),
    (9, 12, 0, 0), (8, 13, 0, 0), (8, 13, 0, 0), (9, 11, 0, 0), (8, 12, 0, 0), (8, 12, 0, 0),
    (8, 12, 0, 0), (8, 12, 0, 0), (8, 13, 0, 0), (8, 13, 0, 0), (7, 12, 0, 0), (7, 12, 0, 0),
    (7, 12, 0, 0), (7, 12, 0, 0), (8, 13, 0, 0), (8, 13, 0, 0), (8, 13, 0, 0), (8, 13, 0, 0),
    (6, 12, 0, 0), (6, 12, 0, 0), (8, 13, 0, 0), (8, 13, 0, 0), (8, 12, 0, 0), (8, 12, 0, 0),
    (8, 12, 0, 0), (8, 12, 0, 0), (8, 12, 0, 0), (8, 12, 0, 0), (10, 10, 0, 1),
]
FONT_ROM_START, FONT_ROM_END = 0x40F10, 0x42450


def rom_metrics(path):
    d = open(path, "rb").read()[FONT_ROM_START:FONT_ROM_END]
    out, p = [], 0
    while len(out) < 95:
        out.append((d[p] + 1, d[p + 1] + 1, d[p + 2], d[p + 3]))
        p += struct.unpack(">I", d[p + 4:p + 8])[0]
    return out


# conker_font_patch's letters (slot, code, base glyph, how): the slot gets the base's metrics
# (a squashed one is 12 high from line 0).
G_N, G_BANG, G_QUESTION, G_A_GRAVE, G_A_CIRC, G_I_CIRC, G_O_CIRC, G_U_CIRC = 23, 44, 55, 70, 72, 84, 88, 90
FONT_PATCHES = {
    1: [(63, 0xC1, G_A_GRAVE, "accent"), (64, 0xC3, G_A_CIRC, "accent"), (65, 0xCD, G_I_CIRC, "accent"),
        (66, 0xD3, G_O_CIRC, "accent"), (69, 0xD5, G_O_CIRC, "accent"), (86, 0xDA, G_U_CIRC, "accent")],
    2: [(63, 0xC1, G_A_GRAVE, "accent"), (64, 0xD1, G_N, "squash"), (65, 0xCD, G_I_CIRC, "accent"),
        (66, 0xD3, G_O_CIRC, "accent"), (69, 0x82, G_QUESTION, "rotate"), (86, 0xDA, G_U_CIRC, "accent"),
        (87, 0x81, G_BANG, "rotate")],
    5: [(69, 0xCC, G_I_CIRC, "accent"), (86, 0xD2, G_O_CIRC, "accent")],
}


class Font:
    def __init__(self, language, metrics):
        self.chars = list(FONT_CHARS)
        self.metrics = list(metrics)
        for slot, code, base, how in FONT_PATCHES.get(language, []):
            w, h, xo, yo = metrics[base]
            if how == "squash":
                h, yo = 12, 0
            self.chars[slot] = code
            self.metrics[slot] = (w, h, xo, yo)

    def glyph(self, c):
        """func_15042C40."""
        u = c - 0x20 if 0x61 <= c <= 0x7A else c
        if c == 0x20:
            return 0x60
        for i, x in enumerate(self.chars):
            if x == u:
                return i
        return c


# func_150415E0: (width, height, baseline, scale) of a button icon / symbol (0xA8..0xFF).
def icon(c):
    if c in (0xA8, 0xA9):
        return 32, 18, 3.1, 1.0
    if c in (0xAA, 0xAB, 0xAC, 0xAD):
        return 32, 27, 2.0, 0.603
    if c == 0xAE:
        return 16, 17, -1.6, 1.0
    if c in (0xAF, 0xB0):
        return 46, 16, 2.0, 1.0
    if c in (0xB6, 0xB7, 0xB8, 0xB9):
        return 16, 12, 2.0, 1.0
    if c == 0xBA:
        return 55, 12, 0.2, 1.0
    if c == 0xB1:
        return 38, 24, 2.0, 0.726
    return 12, 16, 2.0, 1.0


class NoGlyph(Exception):
    pass


def measure(font, b):
    """func_150428D4: (width, height) of a text (bytes)."""
    w = h = widest = line_h = 0
    if not b:
        h += 12
    i = 0
    while i < len(b):
        c = b[i]
        if c == 0xBC:
            i += 2
            continue
        g = font.glyph(c)
        if g == 0x60:
            w += 4
            line_h = max(line_h, 12)
        elif 0xA1 <= g < 0xA8:
            pass
        elif g >= 0xA8:
            iw, ih, base, scale = icon(g)
            w = int(f32(f32(w) + f32(f32(iw) * f32(scale))))
            line_h = max(line_h, int(f32(f32(int(f32(f32(ih) * f32(scale)))) - f32(base))) + 1)
        elif c == 0x0A:
            widest = max(widest, w)
            w = 0
            h += max(line_h, 12)
            line_h = 0
        else:
            if g >= 95:
                raise NoGlyph("byte %02X has no glyph" % c)
            gw, gh, xo, yo = font.metrics[g]
            w += gw + xo - 1
            line_h = max(line_h, gh + yo)
        i += 1
    return max(w, widest), h + line_h


# ---------------------------------------------------------------- the bubble

PAD_SMALL, PAD_LARGE = 18.0, 25.0     # func_1516A7B0: flags & 2 ? 25 : 18
CAMERA_SCALE = f32(214.0 / 216.0)      # the full-screen camera's +0x14 (func_1501A8C0)
VIEW_PX = 280                          # 2..290, 4 pixels in each side (widescreen.cpp)
SHADOW_PX = 5                          # the shadow, 5 pixels right
LINE_BYTES = 83                        # func_1516C934's line buffer, less its NUL
MAX_TEXT_H = {"dialogue": 60, "hint": 108}  # the tallest English page of each kind


def bubble(tw, th, pad=PAD_LARGE, open_=1.0):
    """func_1516A7B0 + func_1516B6BC + func_15095B08: the body's size on screen."""
    W = f32(f32(tw + f32(pad * 0.5)) * f32(1.15))
    H = f32(f32(th + pad) * f32(1.04))
    sx = int(f32(f32(f32(f32(W + W) + 1.0) / 64.0) * f32(2355.2)) * open_)
    sy = int(f32(f32(f32(H + 1.0) / 64.0) * f32(4259.84)) * open_)
    if sx > 32767 or sy > 32767:
        raise OverflowError("sprite scale past s16")
    bw = f32(64.0 * f32(f32(sx) * CAMERA_SCALE) / 4096.0)
    bh = f32(64.0 * f32(f32(sy) * CAMERA_SCALE) / 4096.0)
    return bw, bh


def max_text_width():
    """The widest text whose bubble (pad 25, with its shadow) fits the 4:3 view."""
    tw = 0
    while bubble(tw + 1, 12)[0] + SHADOW_PX <= VIEW_PX:
        tw += 1
    return tw


BUBBLE_TEXT_PX = max_text_width()


# ---------------------------------------------------------------- the runtime (text_translation.cpp)

def font_has(language, code):
    if code in (0xC0, 0xC2, 0xC7, 0xC9, 0xC8, 0xCA, 0xCB, 0xCE, 0xD4, 0xDB, 0xD9, 0xDC):
        return True
    if code in (0xC4, 0xD6, 0xDF, 0xCF):
        return language != 1 and language != 2 and not (language == 5 and code in (0xDF, 0xCF))
    if code in (0xC1, 0xCD, 0xD3, 0xDA):
        return language in (1, 2)
    if code in (0xC3, 0xD5):
        return language == 1
    if code in (0xD1, 0x81, 0x82):
        return language == 2
    if code in (0xCC, 0xD2):
        return language == 5
    return False


def put_char(out, cp, language):
    if 0xE0 <= cp <= 0xFE and cp != 0xF7 and cp != 0xDF:
        cp -= 0x20
    if cp == 0xA1:
        cp = 0x81
    if cp == 0xBF:
        cp = 0x82
    if cp in (0x152, 0x153):
        out += b"oe"
        return
    if cp == 0xC6:
        out += b"ae"
        return
    if cp >= 0x80:
        if font_has(language, cp):
            out.append(cp)
            return
        base = "AAAAAAACEEEEIIIIDNOOOOOxOUUUUYTs"
        if 0xC0 <= cp <= 0xDF:
            ch = base[cp - 0xC0]
            out.append(ord(ch) + (32 if "A" <= ch <= "Z" else 0))
            return
        out.append(ord("!") if cp == 0x81 else ord("?"))
        return
    if ord("A") <= cp <= ord("Z"):
        cp += 32
    out.append(cp)


SWEAR_SYMBOLS = 7  # at most, a word (the English's runs are 4 to 7)


def put_symbols(out, word, seed):
    colour = 0xA2 + seed % 4
    out.append(0xA6)
    n = in_word = 0
    raw = word.encode("utf-8")
    i = 0
    while i < len(raw):
        c = raw[i]
        if c == 0x20:
            out.append(0x20)
            in_word = 0
        elif c == 0x5C and i + 1 < len(raw) and raw[i + 1] == ord("n"):
            out.append(0x0A)
            in_word = 0
            i += 1
        elif c >= 0x80 and (c & 0xC0) == 0x80:
            pass
        elif in_word < SWEAR_SYMBOLS:
            out.append(colour)
            out.append(0xB2 + (seed + n * 3) % 4)
            n += 1
            in_word += 1
        i += 1
    out.append(0xA1)


def encode(text, censored, key, language):
    out = bytearray()
    raw = text.encode("utf-8")
    i = 0
    while i < len(raw):
        c = raw[i]
        if c == 0x5C and raw[i + 1:i + 2] == b"n":
            out.append(0x0A)
            i += 2
            continue
        if c == 0x3C and re.match(rb"<[0-9A-Fa-f]{2}>", raw[i:i + 4]):
            out.append(int(raw[i + 1:i + 3], 16))
            i += 4
            continue
        if c == 0x7B:
            end = raw.find(b"}", i)
            if end >= 0:
                word = raw[i + 1:end].decode("utf-8")
                if censored:
                    put_symbols(out, word, key)
                else:
                    out += encode(word, False, key, language)
                i = end + 1
                continue
        cp, extra = c, 0
        if c >= 0xF0:
            cp, extra = c & 0x07, 3
        elif c >= 0xE0:
            cp, extra = c & 0x0F, 2
        elif c >= 0xC0:
            cp, extra = c & 0x1F, 1
        i += 1
        while extra > 0 and i < len(raw) and (raw[i] & 0xC0) == 0x80:
            cp = (cp << 6) | (raw[i] & 0x3F)
            i += 1
            extra -= 1
        put_char(out, cp, language)
    return bytes(out)


def capitalised(b):
    """A page the game wrote with a capital first gets its first letter as one."""
    b = bytearray(b)
    for i, u in enumerate(b):
        if 0x61 <= u <= 0x7A:
            b[i] = u - 32
            break
        if 0x41 <= u <= 0x5A or u >= 0xC0:
            break
    return bytes(b)


def fits(font, line, max_px):
    return len(line) <= LINE_BYTES and measure(font, line)[0] <= max_px


def wrap_new(font, text, max_px):
    """text_translation.cpp's wrap_to_width: a line that doesn't fit (wider than max_px by the
    game's measure, or longer than the line buffer) is broken at spaces, before the word that
    would cross; its leading spaces stay on its first part, the space at a break goes."""
    out = []
    for line in text.split(b"\n"):
        if fits(font, line, max_px):
            out.append(line)
            continue
        lead = len(line) - len(line.lstrip(b" "))
        cur = line[:lead]
        first = True
        for word in line[lead:].split(b" "):
            if not first and not fits(font, cur + b" " + word, max_px):
                out.append(cur)
                cur, first = b"", True
            cur = cur + word if first else cur + b" " + word
            first = False
        out.append(cur)
    return b"\n".join(out)


def wrap_old(font, text, max_px):
    """The runtime before the fix: glyph width + 1 per character, at 250."""
    def cw(c):
        if c == 0x20:
            return 4
        if 0xA1 <= c <= 0xA7:
            return 0
        if 0xA8 <= c < 0xC0:
            return 14
        if 0x61 <= c <= 0x7A:
            c -= 32
        for i, x in enumerate(font.chars):
            if x == c:
                return font.metrics[i][0] + 1
        return 8
    out = []
    for line in text.split(b"\n"):
        if sum(cw(c) for c in line) <= max_px:
            out.append(line)
            continue
        lead = len(line) - len(line.lstrip(b" "))
        cur, cur_px, first = line[:lead], lead * 4, True
        for word in line[lead:].split(b" "):
            wpx = sum(cw(c) for c in word)
            if not first and cur_px + 4 + wpx > max_px:
                out.append(cur)
                cur, cur_px, first = b"", 0, True
            if not first:
                cur += b" "
                cur_px += 4
            cur += word
            cur_px += wpx
            first = False
        out.append(cur)
    return b"\n".join(out)


def fit_page(font, text, max_px, max_h):
    """text_translation.cpp's fit_to_bubble: the lines wrapped (wrap_new); a page still taller
    than max_h is flowed again as one paragraph (its lines joined, their outer spaces and the
    empty ones dropped), kept if that makes it shorter."""
    page = wrap_new(font, text, max_px)
    h = measure(font, page)[1]
    if h <= max_h:
        return page
    joined = b" ".join(l.strip(b" ") for l in text.split(b"\n") if l.strip(b" "))
    flowed = wrap_new(font, joined, max_px)
    return flowed if measure(font, flowed)[1] < h else page


def runtime_page(font, language, text, censored, key, english_first, mode, kind):
    b = encode(text, censored, key, language)
    if english_first is not None and 0x41 <= english_first <= 0x5A:
        b = capitalised(b)
    if mode == "old":
        return wrap_old(font, b, 250)
    return fit_page(font, b, BUBBLE_TEXT_PX, MAX_TEXT_H[kind])


# ---------------------------------------------------------------- the files

def read_pages(path, kinds=False):
    """{key: (text, kind)}; in a _ui file only the hint book's pages (assets1A)."""
    pages = {}
    kind = "hint" if kinds else "dialogue"
    wanted = not kinds
    for line in open(path, encoding="utf-8"):
        line = line.rstrip("\n").rstrip("\r")
        if line.startswith("#"):
            if kinds and "assets1A" in line:
                wanted = True
            elif kinds and "assets1C" in line:
                wanted = False
            continue
        m = re.match(r"^([0-9a-fA-F]{8}) = (.*)$", line)
        if m and wanted:
            pages[int(m.group(1), 16)] = (m.group(2), kind)
    return pages


def english_bytes(text):
    out = bytearray()
    i = 0
    while i < len(text):
        if text.startswith("\\n", i):
            out.append(0x0A)
            i += 2
            continue
        m = re.match(r"<([0-9A-Fa-f]{2})>", text[i:i + 4])
        if m:
            out.append(int(m.group(1), 16))
            i += 4
            continue
        out += text[i].encode("latin-1", "replace")
        i += 1
    return bytes(out)


def check_page(font, b, kind):
    """(problems, info) of one page as the game gets it."""
    problems = []
    lines = b.split(b"\n")
    try:
        tw, th = measure(font, b)
    except NoGlyph as e:
        return [str(e)], None
    bw, bh = bubble(tw, th)
    for n, line in enumerate(lines):
        lw = measure(font, line)[0]
        if lw > BUBBLE_TEXT_PX:
            problems.append("line %d is %d px wide (max %d; its bubble %.0f px + %d shadow > %d)" %
                            (n + 1, lw, BUBBLE_TEXT_PX, bubble(lw, th)[0], SHADOW_PX, VIEW_PX))
        if len(line) > LINE_BYTES:
            problems.append("line %d is %d bytes (func_1516C934's buffer holds %d)" % (n + 1, len(line), LINE_BYTES))
    if th > MAX_TEXT_H[kind]:
        problems.append("%d lines, %d px tall (max %d for %s: bubble %.0f px)" %
                        (len(lines), th, MAX_TEXT_H[kind], kind, bh))
    return problems, (tw, th, len(lines), bw, bh)


def show(b):
    s = []
    for c in b:
        s.append("\\n" if c == 10 else chr(c) if 0x20 <= c < 0x7F else "<%02X>" % c)
    return "".join(s)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[1])
    ap.add_argument("--lang", default=",".join(LANGUAGES))
    ap.add_argument("--english", default=None, help="English reference (default en_reference.txt if present)")
    ap.add_argument("--runtime", choices=("new", "old"), default="new")
    ap.add_argument("--rom", default=None, help="check the font metrics against the US ROM")
    ap.add_argument("--cxx", nargs="?", const=os.environ.get("CXX", "c++"), default=None, metavar="COMPILER",
                    help="also build text_translation.cpp's fitting on the host (check_bubbles_harness.cpp) "
                         "and check it gives these very pages")
    ap.add_argument("-v", "--verbose", action="store_true")
    args = ap.parse_args()

    rom = args.rom or (DEFAULT_ROM if os.path.exists(DEFAULT_ROM) else None)
    if rom:
        if rom_metrics(rom) != FONT_METRICS:
            print("FAIL: the font metrics differ from the ROM's (%s)" % rom)
            return 1
    status = 0
    global SWEAR_SYMBOLS
    if args.runtime == "old":
        SWEAR_SYMBOLS = 1 << 30  # one symbol a letter
    else:
        # The runtime fits the pages to the limits this model gives: its constants must be these.
        source = open(RUNTIME, encoding="utf-8").read()
        for name, want in (("bubble_text_px", BUBBLE_TEXT_PX), ("bubble_text_h_dialogue", MAX_TEXT_H["dialogue"]),
                           ("bubble_text_h_hint", MAX_TEXT_H["hint"]), ("bubble_line_bytes", LINE_BYTES),
                           ("swear_symbols", SWEAR_SYMBOLS)):
            m = re.search(r"\b%s\s*=\s*(\d+)" % name, source)
            if not m or int(m.group(1)) != want:
                print("FAIL: text_translation.cpp's %s is %s, the model's %d" % (name, m.group(1) if m else "missing", want))
                status = 1
    print("model: text width <= %d px (bubble <= %d px with its shadow), text height <= %s, "
          "line <= %d bytes%s" % (BUBBLE_TEXT_PX, VIEW_PX, MAX_TEXT_H, LINE_BYTES,
                                  ", metrics checked against the ROM" if rom else ""))

    cxx_jobs = []
    english = {}
    eng_path = args.english or (DEFAULT_ENGLISH if os.path.exists(DEFAULT_ENGLISH) else None)
    if eng_path:
        english.update(read_pages(eng_path))
        ui = eng_path.replace(".txt", "_ui.txt")
        if os.path.exists(ui):
            english.update(read_pages(ui, kinds=True))
        font = Font(0, FONT_METRICS)
        bad = 0
        for key, (text, kind) in sorted(english.items()):
            problems, _ = check_page(font, english_bytes(text), kind)
            if problems:
                bad += 1
                if args.verbose:
                    print("  en %08x: %s | %s" % (key, "; ".join(problems), text))
        print("english (reference, the ROM's text as is): %d/%d pages past the limits" % (bad, len(english)))

    for name in args.lang.split(","):
        language = LANGUAGES[name]
        font = Font(language, FONT_METRICS)
        pages = read_pages(os.path.join(TRANSLATION, name + ".txt"))
        ui = os.path.join(TRANSLATION, name + "_ui.txt")
        if os.path.exists(ui):
            pages.update(read_pages(ui, kinds=True))
        failed = {}
        reasons = {}
        for key, (text, kind) in sorted(pages.items()):
            first = None
            if key in english:
                eb = english_bytes(english[key][0])
                first = eb[0] if eb else None
            for censored in (False, True):
                try:
                    b = runtime_page(font, language, text, censored, key, first, args.runtime, kind)
                except NoGlyph as e:
                    b = encode(text, censored, key, language)
                problems, info = check_page(font, b, kind)
                capital = first is not None and 0x41 <= first <= 0x5A
                cxx_jobs.append(("%d %d %08x %d %d %s" % (language, censored, key, capital, kind == "hint", text), b,
                                 "%s %08x %s" % (name, key, "censored" if censored else "uncensored")))
                if problems:
                    failed.setdefault(key, []).append((censored, problems, b))
                    for p in problems:
                        r = re.sub(r"\d+", "N", p.split(" (")[0])
                        reasons[r] = reasons.get(r, 0) + 1
        print("%-6s %4d pages, %3d don't fit%s" % (name, len(pages), len(failed),
              "" if not reasons else ": " + ", ".join("%s x%d" % (r, n) for r, n in sorted(reasons.items()))))
        for key, fails in sorted(failed.items()):
            for censored, problems, b in fails:
                print("  %s %08x %s: %s" % (name, key, "censored" if censored else "uncensored", "; ".join(problems)))
                if args.verbose:
                    print("      %s" % show(b))
        if failed:
            status = 1
    if args.cxx and args.runtime == "new":
        status |= check_cxx(args.cxx, cxx_jobs)
    return status


def check_cxx(compiler, jobs):
    """Builds check_bubbles_harness.cpp with a copy of text_translation.cpp and compares its pages."""
    import subprocess
    import tempfile
    here = os.path.dirname(os.path.abspath(__file__))
    with tempfile.TemporaryDirectory() as tmp:
        open(os.path.join(tmp, "text_translation.cpp"), "w").write(open(RUNTIME, encoding="utf-8").read())
        open(os.path.join(tmp, "conker.hpp"), "w").write(
            "#pragma once\nnamespace conker { int text_language(); bool text_censored(); }\n")
        harness = os.path.join(tmp, "harness.cpp")
        open(harness, "w").write(open(os.path.join(here, "check_bubbles_harness.cpp"), encoding="utf-8").read())
        exe = os.path.join(tmp, "harness")
        cmd = [compiler, "-std=c++20", "-O1", "-D__vita__", "-I", tmp,
               "-I", os.path.join(ROOT, "tools", "N64Recomp", "include"), harness, "-o", exe]
        r = subprocess.run(cmd, capture_output=True, text=True)
        if r.returncode:
            print("FAIL: building the harness:\n" + r.stderr[-3000:])
            return 1
        chars = "".join("%02x" % c for c in FONT_CHARS)
        metrics = "".join("%02x%02x%02x%02x" % m for m in FONT_METRICS)
        r = subprocess.run([exe, chars, metrics], input="\n".join(j[0] for j in jobs) + "\n",
                           capture_output=True, text=True, encoding="utf-8")
        if r.returncode:
            print("FAIL: the harness exited with %d" % r.returncode)
            return 1
        got = r.stdout.split("\n")
        bad = 0
        for (line, want, what), out in zip(jobs, got):
            if bytes.fromhex(out) != want:
                bad += 1
                if bad <= 10:
                    print("  c++ differs, %s:\n      c++    %s\n      python %s" % (what, show(bytes.fromhex(out)), show(want)))
        print("c++ (text_translation.cpp on the host): %d/%d pages as modelled" % (len(jobs) - bad, len(jobs)))
        return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
