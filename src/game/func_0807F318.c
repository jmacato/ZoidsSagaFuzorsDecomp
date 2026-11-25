#include "types.h"

extern const u8 D_08741C44[][5][2];
extern u32 D_02030504[];

void func_0807F318(u8 id)
{
    u8 i, j;
    u8 other;

    D_02030504[id >> 5] |= 1 << (id & 0x1F);
    for (i = 0; D_08741C44[i][0][0] != 0; i++)
    {
        for (j = 0; j < 5 && D_08741C44[i][j][0] != 0; j++)
        {
            if (D_08741C44[i][j][0] == id && D_08741C44[i][j][1] != 1)
            {
                for (j = 0; j < 5 && D_08741C44[i][j][0] != 0; j++)
                {
                    other = D_08741C44[i][j][0];
                    if (other != id)
                        D_02030504[other >> 5] |= 1 << (other & 0x1F);
                }
                return;
            }
        }
    }
}
