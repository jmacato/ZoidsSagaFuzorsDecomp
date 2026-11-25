#include "types.h"

struct Script
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[2];
    u32 pc;
    u8 pad_8[0x114];
    u32 pcs[0x46];
    u16 field_234;
};

extern struct Script D_0201F6DC;
extern u32 D_087347BC[];
void func_08083788(u8);
void func_08075DA8(s32, void (*)(u8));

void func_08083BBC(u32 n)
{
    D_0201F6DC.field_234 = n;
    D_0201F6DC.pc = D_0201F6DC.pcs[0] = D_087347BC[n];
    func_08075DA8(6, func_08083788);
}
