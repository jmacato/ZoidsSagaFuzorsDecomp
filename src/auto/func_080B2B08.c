#include "m2c.h"

s16 func_08075AAC(s16);
M2C_UNK func_080771F4(u8 *);

void func_080B2B08(u8 *arg0)
{
    s32 temp_r1;
    s32 var_r0;

    temp_r1 = M2C_FIELD(arg0, s32 *, 0x30);
    if (temp_r1 <= 8)
    {
        if (temp_r1 >= 0)
        {
            if (temp_r1 == 0)
            {
                M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(arg0, s32 *, 0) & 0xFFFDFFFF);
            }
            var_r0 = 0 - func_08075AAC((s16) (M2C_FIELD(arg0, s32 *, 0x30) * 0x10));
            if (var_r0 < 0)
            {
                var_r0 += 0x1F;
            }
            M2C_FIELD(arg0, s16 *, 0xE) = (s16) (var_r0 >> 5);
        }
    }
    else if (temp_r1 == M2C_FIELD(arg0, s32 *, 0x34))
    {
        func_080771F4(arg0);
    }
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) (M2C_FIELD(arg0, s32 *, 0x30) + 1);
}
