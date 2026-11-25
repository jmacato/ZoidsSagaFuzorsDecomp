#include "types.h"

struct Child
{
    u32 flags;
    u8 pad_04[0x2C];
    void *parent;
    u32 count;
};

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    struct Child *child[32];
    s32 state;
};

extern u32 (*D_03000010)(void);

void func_080A9B14(void *);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
struct Child *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A9DFC(struct Obj *obj)
{
    u8 i;

    if (obj->state == 0)
    {
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->x, obj->y, 0x20, func_080A9B14, 0);
        for (i = 0; i < 4; i++)
            obj->child[i + 1] = func_080A3770(obj, 2, 0,
                obj->x + ((s32)(D_03000010() * 5 >> 15) - 2),
                obj->y + ((s32)(D_03000010() * 5 >> 15) - 2),
                0x400, D_03000010() * 17 >> 15, (D_03000010() * 65 >> 15) + 0x40, 0);
        obj->child[0]->parent = obj;
        obj->child[0]->count = 0;
        func_080A38B0(0);
        obj->state++;
    }
    else if (obj->child[0]->flags & 0x20000)
    {
        for (i = 1; i < obj->child[0]->count / 2 + 6 && obj->child[i] == 0; i++)
            ;
        if (i == obj->child[0]->count / 2 + 6)
            func_08077E6C(obj);
    }
}
