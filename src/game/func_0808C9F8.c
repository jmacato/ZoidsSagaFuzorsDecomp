#include "types.h"

struct Pair
{
    void *a;
    void *b;
};

struct State
{
    u8 pad_0[0x64];
    struct Pair pairs[4];
};

extern struct State D_0201F5F8;
void func_080771F4(void *);
void func_0808C9D0(void);

void func_0808C9F8(void)
{
    u8 i;

    for (i = 0; i < 4; i++)
    {
        if (D_0201F5F8.pairs[i].a != 0)
            func_080771F4(D_0201F5F8.pairs[i].a);
        if (D_0201F5F8.pairs[i].b != 0)
            func_080771F4(D_0201F5F8.pairs[i].b);
    }
    func_0808C9D0();
}
