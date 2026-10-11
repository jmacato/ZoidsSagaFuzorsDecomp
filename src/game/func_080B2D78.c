#include "types.h"

struct Obj
{
    u8 pad_0[0xC];
    u32 *children[32];
    s32 field_8C;
    u8 pad_90[0xC];
    u32 field_9C;
};

void func_08077E6C(void *);

void func_080B2D78(struct Obj *obj)
{
    u8 i;

    if (obj->field_9C < 30)
    {
        obj->field_9C++;
        return;
    }
    for (i = 0; i < 32; i++)
    {
        if (obj->children[i] != 0 && (*obj->children[i] & 1))
            break;
    }
    if (i == 32)
        func_08077E6C(obj);
}
