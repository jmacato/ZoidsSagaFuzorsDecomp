#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    u8 pad_0C[0x24];
    s32 vx;
    s32 vy;
};

void func_080771F4(struct Obj *);

void func_080A37A8(struct Obj *obj)
{
    obj->x += obj->vx;
    obj->y += obj->vy;
    obj->vy += 16;
    if (obj->x < -0x1000 || obj->x > 0x10000 || obj->y < -0x1000 || obj->y > 0x9000)
        func_080771F4(obj);
}
