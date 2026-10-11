#include "types.h"

struct Obj
{
    u8 pad_0[0xC];
    u32 *field_C;
    u32 *field_10;
    u8 pad_14[0x78];
    s32 field_8C;
};

void func_08075F20(u16);
void func_08077204(void *, u16);

void func_080B29D4(struct Obj *obj)
{
    if (obj->field_8C == 1)
    {
        func_08075F20(0xDF);
        func_08077204(obj->field_C, 1);
        func_08077204(obj->field_10, 1);
        obj->field_8C = 2;
    }
    else if (obj->field_8C == 2 && (*obj->field_C & 4) && (*obj->field_10 & 4))
    {
        obj->field_8C = 0xFF;
    }
}
