#include "types.h"

struct Child
{
    u8 pad_00[0x30];
    s32 speed;
};

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    struct Child *child;
    u8 pad_10[0x7C];
    u32 state;
    s32 field_90;
    s32 field_94;
};

void func_080A3578(void *);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
u8 func_080A3874(struct Child *, s32, s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_080771F4(struct Child *);
void func_08077E6C(struct Obj *);

void func_080A42E0(struct Obj *obj)
{
    switch (obj->state)
    {
    case 0:
        obj->child = func_080A34A8(obj, 0, 0, obj->field_90 - 256, obj->field_94, 0x410, func_080A3578, 1);
        obj->child->speed = 16;
        func_080A38B0(0);
        obj->state++;
        break;
    case 1:
        if (func_080A3874(obj->child, obj->field_90 - 16, obj->field_94))
        {
            func_080771F4(obj->child);
            obj->child = func_080A34A8(obj, 1, 0, obj->field_90, obj->field_94, 0, 0, 0);
            func_080A12B0(6, 0);
            func_080A38B0(1);
            obj->state++;
        }
        break;
    case 2:
        if (obj->child == 0)
            func_08077E6C(obj);
        break;
    }
}
