#include "types.h"

struct Obj
{
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    void *field_C;
    void *field_10;
    u8 pad_14[0x78];
    u32 field_8C;
};

void *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
void func_080A38B0(u8);
void func_08077E6C(void *);

void func_080B1FF8(struct Obj *obj)
{
    if (obj->field_8C < 16)
    {
        if (obj->field_8C == 0)
        {
            obj->field_C = func_080A34A8(obj, 0, 0, obj->field_4, obj->field_8, 0, 0, 1);
            func_080A38B0(0);
        }
        else if (obj->field_8C == 15)
        {
            obj->field_C = func_080A34A8(obj, 0, 0, obj->field_4 + 0x20, obj->field_8, 0x10000, 0, 1);
            func_080A38B0(0);
        }
        obj->field_8C++;
    }
    else if (obj->field_C == 0 && obj->field_10 == 0)
    {
        func_08077E6C(obj);
    }
}
