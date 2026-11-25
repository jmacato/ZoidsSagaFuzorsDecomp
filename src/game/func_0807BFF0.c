#include "types.h"

struct Win
{
    u32 flags;
    u8 pad4[4];
    u16 width;
    u16 height;
    u16 cursorX;
    u16 cursorY;
    u8 pad10[3];
    u8 id;
    u8 top;
    u8 pad15[0x4BB];
};

extern u8 D_0200C62E[][210][0x25];
extern struct Win D_02009480[];
extern const u8 D_080C9790[];

void func_0807B048(struct Win *, const u8 *);
u8 func_0807C100(const u8 *);

void func_0807BFF0(u8 id, u8 line, const u8 *str)
{
    u8 i;
    struct Win *win;
    u16 x, y;

    for (i = 0; i < 36 && *str != 0; str++, i++)
    {
        D_0200C62E[id][line][i] = *str;
        if (*str == 1)
        {
            str++;
            i++;
            D_0200C62E[id][line][i] = *str;
        }
    }
    D_0200C62E[id][line][i] = 0;
    win = &D_02009480[id];
    if (line >= win->top && line < win->top + (win->height - 2) / 2)
    {
        x = win->cursorX;
        y = win->cursorY;
        win->cursorX = 0;
        win->cursorY = (line - win->top) * 2;
        func_0807B048(win, D_0200C62E[win->id][line]);
        for (i = func_0807C100(D_0200C62E[win->id][line]); i < win->width - 2; i++)
            func_0807B048(win, D_080C9790);
        win->cursorX = x;
        win->cursorY = y;
        win->flags |= 2;
    }
}
