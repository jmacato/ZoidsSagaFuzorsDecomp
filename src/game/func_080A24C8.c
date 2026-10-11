#include "types.h"

struct State
{
    u8 pad_0[0x8CC];
    u8 field_8CC;
};

extern struct State D_02036E7C;
extern u16 D_0300004C;

void func_080A24C8(void)
{
    D_0300004C &= ~0x200;
    D_02036E7C.field_8CC = 0;
}
