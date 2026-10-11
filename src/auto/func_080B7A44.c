#include "m2c.h"

extern struct { u8 pad_0[0x54]; s32 f_54; } D_0201F5F8;

M2C_UNK func_080771F4(s32);
M2C_UNK func_0807C290(M2C_UNK);

void func_080B7A44(void)
{
    func_0807C290(0x08007111);
    func_080771F4(D_0201F5F8.f_54);
}
