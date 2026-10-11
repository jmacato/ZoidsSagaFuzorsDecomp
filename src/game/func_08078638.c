#include "types.h"

extern u16 D_0300004C;
void func_080784F8(void);

void func_08078638(void)
{
    D_0300004C &= 0xDFFF;
    if (!(D_0300004C & 0x6000))
        func_080784F8();
}
