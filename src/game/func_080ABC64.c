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
    s32 field_98;
    s32 field_9C;
};

extern u32 (*D_03000010)(void);
extern u16 D_03000058;

void func_080ABC64(struct Obj *obj)
{
    s32 range = 16;

    obj->field_8C = obj->field_90 = obj->field_94 = 0;
    obj->field_98 = obj->x + (D_03000010() * 65 >> 15) - 32;
    obj->field_9C = obj->y - range + (D_03000010() * 33 >> 15);
    D_03000058 = 0x1010;
}
