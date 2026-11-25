#include "types.h"

struct Obj
{
    u32 flags;
};

struct Group
{
    u32 flags;
    u8 pad4[8];
    struct Obj *objs[32];
};

void func_080771F4(struct Obj *);

void func_08077E6C(struct Group *group)
{
    u8 i;

    group->flags &= ~1;
    for (i = 0; i < 32; i++)
    {
        if (group->objs[i] != 0 && (group->objs[i]->flags & 1))
            func_080771F4(group->objs[i]);
    }
}
