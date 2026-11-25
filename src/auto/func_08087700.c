#include "m2c.h"

extern struct { u8 pad_0[0x12EC]; s32 f_12EC; } D_0201F6DC;
extern struct { u8 pad_0[0x7B4D]; s8 f_7B4D; } D_02020E4C;

M2C_UNK func_080771F4();
M2C_UNK func_08083C5C(u8, s32, s32);

s32 func_08087700(u8 arg0)
{
    D_02020E4C.f_7B4D = 0;
    if (D_0201F6DC.f_12EC != 0)
    {
        func_080771F4();
        D_0201F6DC.f_12EC = 0;
    }
    func_08083C5C(arg0, -1, 0);
    return 0;
}
