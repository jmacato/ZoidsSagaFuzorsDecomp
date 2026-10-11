#include "types.h"

struct Stats
{
    u8 flags;
    u8 field_1;
    u16 type;
    s16 field_4;
    u8 pad6[6];
    s16 field_C;
    s16 field_E;
    s16 field_10;
    s16 field_12;
    u8 pad14[4];
};

struct Slot
{
    u16 field_0;
    u16 item;
};

struct Item
{
    u8 field_0;
    u8 pad1[0x11];
    u16 bonus1[5][4];
    u16 bonus2[5][4];
    u8 pad62[0x12];
    struct Slot slots[8];
};

struct Pilot
{
    u8 pad0[0x3C];
    s16 field_3C;
};

struct Data
{
    u8 pad0[0x4E6F];
    u8 types[2];
};

extern struct Data D_02031A0C;
extern struct Stats D_08741EF4[];
extern struct Stats D_02031458;

u8 func_080BD368(u8);
s16 func_080BFADC(struct Pilot *, u8);
s16 func_080BFB24(struct Pilot *, struct Item *);
s32 func_080BD2F4(s32, s32);
void func_080C00A8(struct Stats *, struct Item *);
void func_080C0100(struct Stats *);

void func_080C0178(struct Item *item, struct Pilot *pilot, u8 slot, u8 flag, struct Stats *out)
{
    u8 i;
    s16 rate;
    struct Stats *w;
    struct Stats *s;

    *out = D_08741EF4[item->slots[slot].item];
    if (!(out->flags & 1))
    {
        s = out;
        if (slot > 3)
        {
            u8 j = func_080BD368(item->field_0);
            s->field_C += item->bonus1[j][slot - 4];
            s->field_4 += item->bonus2[j][slot - 4];
        }
        if (pilot != 0)
        {
            s->field_E += func_080BD2F4(s->field_E, func_080BD2F4(pilot->field_3C, func_080BFB24(pilot, item) + 100));
            rate = 100;
            if (s->field_1 & 8)
            {
                rate = func_080BFADC(pilot, 0xF) + 100;
                rate -= func_080BFADC(pilot, 0x2E);
                if (s->field_4 != 0)
                {
                    s->field_4 = func_080BD2F4(s->field_4, 100 - func_080BFADC(pilot, 0x15));
                    if (s->field_4 == 0)
                        s->field_4 = 1;
                }
            }
            else
            {
                if (s->field_4 != 0)
                {
                    s->field_4 = func_080BD2F4(s->field_4, rate - func_080BFADC(pilot, 0x16));
                    if (s->field_4 == 0)
                        s->field_4 = 1;
                }
            }
            if (s->field_1 & 1)
            {
                rate += func_080BFADC(pilot, 0x10);
                rate -= func_080BFADC(pilot, 0x2F);
            }
            if (s->field_1 & 4)
            {
                rate += func_080BFADC(pilot, 0x11);
                rate -= func_080BFADC(pilot, 0x30);
            }
            if (s->field_1 & 2)
            {
                rate += func_080BFADC(pilot, 0x12);
                rate -= func_080BFADC(pilot, 0x31);
            }
            if (s->type & 1)
            {
                rate += func_080BFADC(pilot, 0x13);
                rate -= func_080BFADC(pilot, 0x32);
            }
            s->field_E = func_080BD2F4(s->field_E, rate);
        }
        for (i = 0; i <= 7; i++)
        {
            if (flag != 0 && i <= 3 && (D_02031A0C.types[0] == 0x3A || D_02031A0C.types[1] == 0x3A))
                continue;
            if (item->slots[i].item == 0)
                continue;
            w = &D_08741EF4[item->slots[i].item];
            if (!(w->flags & 1))
                continue;
            if (w->field_10 != 1)
                continue;
            if ((u16)(w->type - 5) > 2)
                continue;
            func_080C0178(item, pilot, i, flag, &D_02031458);
            switch (D_02031458.type)
            {
            case 5:
                s->field_E += D_02031458.field_C;
                break;
            case 6:
                s->field_12 += D_02031458.field_C;
                break;
            case 7:
                s->field_E += D_02031458.field_C;
                s->field_12 += D_02031458.field_E;
                break;
            }
        }
        func_080C00A8(out, item);
    }
    else
    {
        w = out;
        if (pilot != 0)
        {
        if (w->type == 1)
            w->field_C = func_080BD2F4(w->field_C, func_080BFADC(pilot, 0x20) + 100);
        if (w->type == 0x10)
            w->field_C = func_080BD2F4(w->field_C, func_080BFADC(pilot, 0x21) + 100);
        if (w->type == 9 || w->type == 0x13)
            w->field_C = func_080BD2F4(w->field_C, func_080BFADC(pilot, 0x22) + 100);
        if (w->type == 5 || w->type == 7)
            w->field_C = func_080BD2F4(w->field_C, func_080BFADC(pilot, 0x23) + 100);
        if (w->type == 2 || w->type == 4)
            w->field_C = func_080BD2F4(w->field_C, func_080BFADC(pilot, 0x24) + 100);
        if (w->type == 3)
            w->field_C = func_080BD2F4(w->field_C, func_080BFADC(pilot, 0x25) + 100);
        if (w->type == 4)
            w->field_E = func_080BD2F4(w->field_E, func_080BFADC(pilot, 0x25) + 100);
        if (w->type == 0xD || w->type == 0xF)
            w->field_C = func_080BD2F4(w->field_C, func_080BFADC(pilot, 0x26) + 100);
    }
    }
    func_080C0100(out);
}
