#include "types.h"

struct Obj
{
    u8 pad0[6];
    s16 field_6;
    s16 field_8;
    u8 padA[0x58];
    s16 max_6;
    s16 max_8;
};

void func_080BE0A0(struct Obj *obj, s16 delta)
{
    s32 v = obj->field_8 + delta;
    if (v < 0)
        obj->field_8 = 0;
    else if (v > obj->max_8)
        obj->field_8 = obj->max_8;
    else
        obj->field_8 += delta;
}
