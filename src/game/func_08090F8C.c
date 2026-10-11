#include "types.h"

struct Item
{
    u8 id;
    u8 pad_1;
    u8 field_2;
    u8 pad_3;
    u16 flags;
};

struct ItemInfo
{
    u8 pad_0[2];
    u8 type;
    u8 pad_3[0x31];
};

extern const struct ItemInfo D_0873FCC8[];
extern const u8 D_0800376B[];
extern const u8 D_080037B7[];
extern const u8 D_080037F7[];
extern const u8 D_08003861[];
extern const u8 D_080038AF[];
void func_08075F20(u32);
void func_0807C290(const u8 *);
u8 func_080C8DC8(u8, u32);

u32 func_08090F8C(struct Item *item, s32 mode, u8 slot, u8 force)
{
    if (force == 0 && item->field_2 == 0)
    {
        func_08075F20(0x114);
        func_0807C290(D_0800376B);
        return 0;
    }
    if (item->flags & 2)
    {
        func_08075F20(0x114);
        func_0807C290(D_080037B7);
        return 0;
    }
    switch (mode)
    {
    case 1:
        if (D_0873FCC8[item->id].type != 0)
        {
            func_08075F20(0x114);
            func_0807C290(D_080037F7);
            return 0;
        }
        break;
    case 2:
        if (D_0873FCC8[item->id].type == 4)
        {
            func_08075F20(0x114);
            if (func_080C8DC8(slot, 3) != 1)
                func_0807C290(D_08003861);
            else
                func_0807C290(D_080038AF);
            return 0;
        }
        break;
    }
    return 1;
}
