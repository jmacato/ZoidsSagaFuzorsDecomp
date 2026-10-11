#include "types.h"

struct Child
{
    u32 flags;
    u8 pad_4[0x16];
    u16 field_1A;
    u16 field_1C;
};

struct Obj
{
    u8 pad_0[0xC];
    struct Child *field_C;
    struct Child *field_10;
    u8 pad_14[0x78];
    s32 field_8C;
    s32 field_90;
};

void func_08075F20(u16);
void func_08077204(void *, u16);

void func_080B27D8(struct Obj *obj)
{
    if (obj->field_8C == 1)
    {
        func_08075F20(0xDF);
        func_08077204(obj->field_C, obj->field_90);
        func_08077204(obj->field_10, obj->field_90);
        obj->field_8C = 2;
    }
    else if (obj->field_8C == 2)
    {
        if (obj->field_90 == 1 && obj->field_C->field_1A == 5 && obj->field_C->field_1C == 0)
            func_08075F20(0xDF);
        if ((obj->field_C->flags & 4) && (obj->field_10->flags & 4))
            obj->field_8C = 0xFF;
    }
}
