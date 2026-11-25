#include "m2c.h"

s32 func_080C8BAC(s32);

void func_080A7A38(u8 *arg0)
{
    M2C_FIELD(arg0, s32 *, 0x8C) = 0;
    M2C_FIELD(arg0, s32 *, 0x94) = (s32) (((u32) (func_080C8BAC(*(s32 *)0x03000010) * 0x21) >> 0xF) - 0x10);
}
