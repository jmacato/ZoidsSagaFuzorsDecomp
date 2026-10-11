#include "types.h"

struct Save
{
    u8 pad_0[0xD40];
    u8 items[200];
};

extern u16 D_02030F7C;
extern struct Save D_02027A10;
extern u16 D_02030C5C[][2];

void func_0808A340(u32 flag)
{
    u16 i;
    D_02030F7C = 0;
    if (flag & 1)
    {
        D_02030C5C[0][0] = D_02030C5C[0][1] = 0;
        D_02030F7C = 1;
    }
    for (i = 1; i < 200; i++)
    {
        if (D_02027A10.items[i] != 0)
        {
            D_02030C5C[D_02030F7C][0] = i;
            D_02030C5C[D_02030F7C][1] = D_02027A10.items[i];
            D_02030F7C++;
        }
    }
}
