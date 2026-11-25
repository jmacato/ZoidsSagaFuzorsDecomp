#include "m2c.h"

void func_080AEE7C(u8 *arg0)
{
    M2C_FIELD(arg0, s32 *, 0x8C) = 0;
    M2C_FIELD((arg0 + 0x8C), u32 *, 4) = (u32) ((u32) M2C_FIELD(arg0, u32 *, 0xA8) >> 0xC);
    M2C_FIELD(arg0, u32 *, 0xA8) = (u32) (M2C_FIELD(arg0, u32 *, 0xA8) & 0xC0);
}
