#include "m2c.h"

u8 *func_0809A908(u8, u8);
s32 func_0809A99C(u8, u8);
M2C_UNK func_080BE0A0(u8 *, s16);

void func_080BF4C4(u8 arg0, u8 arg1)
{
    u8 temp_r4;
    u8 temp_r5;
    u8 *temp_r0;

    temp_r5 = arg0;
    temp_r4 = arg1;
    if (func_0809A99C(temp_r5, temp_r4) != 0)
    {
        temp_r0 = func_0809A908(temp_r5, temp_r4);
        func_080BE0A0(temp_r0, M2C_FIELD(temp_r0, s16 *, 0x66));
    }
}
