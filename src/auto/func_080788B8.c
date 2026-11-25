#include "m2c.h"

M2C_UNK func_08078698();

void func_080788B8(s16 arg0, s16 arg1, u8 arg2)
{
    *(s8 *)0x0300568C = arg2 | 6;
    *(u16 *)0x0300004C |= 0x6000;
    *(s8 *)0x0300569A = 0;
    *(s16 *)0x0300569C = arg0;
    *(s16 *)0x0300569E = arg1;
    func_08078698();
    *(u8 *)0x03000080 |= 2;
}
