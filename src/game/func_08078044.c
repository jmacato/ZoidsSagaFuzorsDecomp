#include "types.h"

struct Unk030053CC
{
    u32 field_0;
    u8 pad4[0x28];
};

extern struct Unk030053CC D_030053CC[];

void func_08078044(void)
{
    u8 i;

    for (i = 0; i < 16; i++)
        D_030053CC[i].field_0 = 0;
}
