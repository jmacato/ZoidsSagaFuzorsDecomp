#include "m2c.h"

void func_08094944(void)
{
    s32 *temp_r1;
    u8 var_r2;

    var_r2 = 0;
    do
    {
        temp_r1 = M2C_FIELD((var_r2 * 4), s32 **, 0x020368B0);
        *temp_r1 &= 0xFFFDFFFF;
        var_r2 += 1;
    } while ((u32) var_r2 <= 6U);
}
