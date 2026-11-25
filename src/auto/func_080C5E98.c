#include "m2c.h"

M2C_UNK func_08075E28(s32);
M2C_UNK func_08079544(s32, s32);
M2C_UNK func_0807970C();
M2C_UNK func_080A0358();
M2C_UNK func_080C5E60();

void func_080C5E98(u8 arg0)
{
    u8 temp_r4;

    temp_r4 = arg0;
    if (temp_r4 != 0)
    {
        if (temp_r4 != 5)
        {
            func_08079544(0x10, 0);
        }
        else
        {
            func_08079544(2, 0x10);
        }
        func_0807970C();
        switch (temp_r4)
        {
        case 1:
            func_08075E28(3);
            return;
        case 6:
            func_080C5E60();
            return;
        case 5:
            func_080A0358();
            func_08075E28(5);
            break;
        }
    }
}
