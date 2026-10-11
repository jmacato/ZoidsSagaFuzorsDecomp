#include "types.h"

extern u8 D_08741C44[][10];

u8 func_080BD304(u8 id)
{
    u8 i, j;
    u8 *p;
    for (i = 0; D_08741C44[i][0] != 0; i++)
    {
        for (p = D_08741C44[i], j = 0; j < 5 && *p != 0; p += 2, j++)
        {
            if (*p == id && p[1] == 1)
                return j;
        }
    }
    return 0;
}
