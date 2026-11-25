#include "m2c.h"

M2C_UNK func_08083C5C(u8, s32, s32);
M2C_UNK func_0809D948(u8, s32);

s32 func_08084AB8(u8 arg0, u8 **arg1)
{
    func_0809D948(M2C_FIELD(*arg1, u8 *, 1), 0);
    func_08083C5C(arg0, -1, 0);
    return 0;
}
