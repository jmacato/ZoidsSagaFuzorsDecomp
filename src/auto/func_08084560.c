#include "m2c.h"

extern struct { s8 f_0; u8 pad_1[0x235]; u8 f_236; } D_0201F6DC;

M2C_UNK func_08083C5C(u8, s32, s32);
M2C_UNK func_080843FC();

s32 func_08084560(u8 arg0)
{
    D_0201F6DC.f_0 = 1;
    func_080843FC();
    if (D_0201F6DC.f_236 == 0)
    {
        func_08083C5C(arg0, -1, 0);
    }
    return 0;
}
