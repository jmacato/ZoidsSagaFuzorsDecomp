#include "types.h"

void func_0808653C(u16);
void func_08083C5C(u8, s32, s32);

s32 func_08086598(u8 id, u8 **pc)
{
    func_0808653C(((*pc)[2] << 8) | (*pc)[1]);
    func_08083C5C(id, -1, 0);
    return 0;
}
