#include "types.h"

struct Obj
{
    u8 pad_00[0x8C];
    s32 field_8C;
    u32 field_90;
    s32 field_94;
    s32 field_98;
    u8 pad_9C[0xC];
    s32 field_A8;
};

extern u32 (*D_03000010)(void);

void func_080AD2D0(struct Obj *obj)
{
    obj->field_8C = obj->field_98 = 0;
    obj->field_90 = D_03000010() >> 14;
    obj->field_A8 = obj->field_90 == 0 ? 0x40 : 0xC0;
}
