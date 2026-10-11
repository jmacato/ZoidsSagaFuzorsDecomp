#include "m2c.h"

extern struct { u8 pad_0[0x84]; s8 f_84; } D_0201F5F8;

void func_080B4390(s8 arg0, s32 arg1)
{
    D_0201F5F8.f_84 = arg0;
    M2C_FIELD((u8 *)((u8 *)&D_0201F5F8 + 0x85), s8 *, 0) = 0;
    M2C_FIELD((u8 *)((u8 *)&D_0201F5F8 + 0x85), s32 *, 3) = arg1;
}
