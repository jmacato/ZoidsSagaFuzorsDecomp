#include "m2c.h"

u8 func_08083628(s32);
M2C_UNK func_08083C5C(u8, s32, u8);

s32 func_08084634(u8 arg0, s32 *arg1)
{
    *(s8 *)0x0201F6DC = 1;
    func_08083C5C(arg0, 0x12, func_08083628(*arg1 + 3));
    return 0;
}
