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
    struct Slot slots[1];
};

extern struct List D_02036E24;

u8 func_080C18C8(u8 index, u8 sub)
{
    u8 i;
    if (sub != 0xFF)
    {
        struct Slot *slot = &D_02036E24.slots[index];
        slot->count--;
        if (slot->count != 0)
        {
            for (i = sub; i < slot->count; i++)
                slot->subs[i] = slot->subs[i + 1];
            return 1;
        }
    }
    D_02036E24.count--;
    for (i = index; i < D_02036E24.count; i++)
        D_02036E24.slots[i] = D_02036E24.slots[i + 1];
    return 0;
}
