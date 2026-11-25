#include "types.h"

struct Obj
{
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    void *field_C;
    u8 pad_10[0x7C];
    s32 field_8C;
    u32 field_90;
};

void *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
void func_080A38B0(u8);
void func_08077E6C(void *);

extern u16 D_03000056;
extern u16 D_03000058;

void func_080B2098(struct Obj *obj)
{
    if (obj->field_8C == 0)
    {
        obj->field_C = func_080A34A8(obj, 0, 0, obj->field_4, obj->field_8, 0x720, 0, 0);
        D_03000056 = 0x740;
        D_03000058 = 0x1010;
        func_080A38B0(0);
        obj->field_8C++;
    }
    else
    {
        obj->field_90++;
        D_03000058 = (16 - (obj->field_90 >> 1)) | 0x1000;
        if (obj->field_90 == 32)
            func_08077E6C(obj);
    }
}
