#include "m2c.h"

extern u8 D_0300004C[];
extern u8 D_03000080[];
extern u8 D_0300568C[];
extern u8 D_0300569C[];
extern u8 D_0300569E[];
extern u8 D_030056B0[];

M2C_UNK func_08078698();

void func_080787A4(s32 arg0, s16 arg1, s16 arg2, u8 arg3)
{
    *(s8 *)D_0300568C = arg3 | 3;
    *(u16 *)D_0300004C |= 0x6000;
    *(s32 *)D_030056B0 = arg0;
    *(s16 *)D_0300569C = arg1;
    *(s16 *)D_0300569E = arg2;
    func_08078698();
    *(u8 *)D_03000080 |= 2;
}
