#include "types.h"

struct Slot
{
    u16 field_0;
    u16 id;
};

struct Def
{
    u8 pad_0[0x14];
    struct Slot slots[8];
};

struct Item
{
    u8 data[24];
};

u8 func_080C0008(const struct Item *);

extern const u8 D_08741C44[][10];
extern const struct Def D_0873FCC8[];
extern const struct Item D_08741EF4[];

s32 func_080B611C(u8 *p, u8 slot, u8 idx)
{
    s32 found = 0;
    u8 val = 0;
    u8 i;
    u8 j;
    const u8 *q;

    for (i = 0; D_08741C44[i][0] != 0 && !found; i++)
    {
        q = D_08741C44[i];
        for (j = 0; j < 5 && *q != 0; j++)
        {
            if (j == slot)
                val = *q;
            if (*q == *p)
                found = 1;
            q += 2;
        }
    }
    if (!found)
        val = *p;
    if (D_0873FCC8[val].slots[idx].id != 0)
        return func_080C0008(&D_08741EF4[D_0873FCC8[val].slots[idx].id]) * 1000;
    return 0;
}
