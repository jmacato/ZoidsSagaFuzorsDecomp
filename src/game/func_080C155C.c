#include "types.h"

struct Slot
{
    u8 id;
    u8 count;
    u8 subs[6];
};

struct List
{
    u8 count;
    u8 pad1[3];
    struct Slot slots[8];
    s16 cost;
    u8 a[3];
    u8 flag;
    u8 b[3];
    u8 ok;
    u8 pad4E[6];
    u32 field_54;
};

struct Info
{
    u8 pad0[8];
    s16 field_8;
};

struct Unit
{
    u8 flags;
    u8 flags2;
    u8 pad2[2];
    u16 field_4;
    u8 pad6[0x26A];
};

struct Data
{
    u8 pad0[0x24C];
    struct Info *info;
    u8 pad250[4];
    u8 count;
    u8 pad255[0x222C - 0x255];
    struct Unit units[1];
};

extern struct List D_02036E24;
extern struct Data D_02031A0C;
extern u32 (*D_03000010)(void);

s32 func_080C269C(u8, u8, u8 *);
void func_080C12A0(void);

void func_080C155C(u8 i, u8 depth)
{
    u8 j;
    s32 r;
    struct Slot *slot;
    for (; i < D_02036E24.count; i++)
    {
        slot = &D_02036E24.slots[i];
        if (depth != 0 && ((D_02031A0C.units[slot->id].flags & 1) || (D_02031A0C.units[slot->id].flags2 & 8)))
            continue;
        r = func_080C269C(depth, slot->id, D_02036E24.b);
        if (r == 0 || r == 3)
            D_02036E24.cost += D_02031A0C.units[slot->id].field_4;
        else
            D_02036E24.cost += D_02031A0C.info->field_8;
        if (D_02036E24.cost <= D_02031A0C.info->field_8)
            D_02036E24.ok = 1;
        else
            D_02036E24.ok = 0;
        for (j = 0; j < slot->count; j++)
        {
            D_02036E24.b[depth] = ((D_03000010() * 3) >> 15) << 6 | slot->subs[j] << 3 | slot->id;
            func_080C12A0();
            D_02036E24.field_54++;
            if (depth + 1 < D_02031A0C.count && !(D_02031A0C.units[slot->id].flags & 1) && !(D_02031A0C.units[slot->id].flags2 & 8))
                func_080C155C(i + 1, depth + 1);
            D_02036E24.b[depth] = 0xFF;
        }
        if (r == 0 || r == 3)
            D_02036E24.cost -= D_02031A0C.units[slot->id].field_4;
        else
            D_02036E24.cost -= D_02031A0C.info->field_8;
    }
}
