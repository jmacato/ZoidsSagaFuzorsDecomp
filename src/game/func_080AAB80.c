#include "types.h"

struct Child
{
    u32 flags;
    u8 pad_04[0x2C];
    void *parent;
    u32 count;
    s32 target;
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
    u32 timer;
};

extern u32 (*D_03000010)(void);

void func_080AA8EC(void *);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080AAB80(struct Obj *obj)
{
    u8 i;

    switch (obj->state)
    {
    case 0:
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->field_90 - 256, obj->field_94, 0x20, func_080AA8EC, 1);
        obj->child[0]->parent = obj;
        obj->child[0]->count = 0;
        obj->child[0]->target = obj->field_90;
        func_080A38B0(0);
        obj->state++;
        break;
    case 1:
        if (obj->child[0]->flags & 0x20000)
        {
            if ((obj->timer & 3) == 0)
                obj->child[obj->timer / 4 + 1] = func_080A34A8(obj, 2, 0,
                    obj->field_90 + (obj->timer ? (s32)(D_03000010() * 33 >> 15) - 16 : 0),
                    obj->field_94 + (obj->timer ? (s32)(D_03000010() * 33 >> 15) - 16 : 0), 0x400, 0, 0);
            if (obj->timer == 0)
                func_080A38B0(1);
            if (++obj->timer == 20)
            {
                func_080A12B0(6, 0);
                obj->state++;
            }
        }
        break;
    case 2:
        for (i = 16; i < obj->child[0]->count / 2 + 17 && obj->child[i] == 0; i++)
            ;
        if (i == obj->child[0]->count / 2 + 17)
        {
            for (i = 1; i < 6 && obj->child[i] == 0; i++)
                ;
            if (i == 6)
                func_08077E6C(obj);
        }
        break;
    }
}
