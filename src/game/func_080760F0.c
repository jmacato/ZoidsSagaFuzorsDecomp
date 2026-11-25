#include "types.h"

struct Unk030024B8
{
    u8 active;
    u8 pad1[5];
    u8 field_6;
};

extern struct Unk030024B8 D_030024B8;

void func_080760F0(void)
{
    if (D_030024B8.active != 0)
        D_030024B8.field_6 = 1;
}
