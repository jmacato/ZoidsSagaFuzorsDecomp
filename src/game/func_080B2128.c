#include "types.h"

struct Obj
{
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
};

struct Big
{
    u8 pad_0[0x8A8];
    s32 field_8A8;
};

struct Scroll
{
    s32 x;
    s32 y;
};

void *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
void func_080A38B0(u8);
void func_080A12B0(s32, s32);
void func_08077E6C(void *);

extern struct Big D_02036E7C;
extern struct Scroll D_03000060;

void func_080B2128(struct Obj *obj)
{
    func_080A34A8(obj, 0, 0, obj->field_4 + D_02036E7C.field_8A8 / 256, obj->field_8 + D_03000060.y / 256, 0x1020, 0, 0);
    func_080A12B0(7, 0);
    func_080A38B0(0);
    func_08077E6C(obj);
}
