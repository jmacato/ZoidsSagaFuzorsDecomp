#include "m2c.h"

extern struct { u8 pad_0[0x10EC]; s32 f_10EC; s32 f_10F0; } D_0201F6DC;

M2C_UNK func_080771F4();

void func_08083490(void)
{
    if (D_0201F6DC.f_10EC != 0)
    {
        func_080771F4();
        D_0201F6DC.f_10EC = 0;
        if (D_0201F6DC.f_10F0 != 0)
        {
            func_080771F4();
            D_0201F6DC.f_10F0 = 0;
        }
    }
}
