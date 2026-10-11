#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    void *child[8];
    u8 pad_2C[0x60];
    u32 count;
};

void *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void), s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A4188(struct Obj *obj)
{
    u8 i;

    if (obj->count < 8)
    {
        obj->child[obj->count] = func_080A34A8(obj, 0, 0, obj->count << 5, obj->y, 0x400, 0, 1);
        if (obj->count == 0)
            func_080A38B0(0);
        obj->count++;
    }
    else
    {
        for (i = 0; i < 8 && obj->child[i] == 0; i++)
            ;
        if (i == 8)
            func_08077E6C(obj);
    }
}
