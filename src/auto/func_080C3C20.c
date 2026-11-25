#include "m2c.h"

M2C_UNK func_0809AA44(u8);
M2C_UNK func_0809F7AC(u8);
M2C_UNK func_0809F9DC(u8);
M2C_UNK func_080B3C84();

void func_080C3C20(u8 arg0)
{
    u8 temp_r4;
    u8 var_r5;

    temp_r4 = arg0;
    func_080B3C84();
    func_0809F9DC(temp_r4);
    func_0809F7AC(temp_r4);
    var_r5 = 0;
    if (temp_r4 == 0)
    {
        var_r5 = 1;
    }
    func_0809AA44(var_r5);
    func_0809F9DC(var_r5);
    func_0809F7AC(var_r5);
}
