#include "types.h"

struct Slot
{
    u16 field_0;
    u16 item;
};

struct Template
{
    u8 pad0[4];
    s16 stats[7];
    u8 pad12[2];
    struct Slot slots[8];
};

struct Obj
{
    u8 id;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u16 field_4;
    s16 field_6;
    s16 field_8;
    s16 mods[4];
    s16 a[5][4];
    s16 b[5][4];
    s16 stats[7];
    u32 rate;
    struct Slot slots[8];
};

extern struct Template D_0873FCC8[];

void func_080BD57C(struct Obj *obj)
{
    struct Template *t = &D_0873FCC8[obj->id];
    u8 i;

    for (i = 0; i < 4; i++)
        obj->slots[i].field_0 = t->slots[i].field_0;
    for (; i < 8; i++)
        obj->slots[i] = t->slots[i];
    obj->stats[0] = t->stats[0];
    obj->stats[1] = t->stats[1];
    obj->stats[2] = t->stats[2];
    obj->stats[3] = t->stats[3];
    obj->stats[4] = t->stats[4];
    obj->stats[5] = t->stats[5];
    obj->stats[6] = t->stats[6];
    if (obj->rate > 1999799)
    {
        obj->stats[2] = obj->stats[1] = obj->stats[0] = 9999;
    }
    else
    {
        if ((obj->rate / 200 + 1) * obj->stats[0] > 9998)
            obj->stats[0] = 9999;
        else
            obj->stats[0] += obj->stats[0] * obj->rate / 200;
        if ((obj->rate / 200 + 1) * obj->stats[1] > 9998)
            obj->stats[1] = 9999;
        else
            obj->stats[1] += obj->stats[1] * obj->rate / 200;
        if ((obj->rate / 200 + 1) * obj->stats[2] > 9998)
            obj->stats[2] = 9999;
        else
            obj->stats[2] += obj->stats[2] * obj->rate / 200;
    }
    if (t->stats[3] + obj->mods[0] <= 0)
        obj->mods[0] -= t->stats[3] + obj->mods[0] - 1;
    if (t->stats[4] + obj->mods[1] <= 0)
        obj->mods[1] -= t->stats[4] + obj->mods[1] - 1;
    if (t->stats[5] + obj->mods[2] <= 0)
        obj->mods[2] -= t->stats[5] + obj->mods[2] - 1;
    if (t->stats[6] + obj->mods[3] <= 0)
        obj->mods[3] -= t->stats[6] + obj->mods[3] - 1;
    obj->stats[3] += obj->mods[0];
    obj->stats[4] += obj->mods[1];
    obj->stats[5] += obj->mods[2];
    obj->stats[6] += obj->mods[3];
}
