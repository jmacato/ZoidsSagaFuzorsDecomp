#include "types.h"

extern u16 D_0201F9A8[][32][4];

void func_0808148C(u8 id)
{
    u8 i, j;
    for (i = 0; i < 31; i++)
    {
        for (j = 0; j < 4; j++)
            D_0201F9A8[id][i][j] = D_0201F9A8[id][i + 1][j];
        if (D_0201F9A8[id][i + 1][0] == 0)
            break;
    }
}
