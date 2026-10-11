#include "types.h"

extern u8 D_02030504[];
void func_080C8B7C(const void *, void *, u32);

void func_0807EC08(void)
{
    u32 zero = 0;
    func_080C8B7C(&zero, D_02030504, 0x05000010);
}
