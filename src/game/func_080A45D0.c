#include "types.h"

struct Obj
{
    u8 pad_00[0x8];
    s32 field_8;
    u8 pad_0C[0x80];
    s32 field_8C;
    s32 field_90;
};

extern u32 (*D_03000010)(void);

void func_080A45D0(struct Obj *obj)
{
    s32 range = 16;

    obj->field_8C = 0;
    obj->field_90 = obj->field_8 - range + (D_03000010() * 33 >> 15);
}
