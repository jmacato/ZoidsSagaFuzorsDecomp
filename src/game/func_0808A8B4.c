#include "types.h"

struct Mgr
{
    u8 pad_0[0x58];
    u32 *objs[1];
};

extern struct Mgr D_0201F5F8;

void func_0808A8B4(u8 i)
{
    u32 *p = D_0201F5F8.objs[i];
    if (p != 0)
        *p &= ~0x20000;
}
