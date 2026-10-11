#include "types.h"

struct Script
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[2];
    u32 regs[0x46];
    u32 pcs[0x46];
};

extern struct Script D_0201F6DC;
void func_08083C5C(u8, s32, s32);

s32 func_08084318(u8 id, u8 **pc)
{
    u8 n = (*pc)[1];
    u32 i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 0x46 && D_0201F6DC.regs[j] != 0; j++)
            ;
        if (j != 0x46)
            D_0201F6DC.regs[j] = D_0201F6DC.pcs[j] = (*pc)[i * 4 + 2] | ((*pc)[i * 4 + 3] << 8) | ((*pc)[i * 4 + 4] << 16) | ((*pc)[i * 4 + 5] << 24);
    }
    func_08083C5C(id, -1, 0);
    return 0;
}
