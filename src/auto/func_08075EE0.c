#include "m2c.h"

M2C_UNK func_08075E94();
M2C_UNK func_080C755C(u16);

void func_08075EE0(u16 arg0)
{
    func_08075E94();
    *(u16 *)0x03002352 = arg0;
    func_080C755C(*(u16 *)0x03002352);
}
