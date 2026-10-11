#include "types.h"

struct Entry
{
    u32 a;
    u32 b;
};

extern struct Entry D_02000000[2][160];

void func_08078698(void)
{
    u8 i, j;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 160; j++)
        {
            D_02000000[i][j].a = 0;
            D_02000000[i][j].b = 0x00A000A0;
        }
    }
}
