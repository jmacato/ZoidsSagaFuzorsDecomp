#include "m2c.h"

extern struct { u8 pad_0[0x8A4]; u8 f_8A4; } D_02036E7C;
extern struct { s32 f_0; } D_03000060;

M2C_UNK func_08075F20(s32);
M2C_UNK func_08079544(s32, s32);
M2C_UNK func_0807970C();
M2C_UNK func_08086454(M2C_UNK);
M2C_UNK func_080A05BC(s32);
s32 func_080A0B54();
M2C_UNK func_080C8FCC(s32);

void func_08087C40(void)
{
    u32 var_r4;

    D_02036E7C.f_8A4 |= 0x80;
    D_03000060.f_0 = 0x1000;
    func_08079544(9, 0);
    func_0807970C();
    func_08086454(0x155);
    func_08075F20(0xEE);
    func_080A05BC(4);
    while ((func_080A0B54() << 0x18) == 0)
    {
        func_080C8FCC(1);
    }
    var_r4 = 0;
    do
    {
        func_080C8FCC(1);
        var_r4 += 1;
    } while (var_r4 <= 0x3BU);
    func_08079544(0x12, 0);
    func_0807970C();
}
