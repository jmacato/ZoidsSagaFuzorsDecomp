#include "m2c.h"

M2C_UNK func_08083C5C(u8, s32, s32);
M2C_UNK func_0809FCD4(s32, u8, u8, s32);

s32 func_08085E5C(u8 arg0, u8 **arg1)
{
    u8 *temp_r0;

    temp_r0 = *arg1;
    func_0809FCD4(5, M2C_FIELD(temp_r0, u8 *, 1), M2C_FIELD(temp_r0, u8 *, 2), 0);
    func_08083C5C(arg0, -1, 0);
    return 0;
}
