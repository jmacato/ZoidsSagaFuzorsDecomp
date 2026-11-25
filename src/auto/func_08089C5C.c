#include "m2c.h"

extern struct { u8 pad_0[0x4]; s32 f_4; s32 f_8; } D_020209D8;
extern struct { s16 f_0; } D_03000056;
extern struct { s32 f_0; s32 f_4; } D_03000060;

M2C_UNK func_08075E28(s32);

void func_08089C5C(void)
{
    D_020209D8.f_4 = (s32) (D_03000060.f_0 + 0x7800);
    D_020209D8.f_8 = (s32) (D_03000060.f_4 + 0x5000);
    D_03000056.f_0 = 0;
    func_08075E28(3);
    func_08075E28(4);
}
