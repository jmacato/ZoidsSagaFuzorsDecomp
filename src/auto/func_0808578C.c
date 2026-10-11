#include "m2c.h"

extern struct { s8 f_0; u8 pad_1[0x12EF]; s8 f_12F0; u8 pad_12F1[0x3]; s32 f_12F4; s32 f_12F8; } D_0201F6DC;

M2C_UNK func_08075F20(s32);
M2C_UNK func_08083C5C(u8, s32, s32);

s32 func_0808578C(u8 arg0)
{
    D_0201F6DC.f_0 = 1;
    D_0201F6DC.f_12F4 = 0;
    D_0201F6DC.f_12F8 = 0;
    D_0201F6DC.f_12F0 = 1;
    func_08075F20(0xD4);
    func_08083C5C(arg0, -1, 0);
    return 0;
}
