#include "m2c.h"

M2C_UNK func_08079544(s32, s32);
M2C_UNK func_0807970C();
M2C_UNK func_08083C5C(u8, s32, s32);

s32 func_08084F04(u8 arg0)
{
    *(s8 *)0x0201F6DC = 1;
    func_0807970C();
    func_08079544(7, 0);
    func_08083C5C(arg0, -1, 0);
    return 0;
}
