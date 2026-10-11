#include "types.h"

struct Obj
{
    u8 pad_00[0x4];
    s32 x;
    s32 y;
    u8 pad_0C[0x80];
    s32 field_8C;
    s32 field_90;
    s32 field_94;
};

extern u32 (*D_03000010)(void);

s32 func_080A38B0(u8);

void func_080AB040(struct Obj *obj)
{
    s32 range = 16;

    obj->field_8C = 0;
    obj->field_90 = obj->x + (D_03000010() * 65 >> 15) - 32;
    obj->field_94 = obj->y - range + (D_03000010() * 33 >> 15);
    func_080A38B0(0);
}
