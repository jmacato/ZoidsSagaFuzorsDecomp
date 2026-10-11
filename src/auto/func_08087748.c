#include "m2c.h"

extern struct { u8 pad_0[0x26]; s16 f_26; } D_02020E4C;

M2C_UNK func_08083C5C(u8, s32, s32);

s32 func_08087748(u8 arg0)
{
    D_02020E4C.f_26 = 0xFFFF;
    func_08083C5C(arg0, -1, 0);
    return 0;
}
