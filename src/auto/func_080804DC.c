#include "m2c.h"

extern struct { s8 f_0; } D_03000AC4;
extern struct { s32 f_0; } D_030057FC;
extern struct { s32 f_0; } D_03005804;
extern struct { s32 f_0; } D_0300580C;
extern struct { s8 f_0; } D_03005811;

void func_080804DC(s32 arg0, s32 arg1, s32 arg2)
{
    D_03000AC4.f_0 = 1;
    D_03005804.f_0 = arg0;
    D_0300580C.f_0 = arg1;
    D_03005811.f_0 = 1;
    D_030057FC.f_0 = arg2;
}
