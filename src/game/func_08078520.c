#include "types.h"

extern u8 D_0300568C;

u32 func_08078520(void)
{
    if (D_0300568C & 7)
        return 0;
    return 1;
}
