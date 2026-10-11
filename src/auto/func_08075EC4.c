#include "m2c.h"

M2C_UNK func_08075E94();

void func_08075EC4(void)
{
    if (*(u16 *)0x03002350 != 0)
    {
        func_08075E94();
        *(u16 *)0x03002350 = 0;
    }
}
