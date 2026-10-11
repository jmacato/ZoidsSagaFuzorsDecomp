#include "types.h"

struct Win
{
    u32 flags;
    u8 pad4[4];
    u16 width;
    u16 height;
    u8 padC[7];
    u8 id;
    u8 pad14[6];
    u8 footer;
    u8 pad1B[5];
    u16 tiles[0x258];
};

extern struct Win D_02009480[];
extern u32 D_0201F5C4;
extern u32 D_0201F5D0;

void func_0807AA34(u16);
void func_0807A140(u8);

void func_0807BD8C(u8 id)
{
    struct Win *win = &D_02009480[id];
    u16 *tile = win->tiles;
    s32 y, x;
    u16 t;

    for (y = 0; y < win->height; y++)
    {
        for (x = 0; x < win->width; x++)
        {
            t = *tile & 0x3FF;
            if (t < D_0201F5C4 || t >= D_0201F5C4 + 0x40)
                func_0807AA34(t - D_0201F5D0);
            *tile = D_0201F5C4;
            tile++;
        }
    }
    if (win->flags & 8)
    {
        for (y = 0; y < 3; y++)
        {
            for (x = 0; x < win->footer; x++)
            {
                *tile = D_0201F5C4;
                tile++;
            }
        }
    }
    win->flags |= 4;
    func_0807A140(win->id);
}
