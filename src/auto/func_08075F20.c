#include "m2c.h"

M2C_UNK func_080C755C(u16);

void func_08075F20(u16 arg0)
{
    *(u16 *)0x03002354 = arg0;
    func_080C755C(*(u16 *)0x03002354);
}
