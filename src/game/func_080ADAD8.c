#include "types.h"

struct Child
{
    u32 flags;
    u8 pad_04[0x13];
    u8 field_17;
};

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    struct Child *child[32];
    u32 state;
    u32 timer;
    s32 fade;
};

extern u32 (*D_03000010)(void);
extern u16 D_03000056;
extern u16 D_03000058;

struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
struct Child *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080ADAD8(struct Obj *obj)
{
    u8 i;
    u8 angle;

    switch (obj->state)
    {
    case 0:
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->x - 128, obj->y, 0x20, 0, 0);
        D_03000056 = 0x2044;
        D_03000058 = 0x1004;
        *(u16 *)0x05000000 = 0;
        func_080A38B0(0);
        obj->state++;
        break;
    case 1:
        obj->fade += 2;
        D_03000058 = (obj->fade + 4) | 0x1000;
        if (obj->fade == 8)
            obj->child[0]->flags |= 0x20000;
        if (obj->fade == 10)
            obj->state++;
        break;
    case 2:
        for (i = 0; i < 16; i++)
            obj->child[i + 1] = func_080A3770(obj, 1, 0, obj->x, obj->y, 0x500, i * 16 + (D_03000010() * 9 >> 15) - 4, (D_03000010() * 257 >> 15) + 0x200, 0);
        for (i = 0; i < 8; i++)
        {
            angle = i * 0x6B / 7 + ((D_03000010() * 9 >> 15) + 0x51);
            obj->child[i + 9] = func_080A3770(obj, 2, 0, obj->x, obj->y, 0x500, angle, (D_03000010() * 257 >> 15) + 0x100, 0);
            obj->child[i + 9]->field_17 = angle + 0x80;
        }
        func_080A12B0(6, 0);
        func_080A38B0(1);
        D_03000056 = 0x740;
        D_03000058 = 0x1010;
        obj->child[0]->flags = (obj->child[0]->flags & ~0x20000) | 0x400;
        obj->state++;
        break;
    case 3:
        obj->timer++;
        D_03000058 = (16 - obj->timer / 2) | 0x1000;
        if (obj->timer == 32)
            func_08077E6C(obj);
        break;
    }
}
