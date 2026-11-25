#include "types.h"

struct Entry
{
    u8 id;
    u8 field_1;
    u8 field_2;
    u8 srcSide;
    u8 srcZoid;
    u8 field_5;
    u16 value;
};

struct Unit
{
    u8 zoid;
    u8 pad_1[7];
    struct Entry entries[32];
};

struct EffectList
{
    u16 flags;
    u8 pad_2[2];
    struct Entry effects[32];
    struct Entry history[32];
};

struct Battle
{
    struct Unit units[2][7];
    u8 pad_E70[0x24E4];
    struct EffectList effects[2][6];
};

extern struct Battle D_02031C64;

void func_080BE46C(u8 side, u8 slot);

void func_0809B4D0(u8 side, u8 slot, u8 index)
{
    struct Unit *unit = &D_02031C64.units[side][slot];
    struct Entry *e;
    u8 i;
    if (unit->zoid != 0xFF)
    {
        e = &unit->entries[index];
        if (e->id != 0x29 && e->id != 0x27 && e->id != 0x28 && e->id != 0x21)
        {
            for (i = 0; i < 32; i++)
            {
                struct Entry *h = &D_02031C64.effects[side][slot].history[i];
                if (h->id == 0)
                {
                    *h = *e;
                    D_02031C64.effects[side][slot].flags |= 5;
                    break;
                }
            }
        }
        for (i = index; i < 31; i++)
            unit->entries[i] = unit->entries[i + 1];
        unit->entries[i].id = 0;
        func_080BE46C(side, slot);
    }
}
