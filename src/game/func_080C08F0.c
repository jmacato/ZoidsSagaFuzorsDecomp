#include "types.h"

struct Stats
{
    u8 flags;
    u8 mask;
    u16 flags2;
    u8 pad4[8];
    s16 field_C;
    u8 padE[2];
    s16 field_10;
};

struct Slot
{
    u16 field_0;
    u16 item;
};

struct Obj
{
    u8 pad0[0x6C];
    s16 field_6C;
    u8 pad6E[6];
    struct Slot slots[8];
};

struct Item
{
    u32 active:1;
    u32 pad:7;
    u32 mask:8;
    u32 type:16;
    u8 pad4[8];
    s16 value;
    u8 padE[0xA];
};

struct Battle
{
    u8 pad0[0x4E6F];
    u8 field_4E6F[2];
};

extern struct Battle D_02031A0C;
extern struct Item D_08741EF4[];

struct Obj *func_0809A908(u8, u8);
s32 func_080C08B0(s32, s32);

void func_080C08F0(u8 a, u8 b, u8 c, u8 d, u8 e, struct Stats *stats, s16 *out)
{
    struct Obj *obj;
    s16 total;
    u8 i;
    func_0809A908(a, b);
    obj = func_0809A908(c, d);
    if (stats->flags & 1)
        return;
    out[1] = (out[0] = stats->field_C) + stats->field_10;
    if (e != 0xFF && !(stats->flags2 & 2))
        total = 0;
    else
    {
        total = obj->field_6C;
        for (i = 0; i < 8; i++)
        {
            if (i < 4 && (D_02031A0C.field_4E6F[0] == 0x3A || D_02031A0C.field_4E6F[1] == 0x3A))
                continue;
            if (obj->slots[i].item != 0)
            {
                struct Item *item = &D_08741EF4[obj->slots[i].item];
                if (item->active && item->type == 1 && (item->mask & stats->mask))
                    total += item->value;
            }
        }
    }
    out[0] = func_080C08B0(out[0], total);
    out[1] = func_080C08B0(out[1], total);
    if (out[0] <= 0)
        out[0] = 1;
    else if (out[0] > 9999)
        out[0] = 9999;
    if (out[1] <= 0)
        out[1] = 1;
    else if (out[1] > 9999)
        out[1] = 9999;
}
