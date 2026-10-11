#include "types.h"

struct Mgr
{
    u8 pad_0[0x58];
    void *objs[1];
};

extern struct Mgr D_0201F5F8;
void func_080771F4(void *);

void func_0808A86C(u8 i)
{
    if (D_0201F5F8.objs[i] != 0)
    {
        func_080771F4(D_0201F5F8.objs[i]);
        D_0201F5F8.objs[i] = 0;
    }
}
