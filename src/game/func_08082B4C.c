#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    s32 vx;
    s32 vy;
};

struct Map
{
    u8 pad_0[0x14];
    u16 width;
    u16 height;
    u8 mode;
};

extern struct Map D_020209D8;
s32 func_080C8C80(s32, s32);

void func_08082B4C(struct Obj *obj)
{
    s32 x, y, nx, t;
    x = obj->x + obj->vx;
    obj->x = x;
    y = obj->y + obj->vy;
    obj->y = y;
    if (D_020209D8.mode == 2)
    {
        nx = func_080C8C80(x, D_020209D8.width << 11);
        obj->x = nx;
        obj->y = func_080C8C80(y, D_020209D8.height << 11);
        if (nx < 0)
        {
            s32 w = D_020209D8.width << 11;
            s32 u = nx;

            do
                u += w;
            while (u < 0);
            obj->x = u;
        }
        t = obj->y;
        if (t < 0)
        {
            do
                obj->y = t += D_020209D8.height << 11;
            while (t < 0);
        }
    }
}
