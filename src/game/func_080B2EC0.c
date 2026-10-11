#include "types.h"

struct Obj
{
    u8 pad_0[0xC];
    void *field_C;
    u8 pad_10[0x7C];
    s32 field_8C;
};

void *func_080B2C38(struct Obj *, u16, u16, s16, s16, u8, u32, s32);
void func_08075F20(u16);

void func_080B2EC0(struct Obj *obj)
{
    obj->field_C = func_080B2C38(obj, 1, 0, -0x10, -0x10, 0, 0x200, 0);
    func_08075F20(0xEF);
    obj->field_8C = 0;
}
