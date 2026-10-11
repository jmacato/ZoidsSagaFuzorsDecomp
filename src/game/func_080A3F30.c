#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    void *child[10];
    u8 pad_34[0x58];
    u32 count;
};

void *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A3F30(struct Obj *obj)
{
    u8 i;

    if (obj->count < 8)
    {
        obj->child[obj->count] = func_080A34A8(obj, 0, 0, obj->x - obj->count * 32 - 8, obj->y, 0x500, 0, 0);
        if (obj->count == 0)
        {
            obj->child[8] = func_080A34A8(obj, 0, 1, obj->x, obj->y, 0x500, 0, 0);
            obj->child[9] = func_080A34A8(obj, 1, 0, obj->x, obj->y, 0x400, 0, 0);
            func_080A38B0(0);
        }
        obj->count++;
    }
    else
    {
        for (i = 0; i < 10 && obj->child[i] == 0; i++)
            ;
        if (i == 10)
            func_08077E6C(obj);
    }
}
