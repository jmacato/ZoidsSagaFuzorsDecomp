#include "types.h"

extern u8 D_02020E3C;
extern void *D_087A43E0[];

void *func_080BF554(u8 a, u8 b, u8 c)
{
    if (D_02020E3C == 0 && a == 1 && b == 13 && c == 1)
        return D_087A43E0[0x9A];
    return D_087A43E0[b];
}
