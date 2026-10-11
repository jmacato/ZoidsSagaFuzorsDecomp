#include "types.h"

struct Save
{
    u8 pad_0[0xE12];
    u8 items[101];
};

extern u8 D_0203116B;
extern struct Save D_02027A10;
extern u8 D_020310A3[][2];

void func_0808A6DC(void)
{
    u8 i;
    D_0203116B = 0;
    for (i = 1; i < 101; i++)
    {
        if (D_02027A10.items[i] != 0)
        {
            D_020310A3[D_0203116B][0] = i;
            D_020310A3[D_0203116B][1] = D_02027A10.items[i];
            D_0203116B++;
        }
    }
}
