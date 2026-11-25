#include "types.h"

struct Child
{
    u8 pad_00[0x1A];
    u16 field_1A;
    u16 field_1C;
    u8 pad_1E[0xE];
    void (*callback)(void *);
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
};

void func_080A3578(void *);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A4670(struct Obj *obj)
{
    switch (obj->state)
    {
    case 0:
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->x, obj->y, 0x400, 0, 0);
        func_080A38B0(0);
        obj->state++;
        break;
    case 1:
        if (obj->child[0]->field_1A == 1 && obj->child[0]->field_1C == 0)
        {
            obj->child[1] = func_080A34A8(obj, 1, 0, obj->x, obj->y, 0x510, 0, 0);
            obj->state++;
        }
        break;
    case 2:
        if (obj->child[0]->field_1A == 2 && obj->child[0]->field_1C == 0)
        {
            obj->child[1]->callback = func_080A3578;
            obj->child[1]->speed = 16;
            obj->state++;
        }
        break;
    case 3:
        if (obj->child[0] == 0 && obj->child[1] == 0)
            func_08077E6C(obj);
        break;
    }
}
