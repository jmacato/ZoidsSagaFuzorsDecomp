#include "types.h"

#define REG_IME (*(vu16 *)0x04000208)

extern u16 D_03007FF8;
extern u8 D_0300068D;
extern u8 D_0300068C;

void func_08075298(void)
{
    REG_IME = 0;
    D_03007FF8 = 1;
    REG_IME = 1;
    D_0300068D++;
    D_0300068C = 0;
}
