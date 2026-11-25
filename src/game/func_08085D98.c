#include "types.h"

struct Slot
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[0x2E];
};

struct Formation
{
    u8 pad_0[4];
    struct Slot slots[6];
};

extern struct Formation D_0875A0C4[][15];
void func_08085B58(u8, u8, u8, u8, u8);
void func_08083C5C(u8, s32, s32);

s32 func_08085D98(u8 id, u8 **pc)
{
    u32 i;
    for (i = 0; i < 6; i++)
    {
        struct Slot *s = &D_0875A0C4[(*pc)[1]][(*pc)[2]].slots[i];
        if (s->field_0 != 0)
            func_08085B58(s->field_0, s->field_1, (*pc)[3], i, (*pc)[4]);
    }
    func_08083C5C(id, -1, 0);
    return 0;
}
