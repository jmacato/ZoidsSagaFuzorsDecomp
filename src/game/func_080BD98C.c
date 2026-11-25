#include "types.h"

struct Pilot
{
    u8 id;
    u8 field_1;
    u8 level;
    u8 flags;
    u8 pad4[0x30];
    s16 stats[4];
    u8 pad3C[2];
    u8 skill;
    u8 growth;
};

struct Obj
{
    u8 pad0[0x62];
    s16 stats[7];
};

struct Bonus
{
    u8 pad0[0x34];
    s16 stats[4];
    u8 pad3C[4];
};

struct Skill
{
    u16 values[4];
    u8 pad8[4];
};

extern struct Bonus D_0203137C;
extern struct Skill D_0874731C[];

void func_080C8B7C(const void *, void *, u32);
s16 func_080BFB24(struct Pilot *, struct Obj *);
s32 func_080BD2F4(s32, s32);
s16 func_080BFADC(struct Pilot *, u8);

void func_080BD98C(struct Obj *obj, struct Pilot **cells, u16 level, u8 flag)
{
    u32 zero;
    s16 m1, m2, m3, d;
    u8 i;
    struct Skill *sk;

    if (cells == 0)
        return;
    zero = 0;
    func_080C8B7C(&zero, &D_0203137C, 0x05000010);
    m3 = 0;
    m2 = 0;
    m1 = 0;
    for (i = 0; i < 4 && cells[i] != 0; i++)
    {
        d = func_080BFB24(cells[i], obj) - (s16)(level - 100);
        D_0203137C.stats[0] = D_0203137C.stats[0] + func_080BD2F4(cells[i]->stats[0], d);
        D_0203137C.stats[1] = D_0203137C.stats[1] + func_080BD2F4(cells[i]->stats[1], d);
        D_0203137C.stats[2] = D_0203137C.stats[2] + func_080BD2F4(cells[i]->stats[2], d);
        D_0203137C.stats[3] = D_0203137C.stats[3] + func_080BD2F4(cells[i]->stats[3], d);
        m1 += func_080BFADC(cells[i], 0x1A);
        m2 += func_080BFADC(cells[i], 0x1B);
        m3 += func_080BFADC(cells[i], 0x1C);
        m1 -= func_080BFADC(cells[i], 0x35);
        m2 -= func_080BFADC(cells[i], 0x36);
        m3 -= func_080BFADC(cells[i], 0x37);
        if (flag && cells[i]->skill != 0 && (cells[i]->flags & 0x80))
        {
            sk = &D_0874731C[cells[i]->skill];
            D_0203137C.stats[0] += sk->values[0];
            D_0203137C.stats[1] += sk->values[1];
            D_0203137C.stats[2] += sk->values[2];
            D_0203137C.stats[3] += sk->values[3];
        }
    }
    if (obj->stats[0] * (D_0203137C.stats[0] + 100) < 999900)
        obj->stats[0] = func_080BD2F4(obj->stats[0], D_0203137C.stats[0] + 100);
    else
        obj->stats[0] = 9999;
    if (obj->stats[3] * (D_0203137C.stats[1] + 100) < 999900)
    {
        obj->stats[3] = m1 + func_080BD2F4(obj->stats[3], D_0203137C.stats[1] + 100);
        if (obj->stats[3] <= 0)
            obj->stats[3] = 1;
    }
    else
        obj->stats[3] = 9999;
    if (obj->stats[4] * (D_0203137C.stats[2] + 100) < 999900)
    {
        obj->stats[4] = m2 + func_080BD2F4(obj->stats[4], D_0203137C.stats[2] + 100);
        if (obj->stats[4] <= 0)
            obj->stats[4] = 1;
    }
    else
        obj->stats[4] = 9999;
    if (obj->stats[5] * (D_0203137C.stats[3] + 100) < 999900)
    {
        obj->stats[5] = m3 + func_080BD2F4(obj->stats[5], D_0203137C.stats[3] + 100);
        if (obj->stats[5] <= 0)
            obj->stats[5] = 1;
    }
    else
        obj->stats[5] = 9999;
}
