#include "m2c.h"

void func_080B0948(u8 *arg0)
{
    M2C_FIELD(arg0, s32 *, 0x8C) = 0;
    *(s16 *)0x03000058 = 0x1010;
}
