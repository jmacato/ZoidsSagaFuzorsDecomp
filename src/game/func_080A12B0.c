#include "types.h"

struct State
{
    u8 pad_0[0x8A4];
    u8 mode;
    u8 field_8A5;
    u8 pad_8A6[0x12];
    s32 field_8B8;
    s32 field_8BC;
    s32 field_8C0;
    u8 pad_8C4[0x4B];
    u8 field_90F;
};

extern struct State D_02036E7C;

void func_080A12B0(u8 mode, s32 arg)
{
    if ((mode == 6 || mode == 8) && D_02036E7C.field_90F == 4)
        mode = 9;
    D_02036E7C.mode = (D_02036E7C.mode & 0x80) | mode;
    D_02036E7C.field_8C0 = arg;
    D_02036E7C.field_8A5 = 0;
    D_02036E7C.field_8B8 = D_02036E7C.field_8BC = 0;
}
