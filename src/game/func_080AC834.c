#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    void *child[32];
    u32 state;
    s32 index;
};

extern u32 (*D_03000010)(void);

void *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
void *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080AC834(struct Obj *obj)
{
    u8 i;

    switch (obj->state)
    {
    case 0:
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->x, obj->y, 0x400, 0, 0);
        func_080A38B0(0);
        obj->state++;
        break;
    case 1:
        obj->index++;
        obj->child[obj->index] = func_080A3770(obj, 1, 0,
            obj->x + ((s32)(D_03000010() * 129 >> 15) - 64), obj->y - 15,
            0x400, 0xC0, (D_03000010() * 257 >> 15) + 0x80, 0);
        if (obj->index == 31)
            obj->state++;
        break;
    case 2:
        for (i = 0; i < 32 && obj->child[i] == 0; i++)
            ;
        if (i == 32)
            func_08077E6C(obj);
        break;
    }
}
