#include "types.h"

struct Win
{
    u32 flags;
    u8 pad4[4];
    u16 width;
    u16 height;
    u16 cursorX;
    u16 cursorY;
    u8 pad10[2];
    u8 field_12;
    u8 id;
    u8 pad14[0xC];
    u16 tiles[0x258];
};

extern struct Win D_02009480[];
extern u32 D_0201F5C4;
extern u16 D_0201F5C8;
extern u32 D_0201F5D0;

void func_0807AA34(u16);

void func_0807BC68(u8 id, u8 x, u8 y, u8 w, u8 h)
{
    struct Win *win = &D_02009480[id];
    u8 i, j;
    u16 *tile;
    u16 t;

    for (j = 0; j < h; j++)
    {
        tile = &(&win->tiles[x + 1])[(y + j + 1) * win->width];
        for (i = 0; i < w; i++)
        {
            t = *tile & 0x3FF;
            if (t < D_0201F5C4 || t >= D_0201F5C4 + 0x40)
            {
                func_0807AA34(t - D_0201F5D0);
                *tile = (D_0201F5C4 + 1) | D_0201F5C8;
            }
            tile++;
        }
    }
    win->cursorX = x;
    win->cursorY = y;
    win->field_12 = 0;
    win->flags |= 2;
}
