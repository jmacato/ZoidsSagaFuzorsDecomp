#include "types.h"

struct Child
{
    u32 flags;
    s32 x;
    s32 y;
};

struct Obj
{
    u8 pad_0[0xC];
    struct Child *children[32];
    u32 field_8C;
    u32 field_90;
    u32 field_94;
};

struct Cam
{
    u8 pad_0[0x10];
    s32 x;
};

struct Big
{
    u8 pad_0[0x8B4];
    u32 field_8B4;
};

struct Child *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
struct Child *func_080A3770(struct Obj *, s32, u16, s16, s16, s32, s32, s32, s32);
s32 func_080A1B9C(void);
void func_080A38B0(u8);
void func_080A12B0(s32, s32);
void func_08077E6C(void *);
s32 func_080C8BAC(s32);

extern s32 D_03000010;
extern u16 D_0300005A;
extern u16 D_03000056;
extern struct Cam D_03000060;
extern struct Big D_02036E7C;

void func_080B16F8(struct Obj *obj)
{
    struct Child *child;
    struct Child *c;
    s32 kind;

    switch (obj->field_8C)
    {
    case 0:
        if (func_080A1B9C() == 0)
        {
            if (D_0300005A <= 15)
                D_0300005A++;
        }
        else
        {
            func_080A38B0(1);
            obj->field_8C++;
            obj->field_94 = 0;
        }
        break;
    case 1:
        if (obj->field_94 <= 1)
        {
            D_03000056 = 0xD95;
            obj->field_94++;
        }
        else
        {
            D_03000056 = 0xD90;
            c = obj->children[0] = func_080A34A8(obj, 0, 0, 0, 0x40, 0x5008, 0, 0);
            if (!(c->flags & 0x8000))
                c->x = D_03000060.x + 0xF000;
            else
                c->x = D_03000060.x;
            obj->field_90 = D_02036E7C.field_8B4 - 0x400;
            obj->field_94 = 0;
            obj->field_8C++;
        }
        break;
    case 2:
        if (D_0300005A != 0)
        {
            if (obj->field_94 & 1)
                goto move;
            D_0300005A--;
        }
        if (!(obj->field_94 & 1))
        {
            kind = (obj->field_94 & 2) == 0 ? 1 : 2;
            child = func_080A3770(obj, kind, 0, 0, 0, kind == 1 ? 0x5520 : 0x5500, 0, ((u32)(func_080C8BAC(D_03000010) * 257) >> 15) + 0x200, 0);
            child->x = obj->children[0]->x + (!(obj->children[0]->flags & 0x8000) ? 0x2000 : -0x2000);
            child->y = obj->children[0]->y + ((((u32)(func_080C8BAC(D_03000010) * 49) >> 15) - 0x18) << 8);
        }
    move:
        if (!(obj->children[0]->flags & 0x8000))
        {
            obj->children[0]->x += obj->field_90;
            if (obj->children[0]->x <= D_03000060.x + 0xA000)
                obj->field_90 += 0x20;
        }
        else
        {
            obj->children[0]->x -= obj->field_90;
            if (obj->children[0]->x >= D_03000060.x + 0x5000)
                obj->field_90 += 0x20;
        }
        if (obj->field_90 == D_02036E7C.field_8B4)
        {
            func_080A12B0(0x12, 0);
            func_080A38B0(2);
            obj->field_8C++;
        }
        obj->field_94++;
        break;
    case 3:
        if (obj->field_90 > 0xFFFFF000)
            obj->field_90 -= 0x20;
        if (!(obj->children[0]->flags & 0x8000))
        {
            obj->children[0]->x += obj->field_90;
            if (obj->children[0]->x <= D_03000060.x - 0x4000)
                func_08077E6C(obj);
        }
        else
        {
            obj->children[0]->x -= obj->field_90;
            if (obj->children[0]->x >= D_03000060.x + 0x13000)
                func_08077E6C(obj);
        }
        break;
    }
}
