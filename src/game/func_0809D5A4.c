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

void func_080BE0A0(s32 a, s16 b);

void func_0809D5A4(void)
{
    u8 i;
    for (i = 0; i < 3 && D_02031A0C.teams[D_02031A0C.field_244][i] != 0xFF; i++)
    {
        u8 id = D_02031A0C.teams[D_02031A0C.field_244][i] & 7;
        func_080BE0A0(D_02031A0C.field_24C, -D_02031A0C.pilots[id].field_0);
    }
}
