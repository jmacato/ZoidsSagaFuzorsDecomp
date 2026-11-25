#include "types.h"

struct Child
{
    u8 pad_00[0x1A];
    u16 field_1A;
};

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    struct Child *child;
    u8 pad_10[0x7C];
    u32 state;
};

struct State
{
    u8 pad_000[0x8A8];
    s32 field_8A8;
};

extern struct State D_02036E7C;
extern s32 D_03000060[];

struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080AC934(struct Obj *obj)
{
    switch (obj->state)
    {
    case 0:
        obj->child = func_080A34A8(obj, 0, 0, obj->x + 64 + D_02036E7C.field_8A8 / 256, obj->y + D_03000060[1], 0x1400, 0, 0);
        func_080A38B0(0);
        obj->state++;
        break;
    case 1:
        if (obj->child->field_1A == 8)
        {
            func_080A12B0(10, 0);
            func_080A38B0(1);
            obj->state++;
        }
        break;
    case 2:
        if (obj->child == 0)
            func_08077E6C(obj);
        break;
    }
}
