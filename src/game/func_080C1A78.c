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
    u16 field_44;
};

struct Unit
{
    u8 pad0[4];
    u16 field_4;
    u8 pad6[0x26A];
};

struct Entry
{
    u8 active;
    u8 sub[3];
};

struct Data
{
    u8 pad0[0x244];
    u8 index;
    u8 pad245[0x222C - 0x245];
    struct Unit units[16];
    u8 pad[0x4F84 - 0x222C - 0x270 * 16];
    struct Entry entries[1];
};

extern struct List D_02036E24;
extern struct Data D_02031A0C;
extern u32 (*D_03000010)(void);

void func_080C18C8(u8, u8);

void func_080C1A78(u8 index, u8 sub)
{
    struct Slot *slot = &D_02036E24.slots[index];
    u8 i;
    D_02031A0C.entries[D_02031A0C.index].active = 0;
    for (i = 0; i < 3; i++)
    {
        if (D_02031A0C.entries[D_02031A0C.index].sub[i] == 0xFF)
        {
            D_02031A0C.entries[D_02031A0C.index].sub[i] = ((D_03000010() * 3) >> 15) << 6 | slot->subs[sub] << 3 | slot->id;
            D_02036E24.field_44 += D_02031A0C.units[slot->id].field_4;
            func_080C18C8(index, 0xFF);
            break;
        }
    }
}
