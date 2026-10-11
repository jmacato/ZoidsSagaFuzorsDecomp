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
    struct Child *child[9];
    u8 pad_30[0x5C];
    u32 count;
};

void func_080A3578(void *);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A63D0(struct Obj *obj)
{
    u8 i;

    if (obj->count < 8)
    {
        if (obj->count == 0)
        {
            obj->child[0] = func_080A34A8(obj, 1, 0, 0, obj->y, 0x110, func_080A3578, 1);
            obj->child[0]->speed = 32;
            func_080A38B0(0);
        }
        obj->child[obj->count + 1] = func_080A34A8(obj, 0, 0, obj->count << 5, obj->y, 0x400, 0, 1);
        obj->count++;
    }
    else
    {
        for (i = 0; i < 9 && obj->child[i] == 0; i++)
            ;
        if (i == 9)
            func_08077E6C(obj);
    }
}
