#include "m2c.h"

M2C_UNK func_0807C290(M2C_UNK);
s32 func_0807F0C4(u8, s32);

void func_08086624(s32 arg0)
{
    u16 temp_r1;
    u8 var_r5;
    u8 *temp_r0;

    var_r5 = 0;
    do
    {
        temp_r0 = arg0 + (var_r5 * 4);
        temp_r1 = M2C_FIELD(temp_r0, u16 *, 0x76);
        if (temp_r1 != 0)
        {
            *(u16 *)0x0200C4C8 = temp_r1;
            func_0807C290(0x08014EC9);
            if (func_0807F0C4((u8) M2C_FIELD(temp_r0, u16 *, 0x76), 1) == 0)
            {
                func_0807C290(0x08014DDF);
            }
        }
        var_r5 += 1;
    } while ((u32) var_r5 <= 3U);
}
