#include "types.h"

struct Child
{
    u8 pad_0[0x1A];
    u16 field_1A;
};

struct Obj
{
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    struct Child *children[32];
    u32 field_8C;
    u32 field_90;
};

struct Child *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
struct Child *func_080A3770(struct Obj *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_080A38B0(u8);
void func_080A12B0(s32, s32);
void func_08077E6C(void *);
s32 func_080C8BAC(s32);

extern s32 D_03000010;

void func_080AECFC(struct Obj *obj)
{
    u8 i;

    switch (obj->field_8C)
    {
    case 0:
        obj->children[0] = func_080A34A8(obj, 0, 1, obj->field_4 - 0x80, obj->field_8, 0x600, 0, 1);
        obj->field_8C++;
        break;
    case 1:
        if (obj->children[0]->field_1A == 4)
        {
            obj->children[1] = func_080A34A8(obj, 1, 0, obj->field_4, obj->field_8, 0x400, 0, 0);
            obj->field_8C++;
        }
        break;
    case 2:
        if (obj->children[0]->field_1A == 5)
        {
            func_080A12B0(6, 0);
            func_080A38B0(0);
            obj->field_8C++;
        }
        break;
    case 3:
        if (obj->children[0]->field_1A <= 0x15)
        {
            if (!(obj->field_90 & 3))
            {
                func_080A3770(obj, 2, 0, obj->field_4, obj->field_8 - 4, 0x500,
                    ((u32)(func_080C8BAC(D_03000010) * 33) >> 15) + 0x80,
                    ((u32)(func_080C8BAC(D_03000010) * 257) >> 15) + 0x100, 0);
                func_080A3770(obj, 2, 0, obj->field_4, obj->field_8 + 4, 0x500,
                    ((u32)(func_080C8BAC(D_03000010) * 33) >> 15) + 0x60,
                    ((u32)(func_080C8BAC(D_03000010) * 257) >> 15) + 0x100, 0);
            }
            obj->field_90++;
        }
        for (i = 0; i < 11; i++)
        {
            if (obj->children[i] != 0)
                break;
        }
        if (i == 11)
            func_08077E6C(obj);
        break;
    }
}
