#include "types.h"

struct Entry
{
    u8 id;
    u8 field_1;
    u8 field_2;
    u8 srcSide;
    u8 srcZoid;
    u8 field_5;
    u16 value;
};

struct Unit
{
    u8 zoid;
    u8 pad_1[7];
    struct Entry entries[32];
};

struct Game
{
    u8 pad_0[0x258];
    struct Unit units[2][7];
};

struct Result
{
    u8 pad_0[4];
    s16 field_4;
};

extern struct Unit D_02031C64[][7];
extern struct Game D_02031A0C;
extern struct Result D_02031410;

s32 func_0809A99C(u8 side, u8 slot);
void func_080C05A4(u8 side, u8 slot, u8 a, u8 b, struct Result *out);

void func_0809B8B4(void)
{
    u8 s, u, j;
    s16 k;
    for (s = 0; s < 2; s++)
    {
        for (u = 0; u < 6; u++)
        {
            if (func_0809A99C(s, u))
            {
                struct Unit *unit = &D_02031C64[s][u];
                for (k = 0; k < 32; k++)
                {
                    if (unit->entries[k].id != 0 && unit->entries[k].field_2 != 0 && unit->entries[k].srcSide != 0xFF && unit->entries[k].srcZoid != 0xFF && unit->entries[k].field_5 != 0xFF)
                    {
                        for (j = 0; j < 6; j++)
                        {
                            if (D_02031A0C.units[unit->entries[k].srcSide][j].zoid == unit->entries[k].srcZoid)
                                break;
                        }
                        func_080C05A4(unit->entries[k].srcSide, j, 0xFF, unit->entries[k].field_5, &D_02031410);
                        if (unit->entries[k].field_2 != D_02031410.field_4)
                            unit->entries[k].field_2 = D_02031410.field_4;
                    }
                }
            }
        }
    }
}
