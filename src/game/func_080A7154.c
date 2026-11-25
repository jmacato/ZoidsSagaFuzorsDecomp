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
    s32 kind;
};

extern u32 (*D_03000010)(void);

void *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);

void func_080A7154(struct Obj *obj)
{
    s32 check = 0;
    struct Parent *parent = obj->parent;
    s32 kind;
    s32 x;

    if (obj->count < 16)
    {
        if (!(obj->flags & 0x8000))
            obj->x -= obj->count << 7;
        else
            obj->x += obj->count << 7;
        if ((obj->count & 3) == 0)
        {
            parent->child[obj->count / 4 + 1] = func_080A3770(parent, 2, 0,
                obj->x / 256 + ((s32)(D_03000010() * 5 >> 15) - 2),
                obj->y / 256 + ((s32)(D_03000010() * 5 >> 15) - 2),
                0x500, 0, 0x100, 2);
            check = 1;
        }
    }
    else
    {
        if (!(obj->flags & 0x8000))
            obj->x -= 0x1000;
        else
            obj->x += 0x1000;
        if (!(obj->count & 1))
        {
            kind = obj->kind + 1;
            x = obj->x / 256;
            parent->child[(obj->count - 16) / 2 + 5] = func_080A3770(parent, kind, 0, !(obj->flags & 0x8000) ? x + 32 : x - 32, obj->y / 256, 0x500, 0, 0x80, 2);
            check = 1;
        }
    }
    if (check && (!(obj->flags & 0x8000) ? obj->x < 0 : obj->x > 0xEFFF))
    {
        obj->flags |= 0x20000;
        obj->callback = 0;
    }
    else
        obj->count++;
}
