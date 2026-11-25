#include "types.h"

struct Child
{
    u8 pad_00[0x17];
    u8 field_17;
    u8 pad_18[0x18];
    s32 speed;
};

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    struct Child *child[2];
    u8 pad_14[0x78];
    u32 state;
    s32 field_90;
    s32 field_94;
};

void func_080A3578(void *);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
struct Child *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A3A68(struct Obj *obj)
{
    s32 dist;

    switch (obj->state)
    {
    case 0:
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->field_90 - 256, obj->field_94, 0x500, func_080A3578, 1);
        obj->child[0]->speed = 16;
        func_080A38B0(0);
        obj->state++;
        break;
    case 1:
        if (obj->child[0] == 0)
        {
            obj->child[0] = func_080A34A8(obj, 1, 0, obj->field_90, obj->field_94, 0, 0, 0);
            dist = (obj->field_94 - obj->y) * 2;
            obj->child[1] = func_080A3770(obj, 2, 0, obj->field_90, obj->field_94, 0x500, dist, 0x800, 0);
            obj->child[1]->field_17 = dist;
            func_080A12B0(6, 0);
            func_080A38B0(1);
            obj->state++;
        }
        break;
    case 2:
        if (obj->child[0] == 0 && obj->child[1] == 0)
            func_08077E6C(obj);
        break;
    }
}
