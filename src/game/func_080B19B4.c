#include "types.h"

struct Obj
{
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    void *children[32];
    u32 field_8C;
    u32 field_90;
    u32 field_94;
};

struct Big
{
    u8 pad_0[0x99];
    u8 field_99;
};

void *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
void func_080A38B0(u8);
void func_08077E6C(void *);
void func_080771F4(void *);
s32 func_080C8BAC(s32);

extern struct Big D_02036E7C;
extern u32 *D_02030B4C[];
extern s32 D_03000010;

void func_080B19B4(struct Obj *obj)
{
    u8 i;

    if (obj->field_8C == 0)
    {
        if (D_02036E7C.field_99 <= 2 && D_02030B4C[D_02036E7C.field_99] != 0)
            obj->field_90 = obj->field_94 = 1;
        func_080A38B0(0);
    }
    if (obj->field_90 != 0)
    {
        if (obj->field_8C == obj->field_90)
        {
            *D_02030B4C[D_02036E7C.field_99] &= ~0x20000;
            obj->field_94++;
            obj->field_90 += obj->field_94;
            if (obj->field_94 == 16)
            {
                func_080771F4(D_02030B4C[D_02036E7C.field_99]);
                D_02030B4C[D_02036E7C.field_99] = 0;
                obj->field_90 = 0;
            }
        }
        else
        {
            *D_02030B4C[D_02036E7C.field_99] |= 0x20000;
        }
    }
    if (obj->field_8C < 16)
    {
        if (!(obj->field_8C & 1))
        {
            obj->children[obj->field_8C >> 1] = func_080A34A8(obj, 0, 0,
                obj->field_4 + ((u32)(func_080C8BAC(D_03000010) * 33) >> 15) - 0x10,
                obj->field_8 + ((u32)(func_080C8BAC(D_03000010) * 33) >> 15) - 0x10,
                0, 0, 0);
        }
    }
    else
    {
        for (i = 0; i < 8; i++)
        {
            if (obj->children[i] != 0)
                break;
        }
        if (i == 8 && obj->field_90 == 0)
            func_08077E6C(obj);
    }
    obj->field_8C++;
}
