#include "m2c.h"

M2C_UNK func_0807BC68(u8, s32, s32, u8, s32);

void func_0807BD4C(u8 arg0)
{
    u8 temp_r0;
    u8 *temp_r4;

    temp_r0 = arg0;
    temp_r4 = (0x4D0 * temp_r0) + 0x02009480;
    func_0807BC68(temp_r0, 0, 0, (u8) (M2C_FIELD(temp_r4, u8 *, 8) - 2), (s32) (u8) (M2C_FIELD(temp_r4, u8 *, 0xA) - 2));
    M2C_FIELD(temp_r4, s16 *, 0x10) = 0;
}
