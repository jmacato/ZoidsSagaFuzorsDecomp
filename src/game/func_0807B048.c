#include "types.h"

struct Win
{
    u32 flags;
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    s16 cursorX;
    s16 cursorY;
    u16 lines;
    u8 font;
    u8 id;
    u8 pad14[0xC];
    u16 tiles[0x258];
};

extern u32 D_0201F5C4;
extern u16 D_0201F5C8;
extern u8 D_0201F5CA;
extern u8 D_0201F5CB;
extern u16 D_0201F5CC;
extern u16 D_0201F5CE;
extern u32 D_0201F5D0;
extern u16 D_0300000C;
extern u16 D_0300000E;
extern u8 D_03000081;
extern u8 D_02030586[];
extern const u8 *D_0200C4AC[];
extern u8 D_0200C4BC[];
extern u8 D_0200C4C0[];
extern u8 D_0200C4C4[];
extern u16 D_0200C4C8[];
extern u8 D_0200C4D0[];
extern u8 D_0200C4D4[];
extern u8 D_0200C4D8[];
extern u8 D_0200C4DC[];
extern u8 D_0200C4E0[][2];
extern void *D_0200C4EC[];
extern const u8 *const D_087A43E0[];
extern const u8 *const D_087A486C[];
extern const u8 *const D_087A4890[];
extern const u8 *const D_087A554C[];
extern const u8 *const D_087A559C[];
extern const u8 *const D_087A58C4[];
extern const u8 *const D_087A5AE4[];
extern const u8 *const D_087A5CA4[][26];
extern const u8 D_080C9470[];
extern const u8 D_080C9498[];

void func_0807BA8C(const u8 *, u8, u8, u8, u8);
const u8 *func_08082E70(u8);
u8 func_0807AAE0(u16);
void func_0807ABEC(u16, u8, u16 *);
void func_0807ADC4(u8, u8, u16 *);
void func_0807AF84(u8, u8, u16 *);
void func_0807AA34(u16);
void func_0807A1A4(void);
void func_080C8FCC(u32);
void *func_080771BC(const void *, const void *, u16, s16, s16, u16, u16, u32, u32);
void func_080771F4(void *);
void func_08075F20(u16);

