#include "types.h"

struct Save
{
    u8 pad_0[0xE08];
    u8 counts[10];
};

extern u8 D_02030F90;
extern struct Save D_02027A10;
extern u8 D_02030F7E[][2];

void func_0808A3A0(void)
{
    u8 i;
    D_02030F90 = 0;
    for (i = 1; i < 10; i++)
    {
        if (D_02027A10.counts[i] != 0)
        {
            D_02030F7E[D_02030F90][0] = i;
            D_02030F7E[D_02030F90][1] = D_02027A10.counts[i];
            D_02030F90++;
        }
    }
}
