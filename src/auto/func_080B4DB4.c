#include "m2c.h"

extern struct { u8 pad_0[0xE86]; u8 f_E86; } D_02009480;
extern struct { u8 pad_0[0x1]; u8 f_1; } D_0201F5F8;

M2C_UNK func_0807C290(M2C_UNK);
M2C_UNK func_080B4D10(s32);
M2C_UNK func_080B4D70();

void func_080B4DB4(void)
{
    func_0807C290(0x0800622C);
    D_02009480.f_E86 = D_0201F5F8.f_1;
    func_080B4D10(0);
    func_080B4D70();
}
