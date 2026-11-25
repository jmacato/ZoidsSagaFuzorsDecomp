#include "types.h"

struct Child
{
    u8 pad_0[0x30];
    s32 field_30;
};

struct Obj
{
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    struct Child *children[32];
    u32 field_8C;
    s32 field_90;
    s32 field_94;
};

struct Child *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
struct Child *func_080A3770(struct Obj *, s32, u16, s16, s16, s32, s32, s32, s32);
u8 func_080A3874(struct Child *, s32, s32);
void func_080A38B0(u8);
void func_080A12B0(s32, s32);
void func_08077E6C(void *);
void func_080A3578(void);
s16 func_08075AAC(s16);
s32 func_080C8BAC(s32);

extern s32 D_03000010;

void func_080B13D0(struct Obj *obj)
{
    u8 k;
    u8 amp;
    u16 x;
    u16 y;
    u8 i;

    if (obj->field_8C == 0)
    {
        obj->children[0] = func_080A34A8(obj, 0, 0, obj->field_90 - 0x180, obj->field_94, 0x510, func_080A3578, 1);
        obj->children[0]->field_30 = 0x10;
        func_080A38B0(0);
        obj->field_8C++;
    }
    if (obj->field_8C < 8)
    {
        if (obj->field_8C == 1 && func_080A3874(obj->children[0], obj->field_90 - 0x80, obj->field_94))
        {
            func_080A12B0(6, 0);
            func_080A38B0(1);
            obj->field_8C++;
        }
        if (obj->field_8C >= 2)
        {
            k = obj->field_8C - 2;
            amp = func_08075AAC((k << 7) / 5) / 16;
            x = obj->field_90 + k * 8;
            y = obj->field_94 + amp * (u8)(k % 3) / 2 - amp / 2 - 4 + ((u32)(func_080C8BAC(D_03000010) * 9) >> 15);
            obj->children[(k + 1) * 5] = func_080A34A8(obj, 1, 0, x, y, 0, 0, 0);
            for (i = 0; i < 4; i++)
                obj->children[(k + 1) * 5 + i + 1] = func_080A3770(obj, 2, 0, x, y, 0x500,
                    ((u32)(func_080C8BAC(D_03000010) * 65) >> 15) - 0x20,
                    ((u32)(func_080C8BAC(D_03000010) * 257) >> 15) + 0x100, 0);
            obj->field_8C++;
        }
    }
    else
    {
        for (i = 0; i < 31; i++)
        {
            if (obj->children[i] != 0)
                break;
        }
        if (i == 31)
            func_08077E6C(obj);
    }
}
