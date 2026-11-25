#include "types.h"

struct Obj
{
    u8 pad_00[0x30];
    s32 field_30;
    s32 field_34;
};

void func_080A35C0(void);
struct Obj *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void), s32);

struct Obj *func_080A3770(void *a0, s32 a1, u16 a2, s16 a3, s16 a4, s32 a5, s32 a6, s32 a7, s32 a8)
{
    struct Obj *obj = func_080A34A8(a0, a1, a2, a3, a4, a5, func_080A35C0, a8);

    obj->field_30 = a6;
    obj->field_34 = a7;
    return obj;
}
