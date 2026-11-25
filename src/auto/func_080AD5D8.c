#include "m2c.h"

M2C_UNK func_080A38B0(s32);

void func_080AD5D8(u8 *arg0)
{
    M2C_FIELD(arg0, s32 *, 0x8C) = 0;
    *(s16 *)0x03000058 = 0x1010;
    func_080A38B0(0);
}
