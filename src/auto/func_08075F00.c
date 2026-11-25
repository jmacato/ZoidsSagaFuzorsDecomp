#include "m2c.h"

M2C_UNK func_08075EAC();
M2C_UNK func_080C7628();

void func_08075F00(void)
{
    if (*(u16 *)0x03002352 != 0)
    {
        func_080C7628();
        func_08075EAC();
        *(u16 *)0x03002352 = 0;
    }
}
