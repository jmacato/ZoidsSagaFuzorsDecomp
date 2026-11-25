#include "types.h"

struct Child
{
    u32 flags;
    u8 pad_04[0x2C];
    void *parent;
    u32 count;
    s32 field_38;
};

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    struct Child *child[32];
    s32 state;
    s32 field_90;
};

void func_080A4E44(void *);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A5AD0(struct Obj *obj)
{
    u8 i;

    if (obj->state == 0)
    {
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->x - 16, obj->field_90, 0x20, func_080A4E44, 1);
        obj->child[0]->parent = obj;
        obj->child[0]->count = 0;
        obj->child[0]->field_38 = 0;
        func_080A38B0(0);
        obj->state++;
    }
    else
    {
        if (obj->child[0]->flags & 0x20000)
        {
            for (i = 24; i < obj->child[0]->count / 4 + 25 && obj->child[i] == 0; i++)
                ;
            if (i == obj->child[0]->count / 4 + 25)
                func_08077E6C(obj);
        }
    }
}
