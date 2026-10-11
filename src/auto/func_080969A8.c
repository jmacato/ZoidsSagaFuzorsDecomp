#include "m2c.h"

extern struct { u8 pad_0[0x4F77]; u8 f_4F77; } D_02031A0C;
extern struct { u16 f_0; } D_0300000C;

M2C_UNK func_08075DB8(s32, s32, s32);
M2C_UNK func_080C8FCC(s32);

void func_080969A8(s32 arg0, s32 arg1)
{
    D_02031A0C.f_4F77 = 0;
    func_08075DB8(4, arg0, arg1);
    while (!(2 & D_0300000C.f_0) && (D_02031A0C.f_4F77 == 0))
    {
        func_080C8FCC(1);
    }
}
