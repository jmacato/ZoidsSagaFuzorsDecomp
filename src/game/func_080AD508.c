#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    void *child[32];
    u32 count;
};

extern u32 (*D_03000010)(void);

void *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_08077E6C(struct Obj *);

void func_080AD508(struct Obj *obj)
{
    u32 type;
    u8 i;

    if (obj->count < 32)
    {
        type = obj->count & 1;
        obj->child[obj->count++] = func_080A3770(obj, type, 0,
            obj->x + (D_03000010() * 65 >> 15) - 32,
            obj->y + (D_03000010() * 65 >> 15) - 32,
            type == 0 ? 0x420 : 0x400, 0,
            (D_03000010() * 257 >> 15) + 0x200, 0);
    }
    else
    {
        for (i = 0; i < 32 && obj->child[i] == 0; i++)
            ;
        if (i == 32)
            func_08077E6C(obj);
    }
}
