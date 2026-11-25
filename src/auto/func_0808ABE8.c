#include "m2c.h"

extern struct { u8 pad_0[0x54]; s32 f_54; } D_0201F5F8;

M2C_UNK func_080771F4(s32);
M2C_UNK func_0808A86C(s32);

void func_0808ABE8(void)
{
    func_080771F4(D_0201F5F8.f_54);
    func_0808A86C(0);
    func_0808A86C(1);
}
