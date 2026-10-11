#include "m2c.h"

M2C_UNK func_080C8BB4(s32, s32, s32);

void func_080759CC(u8 *arg0)
{
    s32 temp_r1;

    temp_r1 = M2C_FIELD(arg0, s32 *, 4);
    func_080C8BB4(temp_r1, temp_r1, M2C_FIELD(arg0, s32 *, 0));
}
