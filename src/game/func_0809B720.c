#include "types.h"

struct Entry
{
    u8 field_0;
    u8 pad_1[7];
};

struct Unit
{
    u8 pad_0[8];
    struct Entry entries[32];
};

extern struct Unit D_02031C64[][7];

void func_0809B720(u8 side, u8 slot)
{
    struct Unit *unit = &D_02031C64[side][slot];
    u8 i;
    for (i = 0; i < 32; i++)
        unit->entries[i].field_0 = 0;
}
