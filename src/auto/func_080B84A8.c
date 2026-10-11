#include "m2c.h"

extern struct { u8 pad_0[0x7C]; s32 f_7C; u8 pad_80[0x1]; u8 f_81; } D_02030A40;

M2C_UNK func_0807B748(s32, s32, s32, u8, s32);

void func_080B84A8(void)
{
    func_0807B748(D_02030A40.f_7C, 0, 7, D_02030A40.f_81, 0);
}
