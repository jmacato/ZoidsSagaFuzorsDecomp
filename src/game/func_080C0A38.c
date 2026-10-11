#include "types.h"

struct Stats
{
    u8 flags;
    u8 field_1;
    u16 type;
    s16 field_4;
    u8 pad6[8];
    s16 field_E;
    s16 field_10;
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
};

struct Group
{
    struct Unit units[7];
};

struct Data
{
    u8 pad0[0x258];
    struct Group groups[2];
    u8 pad[0x4E6F - 0x258 - 0x738 * 2];
    u8 types[2];
};

struct Obj
{
    u8 field_0;
    u8 pad1[0x69];
    s16 field_6A;
};

struct Template
{
    u8 flags;
    u8 field_1;
    u8 type;
    u8 pad3[0x31];
};

extern struct Data D_02031A0C;
extern struct Template D_0873FCC8[];

struct Obj *func_0809A908(u8, u8);
void *func_0809A954(u8, u8, u8);
u8 func_0809B834(u8, u8, u8, void *);
u8 func_080C1C68(u8, u8);
u8 func_080C005C(u8, u8, u8, u8);
s16 func_080BFADC(void *, u8);
s32 func_080BD2F4(s32, s32);
u16 func_080C8B8C(u32);

void func_080C0A38(u8 ag, u8 au, u8 dg, u8 du, struct Stats *s, s16 *out)
{
    struct Obj *a = func_0809A908(ag, au);
    struct Obj *d = func_0809A908(dg, du);
    struct Effect *e;
    s16 sum;
    u8 i;

    if (!(s->flags & 1))
    {
        if (D_02031A0C.types[dg] == 0x20 && func_080C1C68(dg, 1) != du)
        {
            out[0] = out[1] = 0;
            return;
        }
        out[0] = s->field_E;
        out[1] = s->field_12;
        if (d->field_6A > a->field_6A && func_0809B834(dg, du, 0x26, 0) == 0xFF)
            out[0] -= func_080C8B8C((d->field_6A - a->field_6A) / 10);
        switch (D_0873FCC8[d->field_0].type)
        {
        case 0:
            out[0] -= 10;
            break;
        case 1:
            out[0] -= 5;
            break;
        case 2:
            break;
        case 3:
            out[0] += 15;
            break;
        case 4:
            out[0] += 30;
            break;
        }
        switch (func_080C005C(ag, au, dg, du))
        {
        case 2:
            out[0] -= 5;
            break;
        case 3:
            out[0] -= 15;
            break;
        }
        if (!(D_0873FCC8[a->field_0].flags & 0x80))
        {
            if ((D_0873FCC8[d->field_0].flags & 0x80) && !(s->type & 1) && func_0809B834(ag, au, 0x24, 0) == 0xFF)
                out[0] -= 30;
        }
        else
        {
            if (!(D_0873FCC8[d->field_0].flags & 0x80) && !(s->type & 1) && func_0809B834(ag, au, 0x24, 0) == 0xFF)
                out[0] += 10;
        }
        out[1] = func_080BD2F4(out[1], out[0] < 100 ? 100 : out[0]);
        switch (D_0873FCC8[d->field_0].type)
        {
        case 0:
            out[1] -= 3;
            break;
        case 1:
            out[1] -= 1;
            break;
        case 2:
            break;
        case 3:
            out[1] += 2;
            break;
        case 4:
            out[1] += 5;
            break;
        }
        switch (func_080C005C(ag, au, dg, du))
        {
        case 2:
            out[1] -= 1;
            break;
        case 3:
            out[1] -= 3;
            break;
        }
        if (out[0] <= 0)
            out[0] = 1;
        else if (out[0] > 99)
            out[0] = 99;
        if (out[1] <= 0)
            out[1] = 1;
        else if (out[1] > 99)
            out[1] = 99;
        sum = 0;
        for (i = 0; i < 4 && D_02031A0C.groups[dg].units[du].list[i] != 0xFF; i++)
        {
            sum += func_080BFADC(func_0809A954(dg, du, i), 0x14);
            sum -= func_080BFADC(func_0809A954(dg, du, i), 0x33);
        }
        out[0] -= func_080BD2F4(100 - out[0], sum);
        for (i = 0; i < 32; i++)
        {
            e = &D_02031A0C.groups[dg].units[du].effects[i];
            switch (e->type)
            {
            case 0x17:
            case 0x2C:
                out[0] -= e->value;
                break;
            case 0x18:
                out[0] += e->value;
                break;
            case 0x1F:
                out[0] += out[0] - 100;
                break;
            case 0x20:
                out[0] += (100 - out[0]) / 2;
                break;
            }
        }
        if (out[0] <= 0)
            out[0] = 1;
        else if (out[0] > 99)
            out[0] = 99;
        if (out[1] <= 0)
            out[1] = 1;
        else if (out[1] > 99)
            out[1] = 99;
    }
    else
    {
        out[0] = out[1] = 100;
    }
}
