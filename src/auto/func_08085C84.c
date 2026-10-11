#include "m2c.h"

M2C_UNK func_08083C5C(u8, s32, s32);
M2C_UNK func_08085B58(u8, u8, u8, u8, s32);

s32 func_08085C84(u8 arg0, u8 **arg1)
{
    u8 *temp_r4;

    temp_r4 = *arg1;
    func_08085B58(M2C_FIELD(temp_r4, u8 *, 1), M2C_FIELD(temp_r4, u8 *, 2), M2C_FIELD(temp_r4, u8 *, 3), M2C_FIELD(temp_r4, u8 *, 4), (s32) M2C_FIELD(temp_r4, u8 *, 5));
    func_08083C5C(arg0, -1, 0);
    return 0;
}
