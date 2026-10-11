#include "m2c.h"

extern u8 D_02031989[];
extern u8 D_0203198A[];
extern u8 D_03000080[];

void func_0807DBE0(s8 arg0)
{
    *(u8 *)D_03000080 |= 4;
    *(s8 *)D_02031989 = arg0;
    *(s8 *)D_0203198A = 1;
}
