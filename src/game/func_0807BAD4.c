#include "types.h"

struct Win
{
    u32 flags;
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    u16 cursorX;
    u16 cursorY;
    u8 pad10[2];
    u8 field_12;
    u8 id;
    u8 top;
    u8 field_15;
    u8 field_16;
    u8 field_17;
    u8 pad18;
    u8 field_19;
    u8 field_1A;
    u8 field_1B;
    u16 field_1C;
    u8 field_1E;
    u8 pad1F;
    u16 tiles[0x258];
};

extern struct Win D_02009480[];
extern u32 D_0201F5C4;
extern u16 D_0201F5C8;
extern u8 D_0200C624[];
extern const u8 D_080C9780[];
extern const u8 D_080C9788[];

void func_0807B048(struct Win *, const u8 *);
void func_0807A0C8(u8);

void func_0807BAD4(u8 id, u8 x, u8 y, u8 w, u8 h, u32 flags)
{
    struct Win *win = &D_02009480[id];
    u16 *tile;

    win->x = x;
    win->y = y;
    win->width = w;
    win->height = h;
    win->cursorX = win->cursorY = 0;
    win->field_12 = 0;
    win->field_19 = win->field_1A = 0;
    win->field_1B = 0x10;
    win->field_1C = 0;
    win->field_1E = 0;
    win->flags = flags | 1;
    tile = win->tiles;
    for (y = 0; y < win->height; y++)
    {
        for (x = 0; x < win->width; x++)
        {
            if (y == 0)
            {
                if (x == 0)
                    *tile = (D_0201F5C4 + 2) | D_0201F5C8;
                else if (x != win->width - 1)
                    *tile = (D_0201F5C4 + 6) | D_0201F5C8;
                else
                    *tile = (D_0201F5C4 + 3) | D_0201F5C8;
            }
            else if (y != win->height - 1)
            {
                if (x == 0)
                    *tile = (D_0201F5C4 + 8) | D_0201F5C8;
                else if (x != win->width - 1)
                    *tile = (D_0201F5C4 + 1) | D_0201F5C8;
                else
                    *tile = (D_0201F5C4 + 9) | D_0201F5C8;
            }
            else
            {
                if (x == 0)
                    *tile = (D_0201F5C4 + 4) | D_0201F5C8;
                else if (x != win->width - 1)
                    *tile = (D_0201F5C4 + 7) | D_0201F5C8;
                else
                    *tile = (D_0201F5C4 + 5) | D_0201F5C8;
            }
            tile++;
        }
    }
    if (win->flags & 0x80)
    {
        D_0200C624[win->id] = 0;
        win->field_15 = win->top = win->field_16 = 0;
        win->field_17 = 0xFF;
    }
    if (win->flags & 0x100)
    {
        win->cursorX = (win->width - 2) / 2 - 1;
        win->cursorY = win->height - 6;
        func_0807B048(win, D_080C9780);
        win->cursorX = (win->width - 2) / 2 - 1;
        win->cursorY = win->height - 4;
        func_0807B048(win, D_080C9788);
        win->cursorX = win->cursorY = 0;
        win->field_16 = 0;
    }
    func_0807A0C8(id);
}
