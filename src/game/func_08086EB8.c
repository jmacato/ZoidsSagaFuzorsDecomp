#include "types.h"

void func_0808329C(u8);
void func_08082F84(void);
void func_08083C5C(u8, s32, s32);

s32 func_08086EB8(u8 id)
{
    u32 i;
    for (i = 0; i < 16; i++)
        func_0808329C(i);
    func_08082F84();
    func_08083C5C(id, -1, 0);
    return 0;
}
