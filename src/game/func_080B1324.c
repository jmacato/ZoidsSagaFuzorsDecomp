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
    struct Child *field_C;
    u8 pad_10[0x7C];
    s32 field_8C;
};

struct Child *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, s32, s32);
void func_080A38B0(u8);
void func_08077E6C(void *);

void func_080B1324(struct Obj *obj)
{
    if (obj->field_8C == 0)
    {
        obj->field_C = func_080A34A8(obj, 0, 0, obj->field_4, obj->field_8, 0x400, 0, 0);
        func_080A38B0(0);
        obj->field_8C++;
    }
    else if (obj->field_8C == 1)
    {
        if (obj->field_C->field_1A == 0x1A)
        {
            func_080A38B0(1);
            obj->field_8C++;
        }
    }
    else if (obj->field_C == 0)
    {
        func_08077E6C(obj);
    }
}
