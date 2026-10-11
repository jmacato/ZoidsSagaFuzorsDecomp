#include "types.h"

struct Range
{
    u8 start;
    u8 count;
    u8 pad2[6];
};

extern const struct Range D_087346FC[];

u8 func_0807ACE4(u8 id)
{
    u8 i;

    for (i = 0; i < 24; i++)
    {
        if (D_087346FC[i].start <= id && D_087346FC[i].start + D_087346FC[i].count > id)
            return i;
    }
    return 0xFF;
}
