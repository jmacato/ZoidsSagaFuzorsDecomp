#include "types.h"

extern u8 D_08741C44[][5][2];

u8 func_080BD3C0(u8 id)
{
    u8 i, j;
    for (i = 0; D_08741C44[i][0][0] != 0; i++)
    {
        u8 (*row)[2] = D_08741C44[i];
        for (j = 0; j < 5 && row[j][0] != 0; j++)
        {
            if (row[j][0] == id && row[j][1] != 1)
                return row[0][0];
        }
    }
    return id;
}
