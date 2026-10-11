#include "m2c.h"

extern struct { u8 pad_0[0xE86]; u8 f_E86; } D_02009480;
extern struct { u8 pad_0[0x1]; u8 f_1; u8 pad_2[0x52]; s32 f_54; } D_0201F5F8;

s32 func_080771BC(M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32, s32);
M2C_UNK func_0807C290(M2C_UNK);
M2C_UNK func_080B79A8(s32);

void func_080B79E0(void)
{
    func_0807C290(0x08007088);
    D_02009480.f_E86 = D_0201F5F8.f_1;
    func_080B79A8(0);
    D_0201F5F8.f_54 = func_080771BC(0x080F1FD4, 0x080F2008, 0, 0x80, 0x70, 0x2C2, 0xF, 0x20, 0);
}
