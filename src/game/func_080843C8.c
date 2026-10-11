#include "types.h"

struct Script
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[2];
    u32 pc;
    u8 pad_8[0x114];
    u32 pcs[1];
};

extern struct Script D_0201F6DC;
void func_08083BF4(void);

s32 func_080843C8(u8 id, u32 *pc)
{
    if (D_0201F6DC.field_1 == 0)
    {
        func_08083BF4();
        *pc = D_0201F6DC.pcs[id];
        D_0201F6DC.field_0 = 0;
        return 0;
    }
    return 1;
}
