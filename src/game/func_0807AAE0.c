#include "types.h"

struct Range
{
    u16 start;
    u8 count;
    u8 pad3[5];
};

extern const struct Range D_0873463C[];

u8 func_0807AAE0(u16 id)
{
    u8 i;

    for (i = 0; i < 24; i++)
    {
        if (D_0873463C[i].start <= id && D_0873463C[i].start + D_0873463C[i].count > id)
            return i;
    }
    return 0xFF;
}
