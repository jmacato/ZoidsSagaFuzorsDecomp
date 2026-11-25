#include "types.h"

struct Pilot
{
    u8 id;
    u8 field_1;
    u8 level;
    u8 flags;
    u32 exp;
    u8 skills[5][2];
    u8 pad12[0x1D];
    s8 growth_rates[5];
    s16 stats[5];
    u8 field_3E;
    u8 growth;
};

extern u32 D_08747168[];
extern u16 D_087472F4[][5];
extern u8 D_08747388[][56][10];
extern u32 (*D_03000010)(void);

void func_080BF93C(struct Pilot *, u8, u8);

void func_080BFD6C(struct Pilot *p)
{
    s16 gain[5];
    u8 i, j;

    p->exp = D_08747168[p->level];
    p->level++;
    if (p->growth <= 3)
    {
        gain[0] = D_087472F4[p->growth][0];
        gain[1] = D_087472F4[p->growth][1];
        gain[2] = D_087472F4[p->growth][2];
        gain[3] = D_087472F4[p->growth][3];
        gain[4] = D_087472F4[p->growth][4];
    }
    else if (p->growth == 4)
    {
        gain[0] = p->growth_rates[0];
        gain[1] = p->growth_rates[1];
        gain[2] = p->growth_rates[2];
        gain[3] = p->growth_rates[3];
        gain[4] = p->growth_rates[4];
    }
    else if (p->growth == 5 || p->growth == 6)
    {
        for (i = 0; i < 5; i++)
            gain[i] = 0;
        for (i = 0; i < 10; i++)
            gain[(D_03000010() * 5) >> 15]++;
    }
    if (p->stats[0] + gain[0] <= 998)
        p->stats[0] += gain[0];
    else
        p->stats[0] = 999;
    if (p->stats[1] + gain[1] <= 998)
        p->stats[1] += gain[1];
    else
        p->stats[1] = 999;
    if (p->stats[2] + gain[2] <= 998)
        p->stats[2] += gain[2];
    else
        p->stats[2] = 999;
    if (p->stats[3] + gain[3] <= 998)
        p->stats[3] += gain[3];
    else
        p->stats[3] = 999;
    if (p->stats[4] + gain[4] <= 998)
        p->stats[4] += gain[4];
    else
        p->stats[4] = 999;
    for (j = 0; j < 56; j++)
    {
        for (i = 0; i < 10; i++)
        {
            if (D_08747388[p->id][j][i] == p->level)
                func_080BF93C(p, j, 1);
        }
    }
}
