#include "m2c.h"

s32 func_080A34A8(u8 *, s32, s32, s16, s32, s32, s32, s32);

void func_080A38CC(u8 *arg0)
{
    M2C_FIELD(arg0, s32 *, 0xC) = func_080A34A8(arg0, 0, 0, M2C_FIELD(arg0, s16 *, 4), (s32) M2C_FIELD(arg0, s16 *, 8), 0x400, 0, 0);
}
