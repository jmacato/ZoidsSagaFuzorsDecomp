#include "m2c.h"

u8 func_080BF59C(s32, u8);
M2C_UNK func_080BF5C0(s32, u8, u8);

void func_080BF978(s32 arg0, u8 arg1, u8 arg2)
{
    s32 temp_r0;
    u8 temp_r5;

    temp_r5 = arg1;
    temp_r0 = func_080BF59C(arg0, temp_r5) - arg2;
    if (temp_r0 >= 0)
    {
        func_080BF5C0(arg0, temp_r5, (u8) temp_r0);
        return;
    }
    func_080BF5C0(arg0, temp_r5, 0U);
}
