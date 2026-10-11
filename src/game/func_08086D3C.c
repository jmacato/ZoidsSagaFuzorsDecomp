#include "types.h"

void func_080830F4(u8, u8, u8, s16, s16, u8, u8);
void func_08083C5C(u8, s32, s32);

s32 func_08086D3C(u8 id, u8 **pc)
{
    u8 *p = *pc;
    func_080830F4(p[1], p[2], p[3], (p[5] << 8) | p[4], (p[7] << 8) | p[6], p[8], 3);
    func_08083C5C(id, -1, 0);
    return 0;
}
