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

void func_080BE06C(struct Obj *obj, s16 delta)
{
    s32 v = obj->field_6 + delta;
    if (v < 0)
        obj->field_6 = 0;
    else if (v > obj->max_6)
        obj->field_6 = obj->max_6;
    else
        obj->field_6 += delta;
}
