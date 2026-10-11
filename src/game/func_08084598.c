#include "types.h"

extern u8 D_0201F6DC;
extern u8 D_03000081;
void func_080C8FCC(s32);
void func_08083C5C(u8, s32, s32);

s32 func_08084598(u8 id, u8 **pc)
{
    u16 n, i;
    D_0201F6DC = 1;
    n = ((*pc)[2] << 8) | (*pc)[1];
    for (i = 0; i < n; i += D_03000081)
        func_080C8FCC(1);
    func_08083C5C(id, -1, 0);
    return 0;
}
