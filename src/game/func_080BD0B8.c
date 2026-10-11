#include "types.h"

struct Scroll { s32 x, y; };
extern u16 D_0300004C;
extern struct Scroll D_03000060;
extern u8 D_08025174[];
extern u32 D_0873F9D4[];
extern u32 D_0200C524[];
extern u32 D_0200C5A4[];
void func_08079EF4(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_080C8B78(void *, void *, u32);
void func_08079544(s32, s32);
void func_0807970C(void);
void func_0807AA34(s32);
void func_0807ABEC(u32, u8, u16 *);
void func_080C8FCC(s32);

void func_080BD0B8(void)
{
    u16 tiles[2];
    u32 fill;
    s32 end;
    s32 style;
    struct Scroll *scroll;
    /* Empty asm preserves agbcc register copies without adding instructions. */
    register s32 y asm("r1");
    s32 row;
    u16 *dest;
    u8 i;
    u8 *text;
    register s32 initial asm("r3");
    u8 token;
    register u32 mask asm("r9");
    u32 blank;
    register u32 code asm("r1");
    u8 next;
    u16 *out;
    register u32 maskValue asm("r2");
    register u8 *initialText asm("r4");
    register struct Scroll *readScroll asm("r0");
    register s32 nextChar asm("r1");
    register s32 endingToken asm("r0");
    u8 nextByte;
    register u8 *stylePtr asm("r2");
    register u32 styleValue asm("r2");
    register u8 *glyphPtr asm("r1");
    register u32 advance asm("r2");
    register u32 glyph asm("r0");
    register u32 lowByte asm("r1");

    D_0300004C = 0x1140;
    func_08079EF4(0, 1, 0, 0x3C0, 0x3C0, 0, 0xE, 0, 0x3E6, 0xF);
    func_080C8B78(D_0873F9D4, (void *)0x050001C0, 8);
    fill = 0xE3C1E3C1;
    func_080C8B78(&fill, (void *)0x06000000, 0x01000200);
    func_08079544(1, 0x3C);
    func_0807970C();
    D_03000060.y = 0;
    D_03000060.x = 0;
    end = -1;
    text = D_08025174;
    style = 0;
    scroll = &D_03000060;
loop:
    y = scroll->y;
    row = y - 0x1000;
    if (row < 0)
        row = y - 0x801;
    dest = (u16 *)(0x06000000 + (((row >> 11) & 31) << 6));
    i = 0;
    blank = 0xE3C1;
    maskValue = 0x3FF;
    asm("" : "+r"(maskValue));
    mask = maskValue;
    do {
        code = *dest;
        if (code != blank) {
            func_0807AA34(mask & code);
            code = dest[32];
            func_0807AA34(mask & code);
            *dest = blank;
            dest[32] = blank;
        }
        dest++;
        i++;
    } while (i <= 31);
    initialText = text;
    asm("" : "+r"(initialText));
    next = *initialText;
    initial = next;
    token = next;
    if (initial != 0) {
        readScroll = scroll;
        asm("" : "+r"(readScroll));
        y = readScroll->y;
        if (!(y & 0xFFF)) {
            row = y + 0xA000;
            if (row < 0)
                row = y + 0xA7FF;
            dest = (u16 *)(0x06000000 + (((row >> 11) & 31) << 6));
            if (initial != 10) {
                out = tiles;
character:
                if (token == 1) {
                    stylePtr = text;
                    asm("" : "+r"(stylePtr));
                    styleValue = stylePtr[1];
                    asm("" :: "r"(styleValue));
                    style = styleValue;
                    text += 2;
                }
                glyphPtr = text;
                asm("" : "+r"(glyphPtr));
                glyph = glyphPtr[0] << 8;
                asm("" :: "r"(glyph));
                lowByte = glyphPtr[1];
                asm("" :: "r"(lowByte));
                glyph |= lowByte;
                func_0807ABEC(glyph, style, tiles);
                dest[0] = out[0];
                dest[32] = out[1];
                advance = 2;
                asm("" : "+r"(advance));
                text += advance;
                dest++;
                nextByte = *text;
                nextChar = nextByte;
                if (nextChar != 0) {
                    token = nextByte;
                    if (nextChar == 10)
                        goto newline;
                    goto character;
                }
                goto finish;
            }
newline:
            endingToken = token;
            if (endingToken == 0) {
finish:
                end = scroll->y + 0xB000;
            } else if (endingToken == 10) {
                text++;
            }
            i = 0;
            do {
                D_0200C524[i] ^= D_0200C5A4[i];
                D_0200C5A4[i] = 0;
                i++;
            } while (i <= 31);
        }
    }
    scroll->y += 0x80;
    func_080C8FCC(1);
    if (scroll->y != end)
        goto loop;
    func_08079544(2, 8);
    func_0807970C();
}
