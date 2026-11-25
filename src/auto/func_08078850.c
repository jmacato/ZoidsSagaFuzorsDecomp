#include "m2c.h"

extern u8 D_0300004C[];
extern u8 D_03000080[];
extern u8 D_0300568C[];
extern u8 D_03005698[];
extern u8 D_0300569C[];
extern u8 D_0300569E[];
extern u8 D_030056B4[];
extern u8 D_030056B5[];

M2C_UNK func_08078698();

void func_08078850(s8 arg0, s8 arg1, u8 arg2)
{
    *(s8 *)D_0300568C = arg2 | 5;
    *(u16 *)D_0300004C |= 0x6000;
    *(s8 *)D_030056B4 = arg0;
    *(s8 *)D_030056B5 = arg1;
    *(s16 *)D_03005698 = 0;
    *(s16 *)D_0300569C = 0;
    *(s16 *)D_0300569E = 0x3F;
    func_08078698();
    *(u8 *)D_03000080 |= 2;
}
