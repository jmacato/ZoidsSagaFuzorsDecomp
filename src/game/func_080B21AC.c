#include "types.h"

struct Obj
{
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    void *field_C;
    u8 pad_10[0x7C];
    u32 field_8C;
    u32 field_90;
};

void *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
void func_080A38B0(u8);
void func_08077E6C(void *);
void func_080771F4(void *);

extern u16 D_03000056;
extern u16 D_03000058;

void func_080B21AC(struct Obj *obj)
{
    switch (obj->field_8C)
    {
    case 0:
        obj->field_C = func_080A34A8(obj, 0, 0, obj->field_4, obj->field_8, 0x720, 0, 0);
        D_03000056 = 0x740;
        D_03000058 = 0x1000;
        func_080A38B0(0);
        obj->field_8C++;
    case 1:
        obj->field_90++;
        D_03000058 = (obj->field_90 >> 3) | 0x1000;
        if (obj->field_90 == 0x80)
        {
            func_080771F4(obj->field_C);
            obj->field_C = func_080A34A8(obj, 1, 0, obj->field_4, obj->field_8, 0x720, 0, 0);
            func_080A38B0(1);
            obj->field_90 = 0;
            obj->field_8C++;
        }
        break;
    case 2:
        obj->field_90++;
        D_03000058 = (16 - (obj->field_90 >> 1)) | 0x1000;
        if (obj->field_90 == 32)
            func_08077E6C(obj);
        break;
    }
}
