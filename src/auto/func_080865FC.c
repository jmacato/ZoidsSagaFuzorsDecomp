#include "m2c.h"

extern struct { u8 pad_0[0x1143]; s8 f_1143; } D_0201F6DC;

M2C_UNK func_08083C5C(u8, s32, s32);

s32 func_080865FC(u8 arg0)
{
    D_0201F6DC.f_1143 = 1;
    func_08083C5C(arg0, -1, 0);
    return 0;
}
