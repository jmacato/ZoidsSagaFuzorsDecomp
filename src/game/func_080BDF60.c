#include "types.h"

extern u8 D_08741C44[][5][2];
extern u8 D_0203124A[5];
extern u8 D_0203124F;
extern u8 D_02031250;

void func_080BDF60(u8 *obj)
{
    u8 i, j;
    for (i = 0; D_08741C44[i][0][0] != 0; i++)
    {
        u8 (*row)[2];
        D_02031250 = 0;
        row = D_08741C44[i];
        for (j = 0; j < 5 && row[j][0] != 0; j++)
        {
            if (row[j][0] == obj[0])
            {
                D_02031250 = row[j][1];
                break;
            }
        }
        if (D_02031250 != 0)
        {
            D_0203124F = 0;
            for (j = 0; j < 5 && (*row)[0] != 0; row++, j++)
            {
                if (D_02031250 != 1 || ((obj[3] >> j) & 1))
                {
                    D_0203124A[D_0203124F] = (*row)[0];
                    D_0203124F++;
                }
            }
            if (D_0203124F != 0)
                return;
        }
    }
    D_02031250 = 0;
    D_0203124F = 0;
}
