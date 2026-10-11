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

void func_080A7DC0(void *);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A9814(struct Obj *obj)
{
    u8 i;

    switch (obj->state)
    {
    case 0:
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->field_94 - 256, -16, 0x20, func_080A7DC0, 1);
        obj->child[0]->parent = obj;
        obj->child[0]->count = 0;
        obj->child[0]->target = obj->field_94;
        func_080A38B0(0);
        obj->state++;
        break;
    case 1:
        if (obj->child[0]->flags & 0x20000)
        {
            obj->child[1] = func_080A34A8(obj, 2, 1, obj->field_94, 0x70, 0x200, 0, 0);
            func_080A12B0(6, 0);
            func_080A38B0(1);
            obj->timer = 0;
            obj->state++;
        }
        break;
    case 2:
        if (++obj->timer == 4)
        {
            obj->child[2] = func_080A34A8(obj, 2, 1, obj->field_94 + 1, 0x62, 0x80100, 0, 0);
            obj->child[2]->field_10 = obj->child[2]->field_12 = 0x140;
            obj->timer = 0;
            obj->state++;
        }
        break;
    case 3:
        if (++obj->timer == 4)
        {
            obj->child[3] = func_080A34A8(obj, 2, 0, obj->field_94 - 11, 0x44, 0x80000, 0, 0);
            obj->child[3]->field_10 = obj->child[3]->field_12 = 0x180;
            obj->timer = 0;
            obj->state++;
        }
        break;
    case 4:
        if (++obj->timer == 4)
        {
            obj->child[4] = func_080A34A8(obj, 2, 1, obj->field_94 + 18, 0x3E, 0x80100, 0, 0);
            obj->child[4]->field_10 = obj->child[4]->field_12 = 0x140;
            obj->child[5] = func_080A34A8(obj, 2, 1, obj->field_94 - 7, 0x31, 0x80100, 0, 0);
            obj->child[5]->field_10 = obj->child[5]->field_12 = 0x140;
            obj->timer = 0;
            obj->state++;
        }
        break;
    case 5:
        if (++obj->timer == 4)
        {
            obj->child[6] = func_080A34A8(obj, 2, 1, obj->field_94 - 30, 0x41, 0x80200, 0, 0);
            obj->child[6]->field_10 = obj->child[6]->field_12 = 0x140;
            obj->child[7] = func_080A34A8(obj, 2, 0, obj->field_94 + 20, 0x28, 0x80200, 0, 0);
            obj->child[7]->field_10 = obj->child[7]->field_12 = 0x1C0;
            obj->timer = 0;
            obj->state++;
        }
        break;
    case 6:
        if (++obj->timer == 4)
        {
            obj->child[8] = func_080A34A8(obj, 2, 0, obj->field_94 - 13, 0x1E, 0x80200, 0, 0);
            obj->child[8]->field_10 = obj->child[8]->field_12 = 0x200;
            obj->state++;
        }
        break;
    case 7:
        for (i = 24; i < obj->child[0]->count / 2 + 25 && obj->child[i] == 0; i++)
            ;
        if (i == obj->child[0]->count / 2 + 25)
        {
            for (i = 1; i < 9 && obj->child[i] == 0; i++)
                ;
            if (i == 9)
                func_08077E6C(obj);
        }
        break;
    }
}
