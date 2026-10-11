#include "m2c.h"

extern u8 D_0300004C[];
extern u8 D_0300568C[];
extern u8 D_0300569E[];

void func_080784F8(void)
{
    *(s8 *)D_0300568C = 0;
    *(s16 *)D_0300569E = 0;
    *(u16 *)D_0300004C &= 0x9FFF;
}
