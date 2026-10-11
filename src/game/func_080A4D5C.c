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
};

extern u32 (*D_03000010)(void);

void *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);

void func_080A4D5C(struct Obj *obj)
{
    struct Parent *parent = obj->parent;

    obj->x += !(obj->flags & 0x8000) ? -0x1000 : 0x1000;
    if (!(obj->count & 1))
    {
        parent->child[obj->count / 4 + 24] = func_080A3770(parent, 1, 0,
            obj->x / 256 + ((s32)(D_03000010() * 5 >> 15) - 2),
            obj->y / 256 + ((s32)(D_03000010() * 5 >> 15) - 2),
            0x400, 0x7C, 0x40, 2);
        if (!(obj->flags & 0x8000) ? obj->x < 0 : obj->x > 0xEFFF)
        {
            obj->flags |= 0x20000;
            obj->callback = 0;
            return;
        }
    }
    obj->count++;
}
