#include "types.h"

extern void *D_02030B58[5];
void func_080771F4(void *);
void func_0808BB28(void);

void func_0808BB48(void)
{
    u8 i;
    for (i = 0; i < 5; i++)
    {
        if (D_02030B58[i] != 0)
            func_080771F4(D_02030B58[i]);
    }
    func_0808BB28();
}
