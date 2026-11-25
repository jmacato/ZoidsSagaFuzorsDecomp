#include "types.h"

struct Obj
{
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    void *children[16];
    u8 pad_4C[0x40];
    s32 field_8C;
    s32 field_90;
};

void *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
void func_080A38B0(u8);
void func_08077E6C(void *);
s32 func_080C8BAC(s32);

extern s32 D_03000010;

void func_080B0E84(struct Obj *obj)
{
    u8 i;

    if (obj->field_8C == 0)
    {
        obj->children[obj->field_90] = func_080A34A8(obj, 0, 0, obj->field_4 + ((s32)((u32)(func_080C8BAC(D_03000010) * 65) >> 15) - 0x20), obj->field_8 + ((s32)((u32)(func_080C8BAC(D_03000010) * 65) >> 15) - 0x20), 0, 0, 0);
        if (obj->field_90 == 0)
            func_080A38B0(0);
        if (++obj->field_90 == 16)
            obj->field_8C++;
    }
    else
    {
        for (i = 0; i < 16; i++)
        {
            if (obj->children[i] != 0)
                break;
        }
        if (i == 16)
            func_08077E6C(obj);
    }
}
