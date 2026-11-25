#include "types.h"

struct Obj
{
    u8 pad_0[0x8C];
    s32 field_8C;
    s32 field_90;
};

void func_080AE878(struct Obj *obj)
{
    obj->field_8C = obj->field_90 = 0;
}
