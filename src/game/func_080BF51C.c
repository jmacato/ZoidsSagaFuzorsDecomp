#include "types.h"

struct Obj
{
    u8 pad0[4];
    u16 flags;
    u16 field_6;
    u8 pad8[0x5A];
    u16 field_62;
};

struct Obj *func_0809A908(u8, u8);

u8 func_080BF51C(u8 a, u8 b)
{
    struct Obj *obj = func_0809A908(a, b);
    u8 r;
    if (!(obj->flags & 2))
        r = 0;
    else
    {
        obj->field_6 = obj->field_62;
        obj->flags &= ~2;
        r = 1;
    }
    return r;
}
