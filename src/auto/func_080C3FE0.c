#include "m2c.h"

M2C_UNK func_08079544(s32, s32);
M2C_UNK func_0807970C();
M2C_UNK func_08080390(M2C_UNK, s32, M2C_UNK);
u8 func_080803C4();
M2C_UNK func_080804DC(M2C_UNK, s32, M2C_UNK);
u8 func_08080510();
M2C_UNK func_08093228(s32);
M2C_UNK func_0809325C();
M2C_UNK func_08097004();
M2C_UNK func_08098AC0(s32);
M2C_UNK func_0809C9B4();
M2C_UNK func_0809CC2C();
M2C_UNK func_0809D624();
M2C_UNK func_0809D79C();
M2C_UNK func_080C8FCC(s32);

void func_080C3FE0(u8 arg0)
{
    u8 temp_r4;
    u8 temp_r4_2;
    u8 temp_r5;

    temp_r5 = arg0;
    func_0809D79C();
    func_0809C9B4();
    if (*(u8 *)0x02020E3C == 2)
    {
        if (temp_r5 == 0)
        {
            func_08080390(0x020369E0, 0x24, 0x080F5C9C);
            do
            {
                temp_r4 = func_080803C4();
                func_080C8FCC(1);
            } while (temp_r4 == 0);
        }
        else
        {
            func_080804DC(0x020369E0, 0x24, 0x080F5C9C);
            do
            {
                temp_r4_2 = func_08080510();
                func_080C8FCC(1);
            } while (temp_r4_2 == 0);
            func_0809CC2C();
        }
    }
    if (!(2 & *(u16 *)0x02030584))
    {
        func_08079544(2, 0x10);
        func_0807970C();
        func_08093228(1);
        if (temp_r5 == 0)
        {
            func_08079544(9, 0);
        }
        else
        {
            func_08079544(0xA, 0);
        }
        func_0807970C();
        func_08097004();
        func_0809325C();
        func_08079544(1, 0x10);
        func_0807970C();
    }
    else
    {
        func_0809D624();
    }
    func_08098AC0(0);
}
