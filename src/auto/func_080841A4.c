#include "m2c.h"

M2C_UNK func_08083C5C(u8, s32, s32);
M2C_UNK func_08084164(u8, u8, s32, s32, s32, s32, s32);

s32 func_080841A4(u8 arg0, u8 **arg1)
{
    u8 *temp_r5;

    temp_r5 = *arg1;
    if ((u32) M2C_FIELD(temp_r5, u8 *, 1) <= 0xCU)
    {
        func_08084164(M2C_FIELD(temp_r5, u8 *, 2), M2C_FIELD(temp_r5, u8 *, 1), (M2C_FIELD(temp_r5, u8 *, 3) | (M2C_FIELD(temp_r5, u8 *, 4) << 8)) << 0xB, (M2C_FIELD(temp_r5, u8 *, 5) | (M2C_FIELD(temp_r5, u8 *, 6) << 8)) << 0xB, (s32) M2C_FIELD(temp_r5, u8 *, 7), (s32) M2C_FIELD(temp_r5, u8 *, 8), (s32) M2C_FIELD(temp_r5, u8 *, 9));
    }
    func_08083C5C(arg0, -1, 0);
    return 0;
}