const u8 *func_0807B048(struct Win *win, const u8 *s)
{
    u8 lineH;
    s32 c;
    u16 *tile;
    u16 glyph[2];
    u16 t;
    u32 k;
    s32 start, row, col;

    lineH = 1;
    while ((c = *s) != 0)
    {
        if ((u8)c < 0x20)
        {
            switch (*s)
            {
            case 1:
                win->font = s[1];
                s += 2;
                continue;
            case 2:
                win->cursorX = s[1];
                win->cursorY = s[2];
                s += 3;
                lineH = 1;
                continue;
            case 3:
                func_0807B048(win, D_02030586);
                s += 1;
                lineH = 2;
                break;
            case 4:
                switch (s[1])
                {
                case 8:
                    func_0807BA8C(D_0200C4AC[s[3]], s[2], win->font, 20, win->id);
                    lineH = 1;
                    break;
                case 16:
                    func_0807BA8C(D_0200C4AC[s[3]], s[2], win->font, 4, win->id);
                    lineH = 2;
                    break;
                }
                s += 4;
                break;
            case 5:
                switch (s[1])
                {
                case 8:
                    func_0807BA8C(D_0200C4AC[s[3]], s[2], win->font, 16, win->id);
                    lineH = 1;
                    break;
                case 16:
                    func_0807BA8C(D_0200C4AC[s[3]], s[2], win->font, 0, win->id);
                    lineH = 2;
                    break;
                }
                s += 4;
                break;
            case 6:
                func_0807B048(win, D_087A43E0[D_0200C4BC[s[1]]]);
                s += 2;
                lineH = 2;
                break;
            case 7:
                func_0807B048(win, func_08082E70(D_0200C4C0[s[1]]));
                s += 2;
                lineH = 2;
                break;
            case 8:
                func_0807B048(win, D_087A486C[D_0200C4C4[s[1]]]);
                s += 2;
                lineH = 2;
                break;
            case 9:
                func_0807B048(win, D_087A4890[D_0200C4C8[s[1]]]);
                s += 2;
                lineH = 2;
                break;
            case 10:
                win->cursorX = 0;
                win->cursorY += 2;
                win->lines += 2;
                s += 1;
                continue;
            case 11:
                func_0807B048(win, D_087A554C[D_0200C4D0[s[1]]]);
                s += 2;
                lineH = 2;
                break;
            case 12:
                func_0807B048(win, D_087A559C[D_0200C4D4[s[1]]]);
                s += 2;
                lineH = 2;
                break;
            case 13:
                func_0807B048(win, D_087A58C4[D_0200C4D8[s[1]]]);
                s += 2;
                lineH = 2;
                break;
            case 14:
                func_0807B048(win, D_087A5AE4[D_0200C4DC[s[1]]]);
                s += 2;
                lineH = 2;
                break;
            case 15:
                func_0807B048(win, D_087A5CA4[D_0200C4E0[s[1]][0]][D_0200C4E0[s[1]][1]]);
                s += 2;
                lineH = 2;
                break;
            }
        }
        else
        {
            tile = &win->tiles[win->cursorX + 1 + (win->cursorY + 1) * win->width];
            if ((s8)c < 0 && ((u8)c <= 0x9F || func_0807AAE0((s[0] << 8) | s[1]) != 0xFF))
            {
                func_0807ABEC((s[0] << 8) | s[1], win->font, glyph);
                t = tile[0] & 0x3FF;
                if (t < D_0201F5C4 || t >= D_0201F5C4 + 0x40)
                    func_0807AA34(t - D_0201F5D0);
                t = tile[win->width] & 0x3FF;
                if (t < D_0201F5C4 || t >= D_0201F5C4 + 0x40)
                    func_0807AA34(t - D_0201F5D0);
                tile[0] = glyph[0];
                tile[win->width] = glyph[1];
                win->cursorX++;
                s += 2;
                lineH = 2;
            }
            else
            {
                if (lineH == 1)
                {
                    func_0807ADC4(*s, win->font, glyph);
                }
                else
                {
                    func_0807AF84(*s, win->font, glyph);
                    t = tile[win->width] & 0x3FF;
                    if (t < D_0201F5C4 || t >= D_0201F5C4 + 0x40)
                        func_0807AA34(t - D_0201F5D0);
                    tile[win->width] = glyph[1];
                }
                t = tile[0] & 0x3FF;
                if (t < D_0201F5C4 || t >= D_0201F5C4 + 0x40)
                    func_0807AA34(t - D_0201F5D0);
                tile[0] = glyph[0];
                win->cursorX++;
                s += 1;
            }
        }
        if (!(win->flags & 0x10))
        {
            if (*s != 10)
            {
                if (*s == 0)
                    break;
                if (!(win->flags & 0x40) || win->cursorX != win->width - 2)
                    continue;
            }
            win->cursorX = 0;
            win->cursorY += lineH;
            if (*s == 10)
                s++;
        }
        else
        {
            win->flags |= 2;
            func_0807A1A4();
            if (!(D_0300000C & 2))
            {
                if (D_03000081 == 1)
                    func_080C8FCC(2);
                else
                    func_080C8FCC(1);
            }
            if (*s == 0)
                break;
            if (*s != 10)
            {
                if (*s == 0)
                    break;
                if (!(win->flags & 0x40) || win->cursorX != win->width - 2)
                    continue;
            }
            win->lines += lineH;
            if (win->cursorY == win->height - 2 - lineH)
            {
                if (win->lines == win->height - 2)
                {
                    D_0200C4EC[1] = func_080771BC(D_080C9470, D_080C9498, 1,
                        (win->x + 1 + win->cursorX) * 8, (win->y + 1 + win->cursorY) * 8 + 8,
                        D_0201F5CC + 2, D_0201F5CE, 0x1020 | (D_0201F5CB << 6) | (D_0201F5CA << 13), 0);
                    do
                        func_080C8FCC(1);
                    while (!(D_0300000E & 3));
                    func_080771F4(D_0200C4EC[1]);
                    if (!(win->flags & 0x800))
                        win->lines = 0;
                    else
                        win->lines = lineH;
                    func_08075F20(0xCD);
                }
                for (k = 0; k < lineH; k++)
                {
                    start = !(win->flags & 0x800) ? 1 : 3;
                    for (row = start; row < win->height - 2; row++)
                    {
                        for (col = 1; col < win->width - 1; col++)
                        {
                            if (row == start)
                            {
                                t = win->tiles[col + row * win->width] & 0x3FF;
                                if (t < D_0201F5C4 || t >= D_0201F5C4 + 0x40)
                                    func_0807AA34(t - D_0201F5D0);
                            }
                            win->tiles[col + row * win->width] = win->tiles[col + (row + 1) * win->width];
                        }
                    }
                    for (col = 1; col < win->width - 1; col++)
                        win->tiles[col + row * win->width] = (D_0201F5C4 + 1) | D_0201F5C8;
                    win->cursorY--;
                    win->flags |= 2;
                    func_0807A1A4();
                    if (D_03000081 == 1)
                        func_080C8FCC(2);
                    else
                        func_080C8FCC(1);
                }
            }
            win->cursorX = 0;
            win->cursorY += lineH;
            if (*s == 10)
                s++;
        }
    }
    return s;
}
