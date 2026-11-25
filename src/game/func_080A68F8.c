#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    void *child[32];
    u32 state;
    u32 timer;
};

extern u32 (*D_03000010)(void);

void *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
void *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A68F8(struct Obj *obj)
{
    u8 i;

    switch (obj->state)
    {
    case 0:
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->x, obj->y, 0x400, 0, 0);
        func_080A38B0(0);
        obj->timer = 0;
        obj->state++;
    case 1:
        if (obj->timer < 0x58)
        {
            if ((obj->timer & 3) == 0)
                func_080A3770(obj, 1, 0, obj->x, obj->y + (obj->timer % 6 + (D_03000010() >> 14) - 2), 0x400, 0x80, 0xC0, 0);
            obj->timer++;
            break;
        }
        obj->timer = 0;
        obj->state++;
    case 2:
        if (obj->child[0] != 0)
            break;
        if (obj->timer < 30)
        {
            obj->timer++;
            break;
        }
        func_080A38B0(1);
        obj->timer = 0;
        obj->state++;
    case 3:
        if (obj->timer < 8)
        {
            obj->child[obj->timer] = func_080A34A8(obj, 3, obj->timer != 0, obj->x - obj->timer * 32, obj->y, 0x400, 0, 0);
            if (obj->timer == 0)
                obj->child[8] = func_080A34A8(obj, 2, 0, obj->x, obj->y, 0x400, 0, 0);
            obj->timer++;
            break;
        }
        obj->state++;
    case 4:
        for (i = 0; i < 9 && obj->child[i] == 0; i++)
            ;
        if (i == 9)
            func_08077E6C(obj);
        break;
    }
}
