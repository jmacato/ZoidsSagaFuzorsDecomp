#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    void *child[32];
    s32 state;
};

extern u32 (*D_03000010)(void);

void *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
void *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);
void *func_080A37EC(void *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080AB848(struct Obj *obj)
{
    u8 i;

    if (obj->state == 0)
    {
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->x, obj->y, 0x400, 0, 1);
        for (i = 0; i < 8; i++)
            obj->child[i + 1] = func_080A37EC(obj, 1, 0, obj->x, obj->y, 0x20,
                i * 32 / 7 + 0x6E + (D_03000010() * 5 >> 15),
                (i < 4 ? i : 7 - i) * 256 + 0x300 + (D_03000010() * 257 >> 15), 0);
        for (i = 0; i < 8; i++)
            obj->child[i + 9] = func_080A3770(obj, 2, 0, obj->x, obj->y, 0x400,
                i * 32 / 7 + 0x6E + (D_03000010() * 5 >> 15),
                (i < 4 ? i : 7 - i) * 256 + 0x300 + (D_03000010() * 257 >> 15), 0);
        func_080A12B0(8, 0);
        func_080A38B0(0);
        func_080A38B0(1);
        obj->state++;
    }
    else
    {
        for (i = 0; i < 17 && obj->child[i] == 0; i++)
            ;
        if (i == 17)
            func_08077E6C(obj);
    }
}
