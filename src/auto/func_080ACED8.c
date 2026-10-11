#include "m2c.h"

M2C_UNK func_08077E6C(u8 *);
M2C_UNK func_080A2070();
u8 func_080A2250();
M2C_UNK func_080A38B0(s32);

void func_080ACED8(u8 *arg0)
{
    if (M2C_FIELD(arg0, s32 *, 0x8C) == 0)
    {
        func_080A2070();
        func_080A38B0(0);
        M2C_FIELD(arg0, s32 *, 0x8C) = (s32) (M2C_FIELD(arg0, s32 *, 0x8C) + 1);
        return;
    }
    if (func_080A2250() == 1)
    {
        func_08077E6C(arg0);
    }
}
