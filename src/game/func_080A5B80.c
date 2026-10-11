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
    struct Child *child[32];
    u32 count;
};

extern u32 (*D_03000010)(void);

void func_080A3578(void *);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
struct Child *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A5B80(struct Obj *obj)
{
    u8 i;

    if (obj->count < 8)
    {
        if (obj->count == 0)
        {
            obj->child[0] = func_080A34A8(obj, 1, 0, obj->x, obj->y, 0x10, func_080A3578, 0);
            obj->child[0]->speed = 32;
            for (i = 0; i < 6; i++)
                obj->child[i + 9] = func_080A3770(obj, 2, 0, obj->x, obj->y, 0x400, i * 4 - 10, (D_03000010() * 65 >> 15) + 0xC0, 0);
            func_080A38B0(0);
            func_080A12B0(5, 0);
        }
        obj->child[obj->count + 1] = func_080A34A8(obj, 0, 0, obj->x - obj->count * 32, obj->y, 0x400, 0, 0);
        obj->count++;
    }
    else
    {
        for (i = 0; i < 15 && obj->child[i] == 0; i++)
            ;
        if (i == 15)
            func_08077E6C(obj);
    }
}
