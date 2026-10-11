#include "m2c.h"

M2C_UNK func_08077E6C(u8 *);

void func_080A38FC(u8 *arg0)
{
    if (M2C_FIELD(arg0, s32 *, 0xC) == 0)
    {
        func_08077E6C(arg0);
    }
}
