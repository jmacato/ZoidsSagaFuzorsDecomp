#include "types.h"

struct Obj
{
    u8 pad_00[0x4];
    s32 field_4;
    u8 pad_08[0x84];
    s32 field_8C;
    s32 field_90;
    s32 field_94;
};

extern u32 (*D_03000010)(void);

void func_080A8C4C(struct Obj *obj)
{
    obj->field_8C = obj->field_90 = 0;
    obj->field_94 = obj->field_4 + (D_03000010() * 65 >> 15) - 32;
}
