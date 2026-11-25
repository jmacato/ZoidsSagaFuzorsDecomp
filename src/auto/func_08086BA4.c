#include "m2c.h"

extern struct { u8 pad_0[0x20]; u8 f_20; u8 pad_21[0x2]; s8 f_23; u8 pad_24[0x2]; s16 f_26; } D_02020E4C;

M2C_UNK func_0807F318(s32);
M2C_UNK func_08083C5C(u8, s32, s32);

s32 func_08086BA4(u8 arg0, u8 **arg1)
{
    u8 temp_r0;

    D_02020E4C.f_20 = M2C_FIELD(*arg1, u8 *, 1);
    if (M2C_FIELD(*arg1, u8 *, 1) == 0x8A)
    {
        D_02020E4C.f_23 = 1;
        D_02020E4C.f_26 = 0xFFFF;
    }
    temp_r0 = M2C_FIELD(*arg1, u8 *, 1);
    switch (temp_r0)
    {
    case 0x88:
        func_0807F318(0x94);
        break;
    case 0x89:
        func_0807F318(0x95);
        break;
    case 0x8A:
        func_0807F318(0x96);
        break;
    }
    func_08083C5C(arg0, -1, 0);
    return 0;
}
