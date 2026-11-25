#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    void *child[32];
    u32 state;
    s32 field_90;
    s32 field_94;
    s32 timer;
};

extern u32 (*D_03000010)(void);

s16 func_08075AAC(s16);
s16 func_08075AF8(s16);
void func_080771F4(void *);
void *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
void *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080AD0B8(struct Obj *obj)
{
    u8 i;

    switch (obj->state)
    {
    case 0:
        obj->child[0] = func_080A3770(obj, 0, 0, obj->field_90 - func_08075AF8(0x36) * 192 / 256,
            obj->field_94 - func_08075AAC(0x36) * 192 / 256, 0x120, 0x4A, 0xC00, 1);
        func_080A38B0(0);
        obj->state++;
        break;
    case 1:
        if (++obj->timer == 16)
        {
            func_080771F4(obj->child[0]);
            obj->child[0] = func_080A34A8(obj, 2, 0, obj->field_90, obj->field_94, 0x100, 0, 0);
            for (i = 0; i < 8; i++)
                obj->child[i + 1] = func_080A3770(obj, 3, 0, obj->field_90, obj->field_94, 0x500, i * 8 + 0x2C + (D_03000010() >> 13), (D_03000010() * 513 >> 15) + 0x200, 1);
            func_080A12B0(6, 0);
            func_080A38B0(1);
            obj->state++;
        }
        break;
    case 2:
        for (i = 0; i < 9 && obj->child[i] == 0; i++)
            ;
        if (i == 9)
            func_08077E6C(obj);
        break;
    }
}
