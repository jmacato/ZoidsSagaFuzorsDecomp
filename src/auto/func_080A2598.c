#include "m2c.h"

M2C_UNK func_080771F4(u8 *);

void func_080A2598(u8 *arg0)
{
    s32 temp_r0;
    s32 temp_r0_2;

    if (!(M2C_FIELD(arg0, s32 *, 0) & 0x8000))
    {
        temp_r0 = M2C_FIELD(arg0, s32 *, 4) + M2C_FIELD(arg0, s32 *, 0x30);
        M2C_FIELD(arg0, s32 *, 4) = temp_r0;
        if (temp_r0 > 0x11000)
        {
            func_080771F4(arg0);
        }
    }
    else
    {
        temp_r0_2 = M2C_FIELD(arg0, s32 *, 4) - M2C_FIELD(arg0, s32 *, 0x30);
        M2C_FIELD(arg0, s32 *, 4) = temp_r0_2;
        if (temp_r0_2 < 0)
        {
            func_080771F4(arg0);
        }
    }
}
