#include "m2c.h"

extern struct { u8 pad_0[0x54]; s32 f_54; } D_0201F5F8;

M2C_UNK func_080771F4();
M2C_UNK func_080B4D48();

void func_080B4D54(void)
{
    if (D_0201F5F8.f_54 != 0)
    {
        func_080771F4();
        func_080B4D48();
    }
}
