#include "m2c.h"

s32 func_080C8EF4(void)
{
    s32 temp_r0;
    u8 *temp_r2;

    temp_r2 = *(u8 **)0x087B54A8;
    temp_r0 = (M2C_FIELD(temp_r2, s32 *, 0x58) * 0x41C64E6D) + 0x3039;
    M2C_FIELD(temp_r2, s32 *, 0x58) = temp_r0;
    return temp_r0 & 0x7FFFFFFF;
}
