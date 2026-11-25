#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    u8 pad_0C[0x24];
    s32 angle;
    s32 speed;
};

struct Scroll
{
    s32 x;
    s32 y;
};

extern struct Scroll D_03000060[];

s16 func_08075AAC(u8);
s16 func_08075AF8(u8);
void func_080771F4(struct Obj *);

void func_080A35C0(struct Obj *obj)
{
    u8 angle = obj->angle;
    s32 d;
    s32 pos;

    d = func_08075AF8(angle) * obj->speed / 256;
    if (!(obj->flags & 0x8000))
        obj->x += d;
    else
        obj->x -= d;
    pos = obj->x;
    if (obj->flags & 0x1000)
    {
        switch (obj->flags & 0x6000)
        {
        case 0:
            pos -= D_03000060[0].x;
            break;
        case 0x2000:
            pos -= D_03000060[1].x;
            break;
        case 0x4000:
            pos -= D_03000060[2].x;
            break;
        case 0x6000:
            pos -= D_03000060[3].x;
            break;
        }
    }
    if (!(obj->flags & 0x8000))
    {
        if (((angle < 0x40 || angle > 0xC0) && pos > 0x10000) || (angle > 0x40 && angle < 0xC0 && pos < -0x1000))
        {
            func_080771F4(obj);
            return;
        }
    }
    else
    {
        if (((angle < 0x40 || angle > 0xC0) && pos < -0x1000) || (angle > 0x40 && angle < 0xC0 && pos > 0x10000))
        {
            func_080771F4(obj);
            return;
        }
    }
    obj->y += func_08075AAC(angle) * obj->speed / 256;
    pos = obj->y;
    if (obj->flags & 0x1000)
    {
        switch (obj->flags & 0x6000)
        {
        case 0:
            pos -= D_03000060[0].y;
            break;
        case 0x2000:
            pos -= D_03000060[1].y;
            break;
        case 0x4000:
            pos -= D_03000060[2].y;
            break;
        case 0x6000:
            pos -= D_03000060[3].y;
            break;
        }
    }
    if ((angle > 0 && angle < 0x80 && pos > 0x9000) || (angle > 0x80 && pos < -0x1000))
        func_080771F4(obj);
}
