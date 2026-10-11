#include "types.h"

struct Entry
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 pad3[0x31];
};

extern struct Entry D_0873FCC8[];

u8 *func_0809A908(u8, u8);

u8 func_080C3CBC(u8 a, u8 b, u8 mask)
{
    u8 *p = func_0809A908(a, b);
    u8 r = 0;
    if (!(mask & D_0873FCC8[*p].field_0))
        r = 1;
    return r;
}
