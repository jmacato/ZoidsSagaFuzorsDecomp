#include "m2c.h"

M2C_UNK func_08075F20(s32);
s32 func_080B2C38(u8 *, s32, s32, s32, s32, s32, s32, s32);
M2C_UNK func_080B2D78(u8 *);

void func_080B3980(u8 *arg0)
{
    s32 temp_r1;

    temp_r1 = M2C_FIELD(arg0, s32 *, 0x8C);
    if (temp_r1 == 0)
    {
        M2C_FIELD(arg0, s32 *, 0x88) = func_080B2C38(arg0, 5, 0, 0, temp_r1, 6, 0x200, temp_r1);
        func_08075F20(0xEB);
        M2C_FIELD(arg0, s32 *, 0x8C) = (s32) (M2C_FIELD(arg0, s32 *, 0x8C) + 1);
    }
    func_080B2D78(arg0);
}
