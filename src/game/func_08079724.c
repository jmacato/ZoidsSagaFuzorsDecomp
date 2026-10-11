#include "types.h"

extern u8 D_03005714;

u32 func_08079724(void)
{
    u8 mode = D_03005714;

    if (mode == 2 || mode == 4 || mode == 6 || mode == 8 || mode == 11 || mode == 12 || mode == 14 || mode == 18)
        return 1;
    return 0;
}
