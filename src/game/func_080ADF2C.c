#include "types.h"

struct Child
{
    u8 pad_00[0x1A];
    u16 field_1A;
    u16 field_1C;
};

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    struct Child *child[32];
    u32 state;
    s32 timer;
    s32 wait;
};

struct State
{
    u8 pad_000[0x8A8];
    s32 field_8A8;
};

extern struct State D_02036E7C;
extern s32 D_03000060[];
extern s32 D_020378EC[][4];
extern const u8 D_08735940[];
extern const u16 D_087358A0[][8];

void func_080ADE30(struct Obj *, u8);
void func_080771F4(struct Child *);
void func_0807806C(const void *, void *, s32);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080ADF2C(struct Obj *obj)
{
    u8 i;

    if (obj->state < 2 || (obj->state == 2 && obj->child[0]->field_1A < 8))
    {
        if (!(obj->timer & 1))
            func_080ADE30(obj, 1);
        if (++obj->timer == 60)
            obj->state++;
    }
    else if (obj->state == 2 && obj->child[0]->field_1A == 9)
    {
        for (i = 1; i < 32; i++)
        {
            if (obj->child[i] != 0)
                func_080771F4(obj->child[i]);
        }
    }
    switch (obj->state)
    {
    case 0:
        if (obj->timer == 1)
            func_080A38B0(0);
        break;
    case 1:
        obj->child[0] = func_080A34A8(obj, 0, 0, obj->x, obj->y, 0x500, 0, 0);
        obj->state++;
        break;
    case 2:
        if (obj->child[0] == 0)
            obj->state++;
        else if (obj->child[0]->field_1C == 0)
            func_0807806C(D_087358A0[D_08735940[obj->child[0]->field_1A]], (u16 *)0x05000200 + D_020378EC[0][2] * 16, 16);
        break;
    case 3:
        if (++obj->wait == 30)
            obj->state++;
        break;
    case 4:
        obj->child[0] = func_080A34A8(obj, 2, 0, obj->x - 128 + D_02036E7C.field_8A8 / 256, obj->y + D_03000060[1] / 256, 0x1500, 0, 0);
        obj->child[1] = func_080A34A8(obj, 3, 0, obj->x, obj->y, 0x400, 0, 0);
        func_080A12B0(12, 0);
        func_080A38B0(1);
        obj->state++;
        break;
    case 5:
        if (obj->child[0] == 0 && obj->child[1] == 0)
            func_08077E6C(obj);
        break;
    }
}
