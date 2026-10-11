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
    u8 pad_1[0xB];
    s32 field_C;
    s32 field_10;
    u8 field_14;
    u8 field_15;
    u8 pad_16[6];
    struct Sprite *obj1;
    struct Sprite *obj2;
    u32 dx;
    u32 dy;
    u32 negX;
    u32 negY;
    u32 accX;
    u32 accY;
    u32 step;
    u32 count;
};

s32 func_080808CC(struct Actor *);
void func_08077204(struct Sprite *, u16);

void func_08081C7C(struct Actor *a)
{
    a->accX += a->dx;
    a->accY += a->dy;
    while (a->accX >= a->step)
    {
        if (a->negX == 0)
        {
            a->obj1->x++;
            if (a->obj2 != 0)
                a->obj2->x++;
        }
        else
        {
            a->obj1->x--;
            if (a->obj2 != 0)
                a->obj2->x--;
        }
        a->accX -= a->step;
    }
    while (a->accY >= a->step)
    {
        if (a->negY == 0)
        {
            a->obj1->y++;
            if (a->obj2 != 0)
                a->obj2->y++;
        }
        else
        {
            a->obj1->y--;
            if (a->obj2 != 0)
                a->obj2->y--;
        }
        a->accY -= a->step;
    }
    if (++a->count == a->step)
    {
        a->flags &= ~0x10;
        a->obj1->x = 0;
        a->obj1->y = 0xFFFE;
        if (a->obj2 != 0)
        {
            a->obj2->x = 0;
            a->obj2->y = 14;
        }
        a->field_14 = a->field_15 = 0;
        func_08077204(a->obj1, func_080808CC(a));
        a->field_C = a->field_10 = 0;
    }
}
