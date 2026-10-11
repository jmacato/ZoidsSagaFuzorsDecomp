#include "types.h"

struct Obj
{
    u8 pad_0[0x8C];
    s32 field_8C;
    u32 field_90;
    s32 field_94;
    u8 pad_98[0x10];
    u32 field_A8;
};

s32 func_080C8BAC(s32);

extern s32 D_03000010;

void func_080AF4A4(struct Obj *obj)
{
    obj->field_8C = 0;
    obj->field_90 = obj->field_A8 >> 12;
    if (obj->field_90 == 0 || obj->field_90 == 2)
        obj->field_94 = ((u32)(func_080C8BAC(D_03000010) * 33) >> 15) - 0x10;
    else
        obj->field_94 = (u32)(func_080C8BAC(D_03000010) * 33) >> 15;
    obj->field_A8 &= 0xC0;
}
