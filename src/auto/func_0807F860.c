#include "m2c.h"

M2C_UNK func_080C8B78(u16 *, u16 *, u32);
M2C_UNK func_080C8B84(u8 *, u16 *);
M2C_UNK func_080C8B88(u8 *, u16 *);

void func_0807F860(u8 *arg0, u16 *arg1, u16 *arg2)
{
    if (arg1 == (u16 *)0x05000000)
    {
        func_080C8B88(arg0, arg2);
        *arg2 = *arg1;
        func_080C8B78(arg2, arg1, (u32) ((M2C_FIELD(arg0, u8 *, 1) | (M2C_FIELD(arg0, u8 *, 2) << 8) | (M2C_FIELD(arg0, u8 *, 3) << 0x10)) << 9) >> 0xB);
        return;
    }
    func_080C8B84(arg0, arg1);
}
