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
    s32 state;
    s32 started;
    u32 index;
};

extern u32 (*D_03000010)(void);

s16 func_08075AAC(s16);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
struct Child *func_080A37EC(void *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080AE108(struct Obj *obj)
{
    u8 amp;
    s16 px;
    s16 py;
    u8 i;

    if (obj->state == 0)
    {
        obj->child[0] = func_080A34A8(obj, 0, 1, 0x80, obj->y, 0x600, 0, 1);
        func_080A38B0(0);
        obj->state++;
    }
    else if (obj->started == 0)
    {
        if (obj->child[0]->field_1A == 2)
        {
            obj->started = 1;
            func_080A12B0(6, 0);
            func_080A38B0(1);
        }
    }
    if (obj->started != 0 && obj->index < 15)
    {
        amp = func_08075AAC(obj->index * 128 / 14) / 8;
        px = obj->x + obj->index * 8 - 32;
        py = obj->y + (obj->index & 3) * amp / 3 - amp / 2 + ((D_03000010() * 9 >> 15) - 4);
        obj->child[obj->index + 1] = func_080A34A8(obj, 1, 0, px, py, 0x100, 0, 0);
        obj->child[obj->index + 16] = func_080A37EC(obj, 2, 0, px, py, 0x20, 0, (D_03000010() * 257 >> 15) + 0x200, 0);
        obj->index++;
    }
    if (obj->index == 15)
    {
        for (i = 0; i < 31 && obj->child[i] == 0; i++)
            ;
        if (i == 31)
            func_08077E6C(obj);
    }
}
