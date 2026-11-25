#include "types.h"

void func_08075FC0(u16);
void func_08083C5C(u8, s32, s32);

s32 func_08085B2C(u8 id, u8 **pc)
{
    func_08075FC0(((*pc)[2] << 8) | (*pc)[1]);
    func_08083C5C(id, -1, 0);
    return 0;
}
