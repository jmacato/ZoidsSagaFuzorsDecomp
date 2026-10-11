#include "types.h"

extern s32 D_02030AEC[2][6];

void func_080771F4(s32);

void func_080C5E60(void)
{
    u8 i;
    u8 j;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 6; j++)
            func_080771F4(D_02030AEC[i][j]);
    }
}
