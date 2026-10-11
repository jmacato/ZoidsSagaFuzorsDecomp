#include "types.h"

struct Child
{
    u32 flags;
    u8 pad_04[0x2C];
    void *parent;
    u32 count;
    s32 field_38;
    s32 field_3C;
};

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    struct Child *child[32];
    s32 state;
    s32 field_90;
    s32 field_94;
};

void func_080A72E4(void *);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A7A64(struct Obj *obj)
{
    u8 i;

    if (obj->state == 0)
    {
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->x, obj->y + obj->field_94, 0x20, func_080A72E4, 1);
        obj->child[0]->parent = obj;
        obj->child[0]->count = 0;
        obj->child[0]->field_38 = 0;
        obj->child[0]->field_3C = 0;
        func_080A38B0(0);
        obj->state++;
    }
    else
    {
        if (obj->child[0]->flags & 0x20000)
        {
            for (i = 24; i < obj->child[0]->count / 2 + 25 && obj->child[i] == 0; i++)
                ;
            if (i == obj->child[0]->count / 2 + 25)
                func_08077E6C(obj);
        }
    }
}
