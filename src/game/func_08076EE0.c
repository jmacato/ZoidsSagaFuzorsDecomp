#include "types.h"

void func_08075470(void);

extern void (*D_03000000[3])(void);

void func_08076EE0(u8 id, void (*func)(void))
{
    if (D_03000000[0] == func_08075470 && D_03000000[1] == func_08075470 && D_03000000[2] == func_08075470)
    {
        *(vu16 *)0x04000200 |= 2;
        *(vu16 *)0x04000004 |= 0x10;
    }
    D_03000000[id] = func;
}
