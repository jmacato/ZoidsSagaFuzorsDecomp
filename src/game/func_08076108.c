#include "types.h"

struct Link
{
    u8 active;
    u8 pad1[5];
    u8 field_6;
};

extern struct Link D_030024B8;

void func_08076108(void)
{
    *(vu16 *)0x04000208 = 0;
    *(vu16 *)0x04000200 &= 0xFF3F;
    *(vu16 *)0x04000208 = 1;
    *(vu16 *)0x04000128 = 0x2003;
    *(vu32 *)0x0400010C = 0xABFB;
    *(vu16 *)0x04000202 = 0xC0;
    D_030024B8.field_6 = 0;
}
