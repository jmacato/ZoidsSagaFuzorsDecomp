#include "m2c.h"

s32 func_0809D984(u8);
s32 func_0809D998(u8);

s32 func_0809E09C(void)
{
    u8 var_r4;

    var_r4 = 0;
loop_1:
    if ((func_0809D984(var_r4) != 0) && (func_0809D998(var_r4) == 0))
    {
        return 0;
    }
    var_r4 += 1;
    if ((u32) var_r4 > 0x17U)
    {
        return 1;
    }
    goto loop_1;
}
