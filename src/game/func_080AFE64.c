#include "types.h"

struct Obj
{
    u8 pad_0[0x8C];
    s32 field_8C;
    s32 field_90;
    s32 field_94;
    s32 field_98;
    s32 field_9C;
};

void func_080AFE64(struct Obj *obj)
{
    obj->field_8C = obj->field_90 = obj->field_94 = obj->field_98 = obj->field_9C = 0;
}
