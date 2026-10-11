#include "types.h"

u32 func_0809A99C(u8, u8);
void func_0809C284(u8, u8 *);

void func_080933A0(void)
{
    u8 i;
    u8 j;
    u8 buf[6];

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (func_0809A99C(i, j))
                break;
        }
        if (j == 3)
        {
            buf[0] = 3;
            buf[1] = 4;
            buf[2] = 5;
            buf[3] = 0;
            buf[4] = 1;
            buf[5] = 2;
            func_0809C284(i, buf);
        }
    }
}
