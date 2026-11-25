#include "m2c.h"

extern struct { u8 pad_0[0x1]; u8 f_1; u8 pad_2[0x12EE]; s8 f_12F0; u8 pad_12F1[0x3]; s32 f_12F4; s32 f_12F8; } D_0201F6DC;
extern struct { u8 pad_0[0x14]; u16 f_14; u16 f_16; u8 f_18; } D_020209D8;
extern struct { u8 pad_0[0x4]; s32 f_4; } D_02031A0C;
extern struct { s32 f_0; s32 f_4; s32 f_8; s32 f_C; } D_03000060;
extern struct { u8 pad_0[0x18]; s32 f_18; } D_030025A8;

M2C_UNK func_08075F4C(s32);
M2C_UNK func_08083C5C(u8, s32, s32);

s32 func_080857D4(u8 arg0)
{
    s32 temp_r0;
    s32 temp_r1_2;
    s32 temp_r3;
    s32 var_r0;
    u8 temp_r1;

    D_0201F6DC.f_12F0 = 0;
    if (D_0201F6DC.f_1 == 0)
    {
        temp_r3 = D_03000060.f_0 - D_0201F6DC.f_12F4;
        D_03000060.f_0 = temp_r3;
        D_03000060.f_4 = (s32) (D_03000060.f_4 - D_0201F6DC.f_12F8);
        temp_r1 = D_020209D8.f_18;
        if ((temp_r1 == 0) && (D_02031A0C.f_4 != 0))
        {
            if (temp_r3 < 0)
            {
                D_03000060.f_0 = (s32) temp_r1;
            }
            else
            {
                temp_r0 = (D_020209D8.f_14 << 0xB) + 0xFFFF1000;
                if (temp_r3 > temp_r0)
                {
                    D_03000060.f_0 = temp_r0;
                }
            }
            temp_r1_2 = D_03000060.f_4;
            if (temp_r1_2 < 0)
            {
                var_r0 = 0;
                goto block_10;
            }
            var_r0 = (D_020209D8.f_16 << 0xB) + 0xFFFF6000;
            if (temp_r1_2 > var_r0)
            {
block_10:
                D_03000060.f_4 = var_r0;
            }
            D_03000060.f_8 = (s32) D_03000060.f_0;
            D_03000060.f_C = (s32) D_03000060.f_4;
        }
    }
    else
    {
        D_030025A8.f_18 = 0x58;
    }
    func_08075F4C(0xD4);
    func_08083C5C(arg0, -1, 0);
    return 0;
}
