#include "m2c.h"

extern struct { u8 pad_0[0x1142]; u8 f_1142; } D_0201F6DC;

M2C_UNK func_080A0D0C(u16, s32, s32);
M2C_UNK func_080A0DA4(u16, s32);
M2C_UNK func_080A2158();
u8 func_080A2250();
M2C_UNK func_080A24B4();
s32 func_080A24F0();
M2C_UNK func_080A3358();
M2C_UNK func_080C8FCC(s32);

void func_08086454(u16 arg0)
{
    u16 temp_r4;

    temp_r4 = arg0;
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
    if (!(1 & D_0201F6DC.f_1142))
    {
        func_080A0D0C(temp_r4, 0, 0);
    }
    else
    {
        func_080A0DA4(temp_r4, 0);
    }
    func_080A3358();
}
