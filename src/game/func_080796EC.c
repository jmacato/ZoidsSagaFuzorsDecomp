#include "types.h"

extern u8 D_03005715;
extern u8 D_03005716;

u32 func_080796EC(void)
{
    u32 result = 0;
    if (D_03005716 == D_03005715)
        result = 1;
    return result;
}
