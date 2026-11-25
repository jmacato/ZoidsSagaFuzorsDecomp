#include "m2c.h"

u32 func_080C18B8(void)
{
    u8 temp_r1;

    temp_r1 = *(u8 *)0x02036E24;
    return (u32) ((0 - temp_r1) | temp_r1) >> 0x1F;
}
