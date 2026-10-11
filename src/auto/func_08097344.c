#include "m2c.h"

extern struct { u16 f_0; } D_02030584;
extern struct { u8 pad_0[0x244]; u8 f_244; u8 f_245; u8 f_246; } D_02031A0C;

M2C_UNK func_08075E28(s32);
M2C_UNK func_08079544(s32, s32);
M2C_UNK func_0807970C();
M2C_UNK func_08093228(s32);
M2C_UNK func_0809325C();
M2C_UNK func_080969A8(M2C_UNK, s32);
M2C_UNK func_0809AA44(s32);
M2C_UNK func_0809F784(u8, u8);
M2C_UNK func_0809F7AC(s32);
M2C_UNK func_0809F7CC(u8, u8);
M2C_UNK func_0809F910(u8, u8);
M2C_UNK func_0809F9DC(s32);
M2C_UNK func_080A1204();
M2C_UNK func_080B3A38(u8, s32);
M2C_UNK func_080B3B94(s32, u8, u8, s32);
M2C_UNK func_080B3C84();
M2C_UNK func_080BFFA4(u8, u8, u8);

void func_08097344(void)
{
    s32 var_r4;

    if (!(2 & D_02030584.f_0))
    {
        func_08079544(2, 0x10);
        func_0807970C();
        func_08093228(1);
        if (D_02031A0C.f_244 == 0)
        {
            func_08079544(9, 0);
        }
        else
        {
            func_08079544(0xA, 0);
        }
        func_0807970C();
        func_080969A8(0x080972F9, 0);
        func_08079544(0x12, 0);
        func_0807970C();
        func_08075E28(4);
        func_080A1204();
        func_0809325C();
        func_08079544(1, 0x10);
    }
    func_0809F7CC(D_02031A0C.f_244, D_02031A0C.f_245);
    func_0807970C();
    func_080B3A38(D_02031A0C.f_244, 2);
    func_080B3B94(0x22, D_02031A0C.f_244, D_02031A0C.f_245, 0);
    func_080B3C84();
    var_r4 = 0;
    if (D_02031A0C.f_244 == 0)
    {
        var_r4 = 1;
    }
    func_0809AA44(var_r4);
    func_0809F9DC(var_r4);
    func_0809F7AC(var_r4);
    func_080BFFA4(D_02031A0C.f_244, D_02031A0C.f_245, D_02031A0C.f_246);
    func_0809F910(D_02031A0C.f_244, D_02031A0C.f_245);
    func_0809F784(D_02031A0C.f_244, D_02031A0C.f_245);
}
