#include "m2c.h"

extern struct { u8 pad_0[0x1]; u8 f_1; } D_0201F6DC;
extern struct { u8 pad_0[0x18]; u8 f_18; u8 f_19; } D_020209D8;

M2C_UNK func_08083C5C(u8, s32, s32);

s32 func_08087224(u8 arg0)
{
    if ((D_0201F6DC.f_1 == 0) && (D_020209D8.f_18 != 0))
    {
        D_020209D8.f_19 = (u8) (0xFD & D_020209D8.f_19);
    }
    func_08083C5C(arg0, -1, 0);
    return 0;
}
