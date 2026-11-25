#include "types.h"

struct Cell
{
    u8 flags;
    u8 pad_1[0x17];
};
struct Script
{
    u8 field_0;
    u8 field_1;
};
extern struct Script D_0201F6DC;
extern struct Cell D_02037B6C[][6];
void func_08083C5C(u16, s16, u8);

s32 func_08087948(u8 id, u8 **pc)
{
    D_0201F6DC.field_0 = 1;
    if ((*pc)[3] == 0)
        D_02037B6C[(*pc)[1]][(*pc)[2]].flags |= 0x10;
    else
        D_02037B6C[(*pc)[1]][(*pc)[2]].flags |= 8;
    func_08083C5C(id, -1, 0);
    return 0;
}
