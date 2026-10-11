#include "m2c.h"

extern struct { u8 pad_0[0x7A5C]; s32 f_7A5C; } D_02020E4C;

M2C_UNK func_0807A1A4();
M2C_UNK func_0807BA24(s32, s32, s32, s32, s32, s32, s32);

void func_080B4D10(u8 arg0)
{
    func_0807BA24(D_02020E4C.f_7A5C, 9, 0, 0x12, (s32) arg0, 3, 0);
    func_0807A1A4();
}
