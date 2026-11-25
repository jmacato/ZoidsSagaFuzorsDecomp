#include "types.h"

extern u32 D_0201F5B4;
extern u32 D_0201F5C4;
extern u16 D_0201F5C8;
extern u32 D_0201F5D0;

u8 func_0807AA58(u8, u16 *);
u8 func_0807AD1C(u8, u8, u32);
void func_0807AA10(u16);

void func_0807ADC4(u8 ch, u8 color, u16 *out)
{
    u16 tile;

    if (ch == 0x20)
    {
        *out = (D_0201F5C4 + 1) | D_0201F5C8;
    }
    else if (func_0807AA58(1, &tile) && func_0807AD1C(ch, color, D_0201F5B4 + tile * 32))
    {
        func_0807AA10(tile);
        *out = (D_0201F5D0 + tile) | (D_0201F5C8 + ((u8)(color / 3) << 12));
    }
    else
    {
        *out = (D_0201F5C4 + 1) | D_0201F5C8;
    }
}
