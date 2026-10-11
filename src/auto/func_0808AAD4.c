#include "m2c.h"

extern struct { u8 pad_0[0x54]; s32 f_54; } D_0201F5F8;

s32 func_080771BC(M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32, s32);
M2C_UNK func_0808A7F8(s32, s32, s32, s32);

void func_0808AAD4(void)
{
    D_0201F5F8.f_54 = func_080771BC(0x080F1FD4, 0x080F2008, 0, 0x90, 0x90, 0x2C2, 0xF, 0x20, 0);
    func_0808A7F8(0, 0, 0xB8, 0x68);
    func_0808A7F8(1, 1, 0xD8, 0x98);
}
