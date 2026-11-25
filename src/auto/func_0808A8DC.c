#include "m2c.h"

s16 func_080C8BE8(s16, s32);

s32 func_0808A8DC(u8 *arg0)
{
    s32 var_r5;

    var_r5 = 0;
    if ((s32) M2C_FIELD(arg0, s16 *, 6) <= (s32) func_080C8BE8(M2C_FIELD(arg0, s16 *, 0x62), 0xA))
    {
        var_r5 = 1;
    }
    return var_r5;
}
