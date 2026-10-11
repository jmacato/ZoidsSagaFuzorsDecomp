#include "m2c.h"

u8 func_080BD304(u8);

void func_080BDF14(u8 *arg0, u8 arg1)
{
    u8 temp_r1;

    temp_r1 = arg1;
    if ((((u32) (u8) (M2C_FIELD(arg0, u8 *, 0) - 6) <= 4U) && ((u32) temp_r1 > 5U) && ((u32) temp_r1 <= 0xAU)) || (((u32) (u8) (M2C_FIELD(arg0, u8 *, 0) - 0x29) <= 2U) && ((u32) temp_r1 > 0x28U) && ((u32) temp_r1 <= 0x2BU)))
    {
        M2C_FIELD(arg0, u8 *, 3) = (u8) ((1 << func_080BD304(temp_r1)) | M2C_FIELD(arg0, u8 *, 3));
    }
}
