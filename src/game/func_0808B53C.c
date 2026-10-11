#include "types.h"

struct Entry
{
    u8 flags;
    u8 pad_1[0x33];
};

extern struct Entry D_0873FCC8[];

s32 func_0808B53C(u8 *p)
{
    if (D_0873FCC8[*p].flags & 0x80)
    {
        if (*p == 0x66 || *p == 0x7A || *p == 0x7C || *p == 0x8F || *p == 0x90)
            return -8;
        if (*p == 0x91)
            return -4;
        if (*p != 0x7F)
            return -16;
    }
    return 0;
}
