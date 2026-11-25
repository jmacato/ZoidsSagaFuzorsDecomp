#include "types.h"

struct Entry
{
    u8 id;
    u8 turns;
    u8 damage;
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

struct Game
{
    u8 pad_0[0x258];
    struct Unit units[2][7];
    u8 pad_10C8[0x24E4];
    struct EffectList effects[2][6];
};

extern struct Unit D_02031C64[][7];
extern struct Game D_02031A0C;
extern struct EffectList D_02034FB8[][6];

void func_0809B4D0(u8 side, u8 slot, u8 index);
void func_080BE46C(u8 side, u8 slot);
void func_0809ACCC(u8 side, u8 slot, u8 id);

void func_0809B26C(u8 side, u8 slot, u8 id, u16 value, u8 turns, u8 damage, u8 srcSide, u8 srcSlot, u8 field_5)
{
    struct Unit *unit = &D_02031C64[side][slot];
    struct Entry *e;
    s16 k;
    if (unit->zoid == 0xFF)
        return;
    for (k = 0; k < 32; k++)
    {
        e = &unit->entries[k];
        if (e->id == id && (id == 0x22 || id == 0x24 || id == 0x25 || id == 0x26 || id == 0x23 || id == 0x29 || id == 0x2A))
            break;
    }
    if (k != 32)
        return;
    for (k = 0; k < 32; k++)
    {
        e = &unit->entries[k];
        if ((id == 0x17 || id == 0x2C) && (e->id == 0x17 || e->id == 0x2C))
        {
            func_0809B4D0(side, slot, k);
            k--;
        }
    }
    for (k = 0; k < 32; k++)
    {
        e = &unit->entries[k];
        if (e->id == 0)
        {
            e->id = id;
            e->value = value;
            e->turns = turns;
            e->damage = damage;
            if (srcSide != 0xFF && srcSlot != 0xFF && field_5 != 0xFF)
            {
                e->srcSide = srcSide;
                e->srcZoid = D_02031A0C.units[srcSide][srcSlot].zoid;
                e->field_5 = field_5;
            }
            else
            {
                e->field_5 = 0xFF;
                e->srcZoid = -1;
                e->srcSide = -1;
            }
            func_080BE46C(side, slot);
            if (id == 0x26)
                func_0809ACCC(side, slot, 0xFF);
            if (id != 0x29 && id != 0x2A && id != 0x27 && id != 0x28 && id != 0x21)
            {
                for (k = 0; k < 32; k++)
                {
                    struct Entry *h = &D_02034FB8[side][slot].effects[k];
                    if (h->id == 0)
                    {
                        *h = *e;
                        D_02031A0C.effects[side][slot].flags |= 5;
                        return;
                    }
                }
            }
            return;
        }
    }
}
