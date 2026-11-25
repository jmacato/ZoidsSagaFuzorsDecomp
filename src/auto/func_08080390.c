#include "m2c.h"

void func_08080390(s32 arg0, s32 arg1, s32 arg2)
{
    *(s8 *)0x03000AC5 = 0;
    *(s32 *)0x03005800 = arg0;
    *(s32 *)0x03005808 = arg1;
    *(s8 *)0x03005810 = 1;
    *(s32 *)0x030057F8 = arg2;
}
