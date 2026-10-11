#include "types.h"

void func_08086454(u16);
void func_08083C5C(u8, s32, s32);

s32 func_080864D8(u8 id, u8 **pc)
{
    func_08086454(((*pc)[2] << 8) | (*pc)[1]);
    func_08083C5C(id, -1, 0);
    return 0;
}
