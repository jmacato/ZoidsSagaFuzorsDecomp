#include "m2c.h"

M2C_UNK func_08076F30(s32);

void func_08076B70(void)
{
    u8 temp_r5;

    temp_r5 = *(u8 *)0x03002611;
    if (temp_r5 == 1)
    {
        *(s16 *)0x04000208 = 0;
        func_08076F30(0);
        *(s16 *)0x04000208 = (s16) temp_r5;
    }
}
