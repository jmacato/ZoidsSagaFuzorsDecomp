#include "types.h"

struct Sprite
{
    u8 pad_0[0xC];
    u16 x;
    u16 y;
};

struct Actor
{
    u8 flags;
    u8 pad_1[3];
    s32 x;
    s32 y;
    s32 field_C;
    s32 field_10;
    u8 field_14;
    u8 field_15;
    u8 dir;
    u8 dir2;
    u8 pad_18[4];
    struct Sprite *obj1;
    struct Sprite *obj2;
    s32 dx;
    s32 dy;
    u32 negX;
    u32 negY;
    u32 accX;
    u32 accY;
    u32 step;
    u32 count;
};

u16 func_080C8B74(s16, s16);
u16 func_080C8B8C(s32);
s32 func_080808CC(struct Actor *);
void func_08077204(struct Sprite *, u16);

void func_08081B80(struct Actor *a)
{
    s32 tx, ty, dir;
    u16 d;
    a->flags = (a->flags & ~8) | 0x10;
    tx = a->step;
    ty = a->count;
    a->dx = (tx - a->x) / 256;
    a->dy = (ty - a->y) / 256;
    a->obj1->x -= a->dx;
    a->obj1->y -= a->dy;
    if (a->obj2 != 0)
    {
        a->obj2->x -= a->dx;
        a->obj2->y -= a->dy;
    }
    dir = func_080C8B74(-a->dy, a->dx);
    dir = (dir + 0x1000) >> 13;
    a->dir = a->dir2 = dir % 8;
    if (a->dx >= 0)
        a->negX = 0;
    else
    {
        a->dx = -a->dx;
        a->negX = 1;
    }
    if (a->dy >= 0)
        a->negY = 0;
    else
    {
        a->dy = -a->dy;
        a->negY = 1;
    }
    a->accX = a->accY = 0;
    d = func_080C8B8C(a->dx * a->dx + a->dy * a->dy);
    a->step = d;
    if (a->field_14 == 1)
        a->step = d * 2;
    else
    {
        a->field_14 = 3;
        a->step = d >> 1;
    }
    func_08077204(a->obj1, func_080808CC(a));
    a->count = 0;
    a->x = tx;
    a->y = ty;
}
