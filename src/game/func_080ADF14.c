#include "types.h"

struct Obj
{
    u8 pad_00[0x8C];
    s32 field_8C;
    s32 field_90;
    s32 field_94;
};

void func_080ADF14(struct Obj *obj)
{
    obj->field_8C = obj->field_90 = obj->field_94 = 0;
}
