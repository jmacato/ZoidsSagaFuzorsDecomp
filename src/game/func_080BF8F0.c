#include "types.h"

struct Entry
{
    u8 field_0;
    u8 field_1;
    u8 level;
    u8 field_3;
    u32 exp;
    u8 pad8[0x38];
};

extern struct Entry D_02027A10[];
extern u32 D_08747168[];

u8 func_080BF8F0(u8 id, u32 add)
{
    struct Entry *e = &D_02027A10[id];
    u32 v = e->exp + add;
    if (v <= 999999998)
        e->exp = v;
    else
        e->exp = 999999999;
    if (e->level <= 98 && e->exp >= D_08747168[e->level])
        return 1;
    return 0;
}
