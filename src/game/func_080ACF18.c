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

s16 func_08075AAC(u8);
s16 func_08075AF8(u8);
u16 func_080C8B74(s16, s16);
u16 func_080C8B8C(u32);
void *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
void *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080ACF18(struct Obj *obj)
{
    u8 i;
    u8 angle;
    s32 dy;
    s32 dx;
    s32 dist;

    if (obj->state == 0)
    {
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->x, obj->y, 0x500, 0, 0);
        for (i = 0; i < 16; i++)
        {
            angle = i * 16 + ((s32)(D_03000010() * 17 >> 15) - 8);
            dy = func_08075AAC(angle) * 3;
            dx = func_08075AF8(angle) - dy / 2;
            angle = func_080C8B74(dx, dy) >> 8;
            dist = func_080C8B8C(dx * dx + dy * dy);
            dist -= dist * (s32)(D_03000010() * 129 >> 15) / 256;
            obj->child[i + 1] = func_080A3770(obj, 1, 0, obj->x, obj->y, 0x500, angle, dist, 0);
        }
        func_080A38B0(0);
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
