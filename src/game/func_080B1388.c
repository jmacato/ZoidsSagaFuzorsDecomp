#include "types.h"

struct Obj
{
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    u8 pad_C[0x80];
    s32 field_8C;
    s32 field_90;
    s32 field_94;
};

s32 func_080C8BAC(s32);

extern s32 D_03000010;

void func_080B1388(struct Obj *obj)
{
    obj->field_8C = 0;
    obj->field_90 = obj->field_4 + ((u32)(func_080C8BAC(D_03000010) * 65) >> 15) - 0x20;
    obj->field_94 = obj->field_8 + (((u32)(func_080C8BAC(D_03000010) * 33) >> 15) - 0x10);
}
