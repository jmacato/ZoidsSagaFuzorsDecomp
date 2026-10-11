#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    u8 pad_0C[0x80];
    s32 state;
};

struct State
{
    u8 pad_00[0x94];
    struct Obj *field_94;
};

extern struct State D_02036E7C;

void func_080AC9D4(void *);
struct Obj *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
s32 func_080A38B0(u8);

void func_080AC9E8(struct Obj *obj)
{
    if (obj->state == 0)
    {
        D_02036E7C.field_94 = func_080A34A8(obj, 0, 0, obj->x, obj->y, 0x10, func_080AC9D4, obj->state);
        func_080A38B0(0);
        obj->state++;
    }
    else if (D_02036E7C.field_94->flags & 4)
        obj->flags &= ~1;
}
