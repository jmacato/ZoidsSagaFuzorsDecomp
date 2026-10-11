#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    u8 pad_0C[0x80];
    s32 state;
};

struct State
{
    u8 pad_000[0x8A8];
    s32 field_8A8;
};

extern struct State D_02036E7C;
extern s32 D_03000060[];

void *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080AD480(struct Obj *obj)
{
    func_080A34A8(obj, 0, 0, obj->x + D_02036E7C.field_8A8 / 256, obj->y + D_03000060[1] / 256, 0x1420, 0, 0);
    func_080A12B0(7, 0);
    func_080A38B0(0);
    func_08077E6C(obj);
}
