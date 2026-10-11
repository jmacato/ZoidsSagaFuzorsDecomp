#include "m2c.h"

extern struct { u8 pad_0[0x54]; s32 f_54; } D_0201F5F8;

s32 func_080771BC(M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32, s32);

void func_080B4D70(void)
{
    s32 temp_r3;

    temp_r3 = D_0201F5F8.f_54;
    if (temp_r3 == 0)
    {
        D_0201F5F8.f_54 = func_080771BC(0x080F1FD4, 0x080F2008, 0, 0x80, 0x70, 0x2C2, 0xF, 0x20, temp_r3);
    }
}
