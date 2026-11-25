#include "m2c.h"

extern struct { u8 pad_0[0x5C]; s32 f_5C; s32 f_60; s32 f_64; s8 f_68; s8 f_69; } D_020209D8;

M2C_UNK func_080882A0();
M2C_UNK func_080C8FCC(s32);

void func_0808832C(void)
{
    D_020209D8.f_64 = 0;
    D_020209D8.f_60 = 0;
    D_020209D8.f_5C = 0;
    D_020209D8.f_69 = 0;
    D_020209D8.f_68 = 0;
loop_1:
    func_080882A0();
    func_080C8FCC(1);
    goto loop_1;
}
