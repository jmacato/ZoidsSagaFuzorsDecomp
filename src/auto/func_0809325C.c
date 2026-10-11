#include "m2c.h"

extern struct { u8 pad_0[0x1]; u8 f_1; } D_02020E3C;

M2C_UNK func_0809309C();
M2C_UNK func_080930C0();
M2C_UNK func_0809AA44(s32);
M2C_UNK func_0809F7AC(s32);
M2C_UNK func_0809F9DC(s32);
M2C_UNK func_080A0244(u8);
M2C_UNK func_080A3370();
M2C_UNK func_080C8FCC(s32);

void func_0809325C(void)
{
    func_080A3370();
    func_080C8FCC(1);
    func_080A0244(D_02020E3C.f_1);
    func_0809AA44(0);
    func_0809AA44(1);
    func_0809F9DC(0);
    func_0809F9DC(1);
    func_0809F7AC(0);
    func_0809F7AC(1);
    func_0809309C();
    func_080930C0();
}
