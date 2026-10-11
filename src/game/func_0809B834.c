#include "types.h"

struct Entry
{
    u8 id;
    u8 field_1;
    u8 pad_2[4];
    u16 value;
};

struct Unit
{
    u8 zoid;
    u8 pad_1[7];
    struct Entry entries[32];
};

extern struct Unit D_02031C64[][7];

void func_080C8B7C(const void *src, void *dst, u32 ctrl);

u8 func_0809B834(u8 side, u8 slot, u8 id, struct Entry *out)
{
    u8 found = 0xFF;
    struct Unit *unit = &D_02031C64[side][slot];
    u8 i;
    if (unit->zoid != 0xFF)
    {
        if (out != 0)
        {
            u32 zero = 0;
            func_080C8B7C(&zero, out, 0x05000002);
        }
        for (i = 0; i < 32; i++)
        {
            struct Entry *e = &unit->entries[i];
            if (e->id == id)
            {
                if (out != 0)
                {
                    out->field_1 = e->field_1;
                    out->value += e->value;
                }
                found = i;
            }
        }
    }
    return found;
}
