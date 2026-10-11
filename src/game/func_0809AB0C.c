#include "types.h"

struct Zoid
{
    u8 pad_0[0x68];
    s16 field_68;
    s16 field_6A;
};

struct Game
{
    u8 level;
    u8 pad_1[0x4E9D];
    s16 odds;
};

extern struct Game D_02031A0C;
extern u8 D_02020E3C;

s32 func_0809A99C(u8 side, u8 slot);
struct Zoid *func_0809A908(u8 side, u8 slot);

void func_0809AB0C(void)
{
    u8 counts[2];
    s32 totals[2];
    u8 s, u;
    s32 base = 50;
    if (D_02020E3C == 0)
    {
        for (s = 0; s < 2; s++)
        {
            totals[s] = counts[s] = 0;
            for (u = 0; u < 6; u++)
            {
                if (func_0809A99C(s, u))
                {
                    struct Zoid *zoid = func_0809A908(s, u);
                    totals[s] += zoid->field_68 + zoid->field_6A;
                    counts[s]++;
                }
            }
        }
        totals[0] /= counts[0];
        totals[1] /= counts[1];
        D_02031A0C.odds = (totals[0] - totals[1]) / 100 + ((D_02031A0C.level - 1) * 5 + base);
        if (D_02031A0C.odds > 99)
            D_02031A0C.odds = 99;
        else if (D_02031A0C.odds <= 0)
            D_02031A0C.odds = 1;
    }
    else
        D_02031A0C.odds = 100;
}
