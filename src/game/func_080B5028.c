#include "types.h"

struct Slot
{
    u16 field_0;
    u16 id;
};

struct Unit
{
    u8 pad_0[0x74];
    struct Slot slots[4];
};

void func_0807C290(const void *);

extern u8 D_0200C4A2;
extern u8 D_0200C4A0;
extern u8 D_02028750[];
extern u16 D_0200C4C8;
extern const u8 D_080066DE[];
extern const u8 D_08006739[];

s32 func_080B5028(struct Unit *unit)
{
    u8 list[4][2];
    u8 n = 0;
    u8 i;
    u8 j;

    for (i = 0; i < 4; i++)
    {
        if (unit->slots[i].id != 0)
        {
            for (j = 0; j < n; j++)
            {
                if (list[j][0] == unit->slots[i].id)
                {
                    list[j][1]++;
                    break;
                }
            }
            if (j == n)
            {
                list[n][0] = unit->slots[i].id;
                list[n][1] = 1;
                n++;
            }
        }
    }
    if (n != 0)
    {
        func_0807C290(D_080066DE);
        if (D_0200C4A2 != 1 || D_0200C4A0 != 0)
            return 0;
        for (i = 0; i < n; i++)
        {
            if (D_02028750[list[i][0]] + list[i][1] > 99)
            {
                D_0200C4C8 = list[i][0];
                func_0807C290(D_08006739);
                if (D_0200C4A2 == 2 || D_0200C4A0 == 1)
                    break;
            }
        }
        if (i < n)
            return 0;
    }
    return 1;
}
