#include "types.h"

struct Stats
{
    u8 pad0[4];
    u16 field_4;
    u8 pad6[6];
    s16 field_C;
};

struct Info
{
    u8 pad0[8];
    u16 field_8;
};

struct Data
{
    u8 pad0[0x244];
    u8 index;
    u8 pad245[7];
    struct Info *info;
    u8 pad250[0x4E72 - 0x250];
    u16 bonus[1][8];
};

extern struct Data D_02031A0C;

s32 func_080C269C(u8, u8, void *);

s32 func_080C280C(u8 a, u8 b, void *c, struct Stats *stats)
{
    s32 r = func_080C269C(a, b, c);
    if (r != 0)
    {
        stats->field_C += D_02031A0C.bonus[D_02031A0C.index][0];
        if (r != 3)
            stats->field_4 = D_02031A0C.info->field_8;
        if (stats->field_C < 0)
            stats->field_C = 0;
        else if (stats->field_C > 9999)
            stats->field_C = 9999;
    }
    return r;
}
