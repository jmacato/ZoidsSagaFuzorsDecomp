#include "m2c.h"

extern struct { u8 pad_0[0x8C]; s32 f_8C; s32 f_90; } D_0201F5F8;

M2C_UNK func_080771F4(s32);

void func_080B467C(void)
{
    func_080771F4(D_0201F5F8.f_8C);
    func_080771F4(D_0201F5F8.f_90);
}
