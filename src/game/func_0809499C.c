#include "types.h"

struct Item
{
    u8 field_0;
    u8 field_1;
};

struct Obj
{
    u8 pad_0[0x10];
    s16 field_10;
    s16 field_12;
    u8 pad_14[0x1C];
    struct Item *item;
};

struct Big
{
    u8 pad_0[0x4F38];
    struct Obj *objs[6];
    s8 dir;
    u8 count;
};

extern struct Big D_02031A0C;
extern const u8 D_08424594[];
extern const u8 D_084245A0[];
u32 func_0809A99C(u8, u8);
struct Item *func_0809A908(u8, u8);
u8 func_080C8D50(u8, u32);
u8 func_080C8DC8(u8, u32);
void func_0807FB7C(u8, u8, u16, u8);
struct Obj *func_080771BC(const u8 *, const u8 *, u32, s16, s16, u16, u32, u32, u32);

void func_0809499C(u8 side)
{
    u8 i;
    struct Item *item;
    s16 x;
    s16 y;

    for (i = 0; i < 6; i++)
    {
        if (func_0809A99C(side, i))
        {
            item = func_0809A908(side, i);
            x = ((1 - func_080C8D50(i, 3)) << 5) + 0x18;
            y = ((2 - func_080C8DC8(i, 3)) << 5) + 0x28;
            if (side == 0)
            {
                x = 0x50 - x;
                y = 0x90 - y;
            }
            func_0807FB7C(item->field_0, item->field_1, (i << 6) + 0x180, i + 3);
            D_02031A0C.objs[i] = func_080771BC(D_08424594, D_084245A0, 0, x, y, (i << 6) + 0x180, i + 3, side != 0 ? 0x8148 : 0x148, 0);
            D_02031A0C.objs[i]->field_10 = D_02031A0C.objs[i]->field_12 = 0;
            D_02031A0C.objs[i]->item = item;
        }
        else
        {
            D_02031A0C.objs[i] = 0;
        }
    }
    D_02031A0C.dir = 1;
    D_02031A0C.count = 0;
}
