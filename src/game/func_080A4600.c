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
    s32 state;
    s32 field_90;
};

void func_080A3578(void *);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A4600(struct Obj *obj)
{
    if (obj->state == 0)
    {
        obj->child = func_080A34A8(obj, 0, 0, obj->x - 16, obj->field_90, 0x410, func_080A3578, 1);
        obj->child->speed = 16;
        func_080A38B0(0);
        obj->state++;
    }
    else if (obj->child == 0)
        func_08077E6C(obj);
}
