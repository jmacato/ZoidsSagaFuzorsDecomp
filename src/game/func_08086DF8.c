#include "types.h"

void func_080831FC(u8, s16, s16, u8);
void func_08083C5C(u8, s32, s32);

s32 func_08086DF8(u8 id, u8 **pc)
{
    u8 *p = *pc;
    func_080831FC(p[1], (p[3] << 8) | p[2], (p[5] << 8) | p[4], p[6]);
    func_08083C5C(id, -1, 0);
    return 0;
}
