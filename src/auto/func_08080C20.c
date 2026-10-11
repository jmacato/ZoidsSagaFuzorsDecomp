#include "m2c.h"

M2C_UNK func_08080974(s32);

void func_08080C20(void)
{
    s32 temp_r0;
    u8 var_r4;

    var_r4 = 0;
    do
    {
        temp_r0 = var_r4 * 0x44;
        if (1 & M2C_FIELD(temp_r0, u8 *, 0x02020A44))
        {
            func_08080974(temp_r0 + 0x02020A44);
        }
        var_r4 += 1;
    } while ((u32) var_r4 <= 0xDU);
}
