#include "types.h"

struct Child
{
    u8 pad_00[0x30];
    s32 speed;
};

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    struct Child *child[32];
    u32 count;
    s32 field_90;
    s32 field_94;
};

extern u32 (*D_03000010)(void);

void func_080A3578(void *);
s16 func_08075AAC(s16);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
u8 func_080A3874(struct Child *, s32, s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A49C0(struct Obj *obj)
{
    u8 k;
    u8 amp;
    s16 px;
    s16 py;
    u8 i;

    if (obj->count == 0)
    {
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->field_90 - 256, obj->field_94, 0x110, func_080A3578, 1);
        obj->child[0]->speed = 16;
        func_080A38B0(0);
        obj->count++;
    }
    if (obj->count < 8)
    {
        if (obj->count == 1 && func_080A3874(obj->child[0], obj->field_90 - 80, obj->field_94))
        {
            func_080A12B0(6, 0);
            func_080A38B0(1);
            obj->count++;
        }
        if (obj->count > 1)
        {
            k = obj->count - 2;
            amp = func_08075AAC(k * 128 / 5) / 16;
            px = obj->field_90 + k * 8;
            py = obj->field_94 + (k % 3 * amp >> 1) - amp / 2 + ((D_03000010() * 9 >> 15) - 4);
            obj->child[k + 1] = func_080A34A8(obj, 1, 0, px, py, 0, 0, 0);
            obj->count++;
        }
    }
    else
    {
        for (i = 0; i < 7 && obj->child[i] == 0; i++)
            ;
        if (i == 7)
            func_08077E6C(obj);
    }
}
