#include "types.h"

struct Entry
{
    u8 id;
    u8 pad_1[7];
};

struct Unit
{
    u8 zoid;
    u8 pad_1[7];
    struct Entry entries[32];
};

extern struct Unit D_02031C64[][7];

void func_0809B4D0(u8 side, u8 slot, u8 index);

void func_0809B5BC(u8 side, u8 slot, u8 id)
{
    struct Unit *unit = &D_02031C64[side][slot];
    s16 i;
    if (unit->zoid != 0xFF)
    {
        for (i = 0; i < 32; i++)
        {
            if (unit->entries[i].id == id)
            {
                func_0809B4D0(side, slot, i);
                i--;
            }
        }
    }
}
