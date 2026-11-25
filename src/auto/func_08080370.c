#include "m2c.h"

M2C_UNK func_08075E28(s32);
M2C_UNK func_080801D0();

void func_08080370(void)
{
    func_080801D0();
    *(u16 *)0x03000B18 |= 4;
    func_08075E28(6);
}
