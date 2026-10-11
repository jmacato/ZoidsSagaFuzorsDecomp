#include "m2c.h"

M2C_UNK func_08083C5C(u8, s32, s32);
M2C_UNK func_0809D93C();
M2C_UNK func_0809D948(u8, s32);
s32 func_0809D998(u8);

s32 func_080849B4(u8 arg0, u8 **arg1)
{
    u8 temp_r5;

    temp_r5 = arg0;
    if (func_0809D998(M2C_FIELD(*arg1, u8 *, 1)) != 0)
    {
        func_0809D948(M2C_FIELD(*arg1, u8 *, 1), 0);
        func_08083C5C(temp_r5, 0xF, 0);
    }
    else
    {
        func_0809D93C();
        func_08083C5C(temp_r5, 0x10, 0);
    }
    return 0;
}
