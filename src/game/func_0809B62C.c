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

extern struct Game D_02031A0C;

s32 func_0809A99C(u8 side, u8 slot);
void func_0809B4D0(u8 side, u8 slot, u8 index);

s32 func_0809B62C(u8 side, u8 slot, u8 kind)
{
    s32 found = 0;
    u8 s, u;
    s16 k;
    for (s = 0; s < 2; s++)
    {
        for (u = 0; u < 6; u++)
        {
            if (func_0809A99C(s, u))
            {
                for (k = 0; k < 32; k++)
                {
                    struct Entry *e = &D_02031A0C.units[s][u].entries[k];
                    if (e->id != 0 && e->srcSide == side && e->srcZoid == D_02031A0C.units[side][slot].zoid && e->field_5 == kind)
                    {
                        func_0809B4D0(s, u, k);
                        k--;
                        found = 1;
                    }
                }
            }
        }
    }
    return found;
}
