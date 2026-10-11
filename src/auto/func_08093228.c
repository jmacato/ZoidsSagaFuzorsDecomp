#include "m2c.h"

extern struct { u8 pad_0[0x244]; u8 f_244; u8 pad_245[0x7]; s32 f_24C; s32 f_250; } D_02031A0C;

M2C_UNK func_08093140(u8, s32, s32, u8);
M2C_UNK func_080A0358();

void func_08093228(u8 arg0)
{
    func_080A0358();
    func_08093140(D_02031A0C.f_244, D_02031A0C.f_24C, D_02031A0C.f_250, arg0);
}
