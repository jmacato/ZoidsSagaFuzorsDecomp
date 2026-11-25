#include "m2c.h"

M2C_UNK func_080A0E18(u16, s32);
M2C_UNK func_080A2158();
u8 func_080A2250();
M2C_UNK func_080A24B4();
s32 func_080A24F0();
M2C_UNK func_080A3358();
M2C_UNK func_080C8FCC(s32);

void func_0808653C(u16 arg0)
{
    if (func_080A2250() == 1)
    {
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
    func_080A0E18(arg0, 0);
    func_080A3358();
}
