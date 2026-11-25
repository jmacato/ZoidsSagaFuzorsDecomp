#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
};

s32 func_080A3874(struct Obj *obj, s32 x, s32 y)
{
    if (!(obj->flags & 0x8000) ? obj->x == (0xF0 - x) << 8 : obj->x == x << 8)
    {
        if (obj->y == y << 8)
            return 1;
    }
    return 0;
}
