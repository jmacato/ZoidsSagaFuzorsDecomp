#include "m2c.h"

M2C_UNK func_08075E80(u8);
M2C_UNK func_08083C5C(u8, s32, s32);

s32 func_08085A80(u8 arg0, u8 **arg1)
{
    func_08075E80(M2C_FIELD(*arg1, u8 *, 1));
    func_08083C5C(arg0, -1, 0);
    return 0;
}
