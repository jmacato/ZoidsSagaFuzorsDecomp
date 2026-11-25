#include "types.h"

extern u32 D_0200C524[32];
extern u32 D_0201F5B8;

u8 func_0807AA58(u8 count, u16 *out)
{
    u8 found = 0;
    u8 i, j;
    u32 bits;

    for (i = 0; i < 32; i++)
    {
        bits = D_0200C524[i];
        for (j = 0; j < 32; j++)
        {
            if (!(bits & 1))
            {
                *out = i * 32 + j;
                if (*out >= D_0201F5B8)
                    return 0;
                found++;
                if (found == count)
                    return 1;
                out++;
            }
            bits >>= 1;
        }
    }
}
