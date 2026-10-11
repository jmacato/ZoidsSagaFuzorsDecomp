#include "types.h"

extern u8 D_02030F90;
extern u8 D_02030F7E[][2];
extern u8 D_0877C712[];
extern u8 D_02028818[];

void func_080B471C(u8 idx)
{
    u8 i;

    D_02030F90 = 0;
    for (i = 0; i < 9; i++)
    {
        if (D_0877C712[i + idx * 9] != 0)
        {
            D_02030F7E[D_02030F90][0] = D_0877C712[i + idx * 9];
            D_02030F7E[D_02030F90][1] = D_02028818[D_0877C712[i + idx * 9]];
            D_02030F90++;
        }
    }
}
