#include "m2c.h"

extern struct { u8 pad_0[0x958]; s32 f_958; } D_02036E7C;

M2C_UNK func_08075F20(s32);
M2C_UNK func_08077E6C();
M2C_UNK func_080A2158();
u8 func_080A2250();
M2C_UNK func_080A24B4();
s32 func_080A24F0();
M2C_UNK func_080C8FCC(s32);

void func_080A2AE8(void)
{
    if (func_080A2250() == 1)
    {
        func_08075F20(0x116);
        func_080A2158();
        while ((u32) func_080A2250() <= 1U)
        {
            func_080C8FCC(1);
        }
    }
    if ((func_080A24F0() << 0x18) == 0)
    {
        func_080A24B4();
        while ((func_080A24F0() << 0x18) == 0)
        {
            func_080C8FCC(1);
        }
    }
    if (D_02036E7C.f_958 != 0)
    {
        func_08077E6C();
        D_02036E7C.f_958 = 0;
    }
}
