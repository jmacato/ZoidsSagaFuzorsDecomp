#include "types.h"

struct Pair
{
    s32 a;
    s32 b;
};

extern struct Pair D_0201F65C[];

void func_0808C9D0(void)
{
    u8 i;

    for (i = 0; i < 4; i++)
    {
        D_0201F65C[i].a = D_0201F65C[i].b = 0;
    }
}
