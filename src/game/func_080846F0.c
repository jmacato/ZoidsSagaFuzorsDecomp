#include "types.h"

struct Actor
{
    u8 flags;
    u8 id;
    u8 pad_2[2];
    u32 x;
    u32 y;
};

struct Map
{
    u8 pad_0[0x424];
    struct Actor *current;
};

struct Script
{
    u8 pad_0[0x11C];
    u8 *pcs[0x46];
    u8 pad_234[3];
    u8 field_237[0x46];
};

extern struct Map D_020209D8;
extern struct Script D_0201F6DC;
void func_08083C5C(u8, s32, s32);

s32 func_080846F0(u8 id, u8 **pc)
{
    struct Actor *a = D_020209D8.current;
    u32 x0, y0, x1, y1;
    if (a != 0)
    {
        x0 = ((*pc)[1] | ((*pc)[2] << 8)) << 11;
        y0 = ((*pc)[3] | ((*pc)[4] << 8)) << 11;
        x1 = ((*pc)[5] | ((*pc)[6] << 8)) << 11;
        y1 = ((*pc)[7] | ((*pc)[8] << 8)) << 11;
        if (a->id != 0x8A && a->x >= x0 && a->x <= x1 && a->y >= y0 && a->y <= y1)
        {
            if (D_0201F6DC.field_237[id] != 0)
            {
                D_0201F6DC.field_237[id] = 0;
                func_08083C5C(id, -1, 0);
                while (**pc == 0x18)
                {
                    func_08083C5C(id, -1, 0);
                    func_08083C5C(id, -1, 0);
                }
                return 0;
            }
        }
        else
            D_0201F6DC.field_237[id] = 1;
    }
    func_08083C5C(id, -1, 0);
    if (**pc != 0x18)
    {
        *pc = D_0201F6DC.pcs[id];
        return 1;
    }
    return 0;
}
