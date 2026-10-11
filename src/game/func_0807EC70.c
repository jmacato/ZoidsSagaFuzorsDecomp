#include "types.h"

extern u8 D_020309A4[];
void func_080C8B7C(const void *, void *, u32);

void func_0807EC70(void)
{
    u32 zero = 0;
    func_080C8B7C(&zero, D_020309A4, 0x05000001);
}
