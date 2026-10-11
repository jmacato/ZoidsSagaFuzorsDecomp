#include "types.h"

struct Map
{
    u16 id;
    u8 pad_2[0x1A];
    u8 entry;
    u8 pad_1D[3];
    s32 field_20;
    s32 field_24;
    s32 field_28;
    s32 field_2C;
};

extern struct Map D_020209D8;
extern u16 D_0877C4E6[][3];
extern u32 (*D_03000010)(void);
s32 func_080C8BE8(s32, s32);

void func_08088630(void)
{
    u8 i = 0;
    s32 r;
    for (; D_0877C4E6[i][0] != 0; i++)
    {
        if (D_0877C4E6[i][0] == D_020209D8.id)
            break;
    }
    D_020209D8.entry = i;
    D_020209D8.field_20 = D_020209D8.field_24 = 0;
    r = ((D_03000010() * 1000) >> 15) - 1366;
    D_020209D8.field_28 = func_080C8BE8(-500000, r) - 366;
    D_020209D8.field_2C = 0x578;
}
