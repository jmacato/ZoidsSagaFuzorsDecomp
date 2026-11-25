#include "types.h"

struct Child
{
    u32 flags;
    u8 pad_04[0xC];
    u16 field_10;
    u16 field_12;
    u8 pad_14[0x1C];
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
    s32 timer;
    s32 field_94;
};

void func_080A7CB4(void *);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A8E74(struct Obj *obj)
{
    u8 i;

    switch (obj->state)
    {
    case 0:
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->field_94 - 256, 0xE0, 0x20, func_080A7CB4, 1);
        obj->child[0]->parent = obj;
        obj->child[0]->count = 0;
        obj->child[0]->target = obj->field_94;
        func_080A38B0(0);
        obj->state++;
        break;
    case 1:
        if (obj->child[0]->flags & 0x20000)
        {
            obj->child[1] = func_080A34A8(obj, 2, 1, obj->field_94, 0x60, 0x200, 0, 0);
            func_080A12B0(6, 0);
            func_080A38B0(1);
            obj->timer = 0;
            obj->state++;
        }
        break;
    case 2:
        if (++obj->timer == 4)
        {
            obj->child[2] = func_080A34A8(obj, 2, 1, obj->field_94 - 16, 0x48, 0x80100, 0, 0);
            obj->child[2]->field_10 = obj->child[2]->field_12 = 0x180;
            obj->child[3] = func_080A34A8(obj, 2, 2, obj->field_94 - 4, 0x62, 0, 0, 0);
            obj->timer = 0;
            obj->state++;
        }
        break;
    case 3:
        if (++obj->timer == 4)
        {
            obj->child[4] = func_080A34A8(obj, 2, 2, obj->field_94 - 22, 0x5C, 0, 0, 0);
            obj->child[5] = func_080A34A8(obj, 2, 2, obj->field_94 + 12, 0x4B, 0, 0, 0);
            obj->child[6] = func_080A34A8(obj, 2, 2, obj->field_94 - 2, 0x35, 0, 0, 0);
            obj->timer = 0;
            obj->state++;
        }
        break;
    case 4:
        if (++obj->timer == 4)
        {
            obj->child[7] = func_080A34A8(obj, 2, 0, obj->field_94 + 8, 0x34, 0x80200, 0, 0);
            obj->child[7]->field_10 = obj->child[7]->field_12 = 0x200;
            obj->state++;
        }
        break;
    case 5:
        for (i = 24; i < obj->child[0]->count / 2 + 25 && obj->child[i] == 0; i++)
            ;
        if (i == obj->child[0]->count / 2 + 25)
        {
            for (i = 1; i < 8 && obj->child[i] == 0; i++)
                ;
            if (i == 8)
                func_08077E6C(obj);
        }
        break;
    }
}
