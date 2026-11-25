#include "types.h"

struct Result
{
    u8 pad0[6];
    s16 field_6;
};

struct Stats
{
    u8 flags;
    u8 pad1[0x17];
};

struct Target
{
    u8 active;
    u8 pad1;
    s16 weight;
    u8 pad4[4];
};

struct Part
{
    u8 pad0[4];
    struct Target t[2][6];
};

struct Unit
{
    struct Stats stats;
    struct Part parts[6];
};

struct Obj
{
    u8 pad0[6];
    s16 hp;
};

struct Info
{
    u8 pad0[8];
    s16 field_8;
    u8 padA[0x5C];
    s16 field_66;
};

struct Data
{
    u8 pad0[0x244];
    u8 index;
    u8 mode;
    u8 pad246[6];
    struct Info *info;
    u8 pad250[0x222C - 0x250];
    struct Unit units[8];
};

struct List
{
    u8 pad0[0x44];
    s16 cost;
    u8 a[3];
    u8 flag;
    u8 b[3];
    u8 ok;
    u8 pad4E[2];
    s32 best;
};

extern struct Result D_02031408;
extern struct Stats D_02031410;
extern struct Data D_02031A0C;
extern struct List D_02036E24;

struct Obj *func_0809A908(u8, u8);
u8 func_0809B834(u8, u8, u8, struct Result *);
void func_080C280C(u8, u8, u8 *, struct Stats *);
void func_080C08F0(u8, u8, u8, u8, u8, struct Stats *, s16 *);

void func_080C12A0(void)
{
    s32 score = 0;
    s16 out[2];
    s16 hp, shield;
    u8 g, u, k, slot, part;
    struct Target *t;
    struct Unit *unit;
    s32 x, y;
    u32 q;

    for (g = 0; g < 2; g++)
    {
        for (u = 0; u < 6; u++)
        {
            hp = func_0809A908(g, u)->hp;
            if (func_0809B834(g, u, 0x23, &D_02031408) == 0xFF)
                D_02031408.field_6 = 0;
            shield = D_02031408.field_6;
            for (k = 0; k < 3 && D_02036E24.b[k] != 0xFF; k++)
            {
                slot = D_02036E24.b[k] & 7;
                part = (D_02036E24.b[k] >> 3) & 7;
                unit = &D_02031A0C.units[slot];
                t = &unit->parts[part].t[g][u];
                if (t->active == 0)
                    continue;
                if (unit->stats.flags & 1)
                    continue;
                if (hp <= 0)
                    continue;
                D_02031410 = unit->stats;
                func_080C280C(k, slot, D_02036E24.b, &D_02031410);
                func_080C08F0(D_02031A0C.index, D_02031A0C.mode, g, u, shield > 0 ? 0 : 0xFF, &D_02031410, out);
                if (shield > 0 && shield < out[0])
                    out[0] = shield;
                if (g != D_02031A0C.index)
                {
                    if (shield > 0 || hp > out[0])
                        score += out[0] * t->weight;
                    else
                    {
                        score += hp * t->weight;
                        score += 10000 * t->weight;
                    }
                }
                else
                {
                    if (shield > 0 || hp > out[0])
                        score -= out[0] * t->weight;
                    else
                    {
                        score -= hp * 100 * t->weight;
                        score -= 10000 * t->weight;
                    }
                }
                if (shield <= 0)
                    hp -= out[0];
                else
                    shield -= out[0];
            }
        }
    }
    if (D_02036E24.ok == 0)
    {
        x = D_02036E24.cost - D_02031A0C.info->field_8;
        y = D_02031A0C.info->field_66;
        q = x / y;
        if (x % y)
            q++;
        score = (u32)score / (q + 1);
    }
    if (score > D_02036E24.best)
    {
        for (k = 0; k < 3; k++)
            D_02036E24.a[k] = D_02036E24.b[k];
        D_02036E24.flag = D_02036E24.ok;
        D_02036E24.best = score;
    }
}
