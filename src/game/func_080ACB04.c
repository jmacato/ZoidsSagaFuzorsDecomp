#include "types.h"

struct Obj
{
    u8 pad_00[0x8C];
    s32 field_8C;
    s32 field_90;
};

extern u16 D_03000058;
extern u16 D_03000056;
extern u8 D_02037B2C[];

void func_080787A4(void *, s16, s16, u8);

void func_080ACB04(struct Obj *obj)
{
    obj->field_8C = obj->field_90 = 0;
    D_03000058 = 0x808;
    func_080787A4(D_02037B2C, 0x3F3F, 0x1F1F, 8);
    D_03000056 = 0x2044;
    *(u16 *)0x05000000 = 0x1F;
}
