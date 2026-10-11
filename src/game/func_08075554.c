#include "types.h"

extern u16 D_03000B1C[2];
extern u16 D_0300000C;
extern u16 D_0300000E;
extern u8 D_03000088;
extern u8 D_03000089;
extern u8 D_0300008A;
extern u16 D_030057EC;

void func_08079E88(void);
void func_080C8B90(u32);

void func_08075554(void)
{
    u16 keys = ~*(vu16 *)0x04000130;
    u16 prev = D_03000B1C[1];

    D_03000B1C[0] = prev;
    D_03000B1C[1] = D_0300000E;
    D_0300000E = keys & ~D_0300000C & ~prev;
    D_0300000C = keys;
    func_08079E88();
    if (D_03000088 && D_03000089 && (D_0300000C & 0x3FF) == 0x30C && (D_0300000E & 0x30C))
        func_080C8B90(0xFF);
    D_03000089 = D_03000088;
    if (D_0300008A)
        D_0300000C = D_0300000E = D_030057EC = 0;
}
