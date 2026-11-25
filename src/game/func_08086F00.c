#include "types.h"

extern u8 D_0201F6DC;
extern u32 D_0873503C[];
void func_080C8BAC(u32);
void func_08083C5C(u8, s32, s32);

s32 func_08086F00(u8 id, u8 **pc)
{
    D_0201F6DC = 1;
    func_080C8BAC(D_0873503C[(*pc)[1]]);
    func_08083C5C(id, -1, 0);
    return 0;
}
