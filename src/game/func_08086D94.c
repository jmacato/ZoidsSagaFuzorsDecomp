#include "types.h"

struct Script
{
    u8 pad_0[0x12AC];
    u32 *objs[16];
};

extern struct Script D_0201F6DC;
void func_08077204(u32 *, u8);
void func_08083C5C(u8, s32, s32);

s32 func_08086D94(u8 id, u8 **pc)
{
    u32 *obj = D_0201F6DC.objs[(*pc)[1]];
    func_08077204(obj, (*pc)[2]);
    *obj &= ~0x30;
    switch ((*pc)[3])
    {
    case 1:
        *obj |= 0x20;
        break;
    case 2:
        *obj |= 0x10;
        break;
    case 0:
        break;
    }
    func_08083C5C(id, -1, 0);
    return 0;
}
