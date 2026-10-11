#include "types.h"

struct Base
{
    u16 stats[5];
    u8 field_A;
    u8 growth;
};

struct Pilot
{
    u8 id;
    u8 field_1;
    u8 level;
    u8 flags;
    u32 exp;
    u8 skills[5][2];
    u8 pad12[0x1C];
    u8 field_2E;
    u8 field_2F;
    u8 field_30;
    u8 field_31;
    u8 field_32;
    u8 field_33;
    s16 stats[5];
    u8 field_3E;
    u8 field_3F;
};

extern struct Base D_08746B14[];
extern u8 D_08747388[][56][10];
extern u32 D_08747168[];
extern s16 D_087472F4[][5];

void func_080BF5C0(struct Pilot *, u8, u8);
void func_080BF93C(struct Pilot *, u8, u8);
u8 func_080BF9B4(struct Pilot *, u8);
void func_080BFA34(struct Pilot *, u8, u8);

void func_080BF608(u8 id, u8 level, struct Pilot *p)
{
    u8 k, i, j;
    struct Base *base = &D_08746B14[id];

    p->id = id;
    p->level = level;
    p->flags = 0;
    for (j = 0; j < 5; j++)
        p->skills[j][0] = 0;
    for (k = 55; k != 0; k--)
    {
        func_080BF5C0(p, k, 0);
        for (j = 0; j < 10; j++)
        {
            if (D_08747388[id][k][j] != 0 && D_08747388[id][k][j] <= level)
            {
                func_080BF93C(p, k, 1);
                if (func_080BF9B4(p, k) < 5)
                    func_080BFA34(p, 0, k);
                else
                {
                    for (i = 0; i < 5; i++)
                    {
                        if (p->skills[i][0] == 0)
                        {
                            func_080BFA34(p, i, k);
                            break;
                        }
                    }
                }
            }
        }
    }
    level--;
    p->exp = D_08747168[level];
    p->stats[0] = level * D_087472F4[base->growth][0] + base->stats[0];
    p->stats[1] = level * D_087472F4[base->growth][1] + base->stats[1];
    p->stats[2] = level * D_087472F4[base->growth][2] + base->stats[2];
    p->stats[3] = level * D_087472F4[base->growth][3] + base->stats[3];
    p->stats[4] = level * D_087472F4[base->growth][4] + base->stats[4];
    p->field_3E = base->field_A;
    p->field_3F = base->growth;
    p->field_2F = p->field_30 = p->field_31 = p->field_32 = p->field_33 = 2;
    p->field_2E = 0;
}
