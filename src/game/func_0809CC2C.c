#include "types.h"

struct Row
{
    u8 a[6];
    u8 b[6];
};

extern struct Row D_020369E0[];

void func_0809CC2C(void)
{
    u8 i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 6; j++)
        {
            u8 t = D_020369E0[i].a[j];
            D_020369E0[i].a[j] = D_020369E0[i].b[j];
            D_020369E0[i].b[j] = t;
        }
    }
}
