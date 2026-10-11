#include "types.h"

struct Slot
{
    u8 flags;
    u8 pad_1[0x17];
};

extern struct Slot D_02037B6C[][6];

void func_0809F4F4(void)
{
    u8 i, j;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 6; j++)
            D_02037B6C[i][j].flags = 0;
}
