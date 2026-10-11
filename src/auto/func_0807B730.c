#include "m2c.h"

extern u8 D_02009480[];

void func_0807B730(u8 arg0, s16 arg1, s16 arg2)
{
    u8 *temp_r0;

    temp_r0 = (0x4D0 * arg0) + D_02009480;
    M2C_FIELD(temp_r0, s16 *, 0xC) = arg1;
    M2C_FIELD(temp_r0, s16 *, 0xE) = arg2;
}
