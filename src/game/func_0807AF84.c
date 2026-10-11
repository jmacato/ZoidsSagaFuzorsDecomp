#include "types.h"

extern u32 D_0201F5B4;
extern u32 D_0201F5C4;
extern u16 D_0201F5C8;
extern u32 D_0201F5D0;

u8 func_0807AA58(u8, u16 *);
u8 func_0807AE80(u8, u8, u32, u32);
void func_0807AA10(u16);

void func_0807AF84(u8 ch, u8 color, u16 *out)
{
    u16 tiles[2];

    if (ch == 0x20)
    {
        out[0] = (D_0201F5C4 + 1) | D_0201F5C8;
        out[1] = (D_0201F5C4 + 1) | D_0201F5C8;
    }
    else if (func_0807AA58(2, tiles) && func_0807AE80(ch, color, D_0201F5B4 + tiles[0] * 32, D_0201F5B4 + tiles[1] * 32))
    {
        func_0807AA10(tiles[0]);
        func_0807AA10(tiles[1]);
        out[0] = (D_0201F5D0 + tiles[0]) | (D_0201F5C8 + ((u8)(color / 3) << 12));
        out[1] = (D_0201F5D0 + tiles[1]) | (D_0201F5C8 + ((u8)(color / 3) << 12));
    }
    else
    {
        out[0] = (D_0201F5C4 + 1) | D_0201F5C8;
        out[1] = (D_0201F5C4 + 1) | D_0201F5C8;
    }
}
