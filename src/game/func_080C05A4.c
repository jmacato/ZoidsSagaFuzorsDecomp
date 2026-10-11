#include "types.h"

struct Stats
{
    u8 flags;
    u8 pad1[3];
    s16 field_4;
    u8 pad6[6];
    s16 attack;
    s16 hit;
    u8 pad10[2];
    s16 field_12;
};

struct Effect
{
    u8 type;
    u8 pad1[5];
    u16 value;
};

struct Unit
{
    u8 id;
    u8 list[4];
    u8 pad5[3];
    struct Effect effects[32];
    u8 pad108[0];
};

struct Group
{
    struct Unit units[7];
};

struct Item
{
    u8 data[0x94];
};

struct Cell
{
    u8 field_0;
    u8 pad1[2];
    u8 flags;
    u8 pad4[0x3A];
    u8 skill;
    u8 pad3F;
};

struct Data
{
    u8 pad0[0x258];
    struct Group groups[2];
    struct Item items[2][11];
    struct Cell cells[2][7];
    u8 pad2100[0x4E6F - 0x2100];
    u8 types[3];
    u16 bonus[2][8];
};

struct Skill
{
    u8 pad0[8];
    s16 value;
    u8 padA[2];
};

extern struct Data D_02031A0C;
extern struct Cell D_0203378C[][7];
extern struct Skill D_0874731C[];

void func_080C0178(struct Item *, struct Cell *, u8, u8, struct Stats *);
u8 func_0808A8DC(struct Item *);
s16 func_080BFADC(struct Cell *, u8);
s32 func_080BD2F4(s32, s32);
void func_080C00A8(struct Stats *, struct Item *);
void func_080C0100(struct Stats *);

void func_080C05A4(u8 g, u8 u, u8 cell, u8 slot, struct Stats *s)
{
    struct Unit *unit = &D_02031A0C.groups[g].units[u];
    struct Item *item = &D_02031A0C.items[g][unit->id];
    struct Cell *pilot;
    struct Effect *e;
    u16 v;
    s16 r;
    u8 i, other;
    s16 sum;

    if (cell != 0xFF)
        pilot = &D_02031A0C.cells[g][cell];
    else
        pilot = 0;
    func_080C0178(item, pilot, slot, 1, s);
    if (pilot != 0 && !(s->flags & 1))
    {
        if (func_0808A8DC(item))
        {
            sum = func_080BFADC(pilot, 0x1D) + 100;
            s->attack = func_080BD2F4(s->attack, sum);
        }
        r = func_080BFADC(pilot, 0x1E);
        v = r;
        if (r)
        {
            if (u <= 2)
                s->hit = func_080BD2F4(s->hit, (s16)v + 100);
            else
                s->hit = func_080BD2F4(s->hit, 100 - (s16)v);
        }
        r = func_080BFADC(pilot, 0x1F);
        v = r;
        if (r)
        {
            if (u > 2)
                s->hit = func_080BD2F4(s->hit, (s16)v + 100);
            else
                s->hit = func_080BD2F4(s->hit, 100 - (s16)v);
        }
    }
    for (i = 0; i < 32; i++)
    {
        e = &unit->effects[i];
        switch (e->type)
        {
        case 0x11:
            if (!(s->flags & 1))
                s->attack += e->value;
            break;
        case 0x12:
            if (!(s->flags & 1))
                s->attack -= e->value;
            break;
        case 0x13:
            if (!(s->flags & 1))
                s->hit += e->value;
            break;
        case 0x14:
            if (!(s->flags & 1))
                s->hit -= e->value;
            break;
        case 0x15:
            if (!(s->flags & 1))
                s->field_12 += e->value;
            break;
        case 0x16:
            if (!(s->flags & 1))
                s->field_12 -= e->value;
            break;
        case 0x1D:
            if (!(s->flags & 1))
                s->attack *= 2;
            break;
        case 0x1E:
            if (!(s->flags & 1))
                s->attack /= 2;
            break;
        case 0x21:
            s->field_4 *= 2;
            break;
        }
    }
    if (!(s->flags & 1))
    {
        sum = 0;
        for (i = 0; i < 4 && unit->list[i] != 0xFF; i++)
        {
            pilot = &D_0203378C[g][unit->list[i]];
            if (pilot->skill != 0 && (pilot->flags & 0x80))
                sum += D_0874731C[pilot->skill].value;
        }
        s->attack += func_080BD2F4(s->attack, sum);
        other = g == 0;
        if (D_02031A0C.types[other] == 0x29)
            s->attack -= D_02031A0C.bonus[other][0];
        func_080C00A8(s, item);
    }
    func_080C0100(s);
}
