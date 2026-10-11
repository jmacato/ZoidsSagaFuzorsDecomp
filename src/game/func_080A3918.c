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
    struct Child *child[2];
    u8 pad_14[0x78];
    s32 state;
};

void func_080A3578(void *);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A3918(struct Obj *obj)
{
    if (obj->state == 0)
    {
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->x, obj->y, 0x400, 0, 0);
        obj->child[1] = func_080A34A8(obj, 1, 0, obj->x, obj->y, 0x500, func_080A3578, 0);
        obj->child[1]->speed = 16;
        func_080A38B0(0);
        obj->state++;
    }
    else if (obj->child[0] == 0 && obj->child[1] == 0)
        func_08077E6C(obj);
}
