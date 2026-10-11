#include "types.h"

struct Parent
{
    u32 flags;
    s32 x;
    s32 y;
    void *child[32];
};

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    u8 pad_0C[0x20];
    void (*callback)(void *);
    struct Parent *parent;
    u32 count;
    s32 target;
};

void *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);
u8 func_080A3874(struct Obj *, s32, s32);

void func_080A9D08(struct Obj *obj)
{
    struct Parent *parent = obj->parent;
    s32 x;

    if (!(obj->flags & 0x8000))
        obj->x -= 0x800;
    else
        obj->x += 0x800;
    obj->y += 0x400;
    if (!(obj->count & 1))
    {
        x = obj->x / 256;
        parent->child[obj->count / 2 + 16] = func_080A3770(parent, 1, 0, !(obj->flags & 0x8000) ? x + 16 : x - 16, obj->y / 256 - 8, 0x500, 0x6D, 0x80, 3);
    }
    if (obj->target == 0 ? obj->y <= 0x6FFF : !func_080A3874(obj, obj->target - 16, obj->y / 256))
        obj->count++;
    else
    {
        obj->flags |= 0x20000;
        obj->callback = 0;
    }
}
