#include "types.h"

struct Entry
{
    u8 active;
    u8 pad1[2];
    u8 flags;
    u8 pad4[0x3C];
};

struct Zoid
{
    u8 species;
    u8 pad1[3];
    u16 flags;
    u8 pad6[0x8E];
};

extern struct Entry D_02027A10[];
extern struct Zoid D_02020E88[];

void func_0807EFF0(void)
{
    u8 i;

    for (i = 1; i < 53; i++)
    {
        struct Entry *entry = &D_02027A10[i];
        if (entry->active != 0 && (entry->flags & 4))
            entry->flags &= ~4;
    }
    for (i = 1; i < 186; i++)
    {
        struct Zoid *zoid = &D_02020E88[i];
        if (zoid->species != 0 && (zoid->flags & 0x20))
            zoid->flags &= ~0x20;
    }
}
