#include "types.h"

struct Pilot
{
    u16 field_0;
    u8 pad_2[0x26E];
};

struct Game
{
    u8 pad_0[0x244];
    u8 field_244;
    u8 pad_245[7];
    s32 field_24C;
    u8 pad_250[0x1FE0];
    struct Pilot pilots[8];
    u8 pad_35B0[0x19D5];
    u8 teams[8][4];
};

extern struct Game D_02031A0C;

void func_0809CC6C(u8 a, u8 b, u8 c);

void func_0809D624(void)
{
    u8 i, j, k;
    for (i = 0; i < 3 && D_02031A0C.teams[D_02031A0C.field_244][i] != 0xFF; i++)
        for (j = 0; j < 2; j++)
            for (k = 0; k < 6; k++)
                func_0809CC6C(i, j, k);
}
