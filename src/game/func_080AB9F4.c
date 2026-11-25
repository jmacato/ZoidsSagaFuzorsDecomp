#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    void *child[32];
    s32 state;
};

extern u32 (*D_03000010)(void);

void *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
void *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080AB9F4(struct Obj *obj)
{
    u8 i;

    if (obj->state == 0)
    {
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->x - 128, obj->y, 0, 0, 1);
        for (i = 0; i < 8; i++)
            obj->child[i + 1] = func_080A3770(obj, 1, 0, obj->x, obj->y, 0x500,
                i * 32 / 7 + 0x6C + (D_03000010() * 9 >> 15), (D_03000010() * 513 >> 15) + 0x200, 0);
        func_080A38B0(0);
        obj->state++;
    }
    else
    {
        for (i = 0; i < 9 && obj->child[i] == 0; i++)
            ;
        if (i == 9)
            func_08077E6C(obj);
    }
}
