#include "types.h"

extern void (*D_03000E14[])(u32);
extern u32 D_03000E2C[];
extern u8 D_03000BB0;

void func_08075E28(u8);
void func_080C8FCC(u32);

void func_08075C84(u8 id)
{
    D_03000E14[id - 1](D_03000E2C[id - 1]);
    func_08075E28(D_03000BB0);
    for (;;)
        func_080C8FCC(1);
}
