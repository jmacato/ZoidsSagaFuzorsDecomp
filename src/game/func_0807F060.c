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

void func_0807EF5C(u8);
void func_0807EE04(u8);

void func_0807F060(void)
{
    u8 i;

    for (i = 1; i < 53; i++)
    {
        if ((D_02027A10 + i)->active != 0 && ((D_02027A10 + i)->flags & 4))
            func_0807EF5C(i);
    }
    for (i = 1; i < 186; i++)
    {
        if ((D_02020E88 + i)->species != 0 && ((D_02020E88 + i)->flags & 0x20))
            func_0807EE04(i);
    }
}
