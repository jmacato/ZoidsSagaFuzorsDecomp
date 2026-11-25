#include "m2c.h"

M2C_UNK func_08083C5C(u8, s32, s32);

s32 func_080872D0(u8 arg0)
{
    *(s32 *)0x02020E4C |= 4;
    func_08083C5C(arg0, -1, 0);
    return 0;
}
