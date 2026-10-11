#include "types.h"

struct Data
{
    u8 a[2][9];
    u8 b[2][6];
};

extern struct Data D_02036849;

void func_080BEB10(void)
{
    u8 i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 9; j++)
            D_02036849.a[i][j] |= 0xFF;
        for (j = 0; j < 6; j++)
            D_02036849.b[i][j] |= 0xFF;
    }
}
