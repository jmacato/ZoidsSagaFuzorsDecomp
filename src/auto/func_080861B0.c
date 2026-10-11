#include "m2c.h"

M2C_UNK func_08083C5C(u8, s32, s32);
M2C_UNK func_08085F14(u8, u8, u8, u8);

s32 func_080861B0(u8 arg0, u8 **arg1)
{
    u8 *temp_r3;

    temp_r3 = *arg1;
    func_08085F14(M2C_FIELD(temp_r3, u8 *, 1), M2C_FIELD(temp_r3, u8 *, 2), M2C_FIELD(temp_r3, u8 *, 3), M2C_FIELD(temp_r3, u8 *, 4));
    func_08083C5C(arg0, -1, 0);
    return 0;
}
