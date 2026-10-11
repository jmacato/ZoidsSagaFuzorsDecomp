#include "types.h"

struct Map
{
    u8 pad_0[0x14];
    u16 width;
    u16 height;
    vu8 mode;
};

extern struct Map D_020209D8;
extern u8 *D_02031A18;
s32 func_08081E80(u8, u16);

u16 func_08081F04(u8 kind, s32 x, s32 y)
{
    struct Map *map;
    u32 w = D_020209D8.width >> 1;
    u8 tile;
    x = x % (s32)w;
    y = y % (D_020209D8.height >> 1);
    map = &D_020209D8;
    if (x < 0)
    {
        s32 t = w;
        do
            x += t;
        while (x < 0);
    }
    while (y < 0)
        y += D_020209D8.height >> 1;
    if (map->mode != 2 && (x <= 0 || y <= 0 || x >= (map->width >> 1) - 1 || y >= (map->height >> 1) - 1))
        return 1;
    tile = D_02031A18[x + y * (map->width >> 1)];
    if (tile & 0x40)
        return 0;
    return func_08081E80(kind, tile);
}
