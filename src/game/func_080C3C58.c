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

u8 func_080C3C58(u8 a, u8 b, u8 val)
{
    return D_0873FCC8[*func_0809A908(a, b)].field_2 != val;
}
