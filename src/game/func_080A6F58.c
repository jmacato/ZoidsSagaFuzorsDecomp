#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    void *child[32];
    u32 count;
    s32 started;
    u32 index;
};

extern u32 (*D_03000010)(void);

s16 func_08075AAC(s16);
void *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A6F58(struct Obj *obj)
{
    u8 amp;
    u8 i;

    if (obj->count < 8)
    {
        obj->child[obj->count] = func_080A34A8(obj, 0, 1, obj->count << 5, obj->y, 0x500, 0, 1);
        if (obj->count == 0)
            func_080A38B0(0);
        if (obj->started == 0 && obj->count * 32 - 32 > obj->x)
        {
            func_080A12B0(6, 0);
            func_080A38B0(1);
            obj->started = 1;
        }
        obj->count++;
    }
    if (obj->started != 0 && obj->index < 16)
    {
        amp = func_08075AAC(obj->index * 128 / 15) / 16;
        obj->child[obj->index + 8] = func_080A34A8(obj, 1, 0, obj->x + obj->index * 4 - 32,
            obj->y + (obj->index & 3) * amp / 3 - amp / 2 + ((s32)(D_03000010() * 9 >> 15) - 4), 0, 0, 0);
        obj->index++;
    }
    if (obj->index == 16)
    {
        for (i = 0; i < 24 && obj->child[i] == 0; i++)
            ;
        if (i == 24)
            func_08077E6C(obj);
    }
}
