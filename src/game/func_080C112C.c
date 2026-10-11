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
    s16 field_44;
};

struct Info
{
    u8 pad0[8];
    s16 field_8;
};

struct Unit
{
    u16 flags;
    u8 pad2[2];
    s16 field_4;
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

void func_080C10CC(void);
void func_080C180C(void);
u8 func_080C18B8(void);
void func_080C1A78(u8, u8);
void func_080C19AC(void);

void func_080C112C(void)
{
    u8 i;
    func_080C10CC();
    func_080C180C();
    for (i = 0; i < D_02031A0C.count; i++)
    {
        u8 k;
        struct Unit *unit;
        struct Slot *slot;
        if (!func_080C18B8())
            return;
        k = (D_03000010() * D_02036E24.count) >> 15;
        slot = &D_02036E24.slots[k];
        unit = &D_02031A0C.units[slot->id];
        if (D_02031A0C.info->field_8 < D_02036E24.field_44 + unit->field_4)
            return;
        func_080C1A78(k, (D_03000010() * slot->count) >> 15);
        if (unit->flags & 0x801)
            return;
        if (i == 0)
            func_080C19AC();
    }
}
