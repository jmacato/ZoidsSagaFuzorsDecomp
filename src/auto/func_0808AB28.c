#include "m2c.h"

extern struct { u8 pad_0[0x16]; u8 f_16; } D_02009480;
extern struct { u8 pad_0[0x1]; u8 f_1; } D_0201F5F8;
extern struct { u8 pad_0[0x7A5C]; s32 f_7A5C; } D_02020E4C;

M2C_UNK func_0807A1A4();
M2C_UNK func_0807BA24(s32, s32, s32, s32, s32, s32, s32);
M2C_UNK func_0807C290(M2C_UNK);
s32 func_0807F558();
M2C_UNK func_0808A948();
M2C_UNK func_0808AAD4();

void func_0808AB28(void)
{
    func_0808AAD4();
    func_0807C290(0x08000AC9);
    func_0808A948();
    func_0807BA24(func_0807F558(), 9, 0, 0x12, 2, 2, 0);
    func_0807BA24(D_02020E4C.f_7A5C, 9, 0, 0x12, 3, 1, 0);
    func_0807A1A4();
    D_02009480.f_16 = (u8) D_0201F5F8.f_1;
}
