#include "types.h"

struct Obj
{
    u8 pad0[4];
    u16 flags;
    u16 field_6;
    u8 pad8[0x5A];
    u16 field_62;
};

void func_080BE378(struct Obj *obj)
{
    if (obj->flags & 2)
    {
        obj->flags &= ~2;
        obj->field_6 = obj->field_62;
    }
}
