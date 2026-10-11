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
    s32 field_90;
};

struct Child *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
struct Child *func_080A3770(struct Obj *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_080A38B0(u8);
void func_080A12B0(s32, s32);
void func_08077E6C(void *);
s32 func_080C8BAC(s32);

extern s32 D_03000010;

void func_080B1B3C(struct Obj *obj)
{
    u8 i;

    switch (obj->field_8C)
    {
    case 0:
        obj->children[0] = func_080A34A8(obj, 0, 0, obj->field_4, obj->field_8, 0, 0, 1);
        func_080A38B0(0);
        obj->field_8C++;
        break;
    case 1:
        if (obj->children[0]->field_1A == 5)
        {
            for (i = 0; i < 8; i++)
                obj->children[i + 1] = func_080A3770(obj, 1, 0, obj->field_4, obj->field_8, 0x500,
                    ((u32)(func_080C8BAC(D_03000010) * 49) >> 15) + 0x80,
                    ((u32)(func_080C8BAC(D_03000010) * 513) >> 15) + 0x200, 0);
            func_080A12B0(6, 0);
            func_080A38B0(1);
            obj->field_8C++;
        }
        break;
    case 2:
        if (obj->field_90 == 15)
        {
            obj->children[9] = func_080A34A8(obj, 0, 0, obj->field_4 + 0x20, obj->field_8, 0x10000, 0, 1);
            func_080A38B0(0);
            obj->field_8C++;
        }
        else
        {
            obj->field_90++;
        }
        break;
    case 3:
        if (obj->children[9]->field_1A == 5)
        {
            for (i = 0; i < 8; i++)
                obj->children[i + 10] = func_080A3770(obj, 1, 0, obj->field_4 + 0x20, obj->field_8, 0x500,
                    ((u32)(func_080C8BAC(D_03000010) * 49) >> 15) + 0x80,
                    ((u32)(func_080C8BAC(D_03000010) * 513) >> 15) + 0x200, 0);
            func_080A12B0(8, 0);
            func_080A38B0(1);
            obj->field_8C++;
        }
        break;
    case 4:
        for (i = 0; i < 18; i++)
        {
            if (obj->children[i] != 0)
                break;
        }
        if (i == 18)
            func_08077E6C(obj);
        break;
    }
}
