#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    u8 pad_0C[0x24];
    s32 speed;
};

void func_080771F4(struct Obj *);

void func_080A3578(struct Obj *obj)
{
    if (!(obj->flags & 0x8000))
    {
        obj->x -= obj->speed << 8;
        if (obj->x < -0x1000)
            func_080771F4(obj);
    }
    else
    {
        obj->x += obj->speed << 8;
        if (obj->x > 0x10000)
            func_080771F4(obj);
    }
}
