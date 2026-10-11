#include "types.h"

struct Obj
{
    u32 flags;
    s32 y;
};

struct State
{
    u8 pad_0[0x95C];
    struct Obj **field_95C;
    struct Obj *field_960;
};

extern struct State D_02036E7C;
extern u16 D_0300005A;
extern u16 D_03000056;

void func_080C8FCC(u32 frames);
void func_080771F4(void *obj);
void func_080A12B0(u8 mode, s32 arg);

void func_080A2CBC(void)
{
    u32 i;
    u16 alpha;
    struct Obj *obj;
    if (D_02036E7C.field_960 != 0)
    {
        for (i = 0; i < 60; i++)
            func_080C8FCC(1);
        alpha = 0x10;
        while (D_02036E7C.field_960->y < 0xF000)
        {
            D_02036E7C.field_960->y += 0x800;
            alpha--;
            D_0300005A = alpha / 2;
            func_080C8FCC(1);
        }
        D_03000056 = 0;
        func_080771F4(D_02036E7C.field_960);
        D_02036E7C.field_960 = 0;
        if (D_02036E7C.field_95C != 0 && (obj = *D_02036E7C.field_95C) != 0)
            obj->flags &= ~0x400;
        func_080A12B0(1, 0);
    }
}
