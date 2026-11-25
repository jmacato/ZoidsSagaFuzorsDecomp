#include "types.h"

extern u16 D_02030F7C;
extern u16 D_02030C5C[][2];
extern u8 D_0877C5F0[];
extern u8 D_02028750[];

void func_080B3D4C(u8 idx)
{
    u8 i;

    D_02030F7C = 0;
    for (i = 0; i < 10; i++)
    {
        if (D_0877C5F0[i + idx * 10] != 0)
        {
            D_02030C5C[D_02030F7C][0] = D_0877C5F0[i + idx * 10];
            D_02030C5C[D_02030F7C][1] = D_02028750[D_0877C5F0[i + idx * 10]];
            D_02030F7C++;
        }
    }
}
