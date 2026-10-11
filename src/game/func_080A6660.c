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
    struct Child *child[32];
    u32 state;
};

extern u32 (*D_03000010)(void);

struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
struct Child *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A6660(struct Obj *obj)
{
    u8 i;

    switch (obj->state)
    {
    case 0:
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->x, obj->y, 0, 0, 1);
        func_080A38B0(0);
        obj->state++;
        break;
    case 1:
        if (obj->child[0]->field_1A == 5)
        {
            for (i = 0; i < 8; i++)
                obj->child[i + 1] = func_080A3770(obj, 1, 0, obj->x, obj->y, 0x500, (D_03000010() * 49 >> 15) + 0x80, (D_03000010() * 513 >> 15) + 0x200, 0);
            func_080A12B0(8, 0);
            func_080A38B0(1);
            obj->state++;
        }
        break;
    case 2:
        for (i = 0; i < 9 && obj->child[i] == 0; i++)
            ;
        if (i == 9)
            func_08077E6C(obj);
        break;
    }
}
