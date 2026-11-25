#include "types.h"

struct Obj
{
    u32 flags;
    u8 pad4[8];
    void *children[32];
    u8 pad8C[0x20];
    u32 field_AC;
    u32 field_B0;
};

extern struct Obj D_03002688[];

struct Obj *func_08077DF0(u32 flags, u32 a, u32 b)
{
    u8 i;
    struct Obj *obj;

    for (i = 0; i < 16; i++)
    {
        if (!(D_03002688[i].flags & 1))
            break;
    }
    if (i == 16)
        return 0;
    obj = &D_03002688[i];
    obj->flags = flags | 1;
    for (i = 0; i < 32; i++)
        obj->children[i] = 0;
    obj->field_AC = a;
    obj->field_B0 = b;
    return obj;
}
