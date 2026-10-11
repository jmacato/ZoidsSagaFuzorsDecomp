#include "types.h"

extern u8 D_0201F960[];
void func_08082F20(u8);
void func_08083C5C(u8, s32, s32);

s32 func_08084B54(u8 id, u8 **pc)
{
    u8 i;
    for (i = 0; i < 0x46; i++)
        D_0201F960[i] = 1;
    func_08082F20((*pc)[1]);
    func_08083C5C(id, -1, 0);
    return 0;
}
