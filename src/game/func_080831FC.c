#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
};

struct Slot
{
    u8 active;
    u8 flipX;
    u8 flipY;
    u8 pad_3;
    s16 dx;
    s16 dy;
    s16 field_8;
    s16 field_A;
    u8 field_C;
    u8 field_D;
    u8 pad_E[2];
};

struct Script
{
    u8 pad_0[0x11AC];
    struct Slot slots[16];
    struct Obj *objs[16];
};

extern struct Script D_0201F6DC;

void func_080831FC(u8 id, s16 x, s16 y, u8 k)
{
    struct Slot *s = &D_0201F6DC.slots[id];
    s->active = 1;
    s->dx = x - D_0201F6DC.objs[id]->x / 256;
    if (s->dx < 0)
    {
        s->dx = -s->dx;
        s->flipX = 1;
    }
    else
        s->flipX = 0;
    s->dy = y - D_0201F6DC.objs[id]->y / 256;
    if (s->dy < 0)
    {
        s->dy = -s->dy;
        s->flipY = 1;
    }
    else
        s->flipY = 0;
    s->field_C = k;
    s->field_8 = s->field_A = 0;
    s->field_D = 0;
}
