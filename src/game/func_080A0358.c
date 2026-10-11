#include "types.h"

extern u8 D_03000080;
extern u8 D_03000081;
extern u8 D_030057F5;

void func_08075E28(u8 id);
void func_080784F8(void);

void func_080A0358(void)
{
    D_03000080 &= ~1;
    D_03000081 = D_030057F5 = 1;
    func_08075E28(3);
    func_080784F8();
}
