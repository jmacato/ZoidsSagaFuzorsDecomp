#include "m2c.h"

extern u8 D_030057EE[];
extern u8 D_030057F0[];

void func_08079E70(void)
{
    *(s8 *)D_030057F0 = 0x10;
    *(s16 *)D_030057EE = 0;
}
