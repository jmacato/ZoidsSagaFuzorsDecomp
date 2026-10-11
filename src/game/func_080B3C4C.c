#include "types.h"

extern u32 *D_02037CF4[];

s32 func_080B3C4C(void)
{
    s32 done = 1;
    u8 i;

    for (i = 0; i < 6; i++)
    {
        if (D_02037CF4[i] != 0)
        {
            if (*D_02037CF4[i] & 1)
                done = 0;
            else
                D_02037CF4[i] = 0;
        }
    }
    return done;
}
