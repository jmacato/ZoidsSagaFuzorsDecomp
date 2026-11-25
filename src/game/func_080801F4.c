#include "types.h"

extern u32 D_03000B14;
extern u8 D_03005812;
extern u8 D_03000081;
extern u8 D_030057F5;

u32 func_080801F4(u8 count)
{
    if ((D_03000B14 & 0x3F0F) == 0x303)
    {
        D_03005812 = 0;
        D_03000081 = D_030057F5;
        return 1;
    }
    if (count != 0)
        D_03005812++;
    if (D_03005812 < 60)
        return 0;
    return 2;
}
