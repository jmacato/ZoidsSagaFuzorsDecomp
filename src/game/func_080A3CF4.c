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
    struct Child *child[32];
    u32 state;
    s32 field_90;
    s32 field_94;
};

extern u32 (*D_03000010)(void);

void func_080A3578(void *);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
struct Child *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A3CF4(struct Obj *obj)
{
    s32 dist;
    u8 i;

    switch (obj->state)
    {
    case 0:
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->field_90 - 256, obj->field_94, 0x400, func_080A3578, 1);
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
            for (i = 2; i < 6; i++)
                obj->child[i] = func_080A3770(obj, 3, 0, obj->field_90, obj->field_94, 0x500, (D_03000010() * 49 >> 15) + 0x80, (D_03000010() * 513 >> 15) + 0x200, 0);
            func_080A12B0(6, 0);
            func_080A38B0(1);
            obj->state++;
        }
        break;
    case 2:
        for (i = 0; i < 6 && obj->child[i] == 0; i++)
            ;
        if (i == 6)
            func_08077E6C(obj);
        break;
    }
}
