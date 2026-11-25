#include "types.h"

struct Child
{
    u8 pad_0[0x1A];
    u16 field_1A;
};

struct Obj
{
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    struct Child *children[32];
    u32 field_8C;
    u32 field_90;
};

struct Child *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
struct Child *func_080A3770(struct Obj *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_080A38B0(u8);
void func_08077E6C(void *);
void func_080C8B78(const void *, void *, u32);
void func_080C8B7C(const void *, void *, u32);
void func_0807806C(const void *, void *, s32);

extern u16 D_0203796C[2][64];
extern u16 D_02037A6C[2][48];

void func_080AF8E8(struct Obj *obj)
{
    vu16 bg;
    vu16 sp;
    u16 *bgPal;
    u16 *objPal;
    u8 i;
    u8 r;
    u8 g;
    u8 b;

    switch (obj->field_8C)
    {
    case 0:
        obj->children[0] = func_080A3770(obj, 3, 0, obj->field_4, obj->field_8, 0x400, 0xC0, 0x49, 0);
        func_080A38B0(0);
        obj->field_8C++;
        break;
    case 1:
        if (obj->children[0] == 0)
        {
            obj->children[0] = func_080A34A8(obj, 2, 0, obj->field_4, obj->field_8 - 0x18, 0x400, 0, 0);
            obj->children[1] = func_080A34A8(obj, 1, 0, obj->field_4 + 0x80, obj->field_8 - 0x18, 0x400, 0, 0);
            func_080A38B0(1);
            obj->field_8C++;
        }
        break;
    case 2:
        if (obj->children[1] == 0 && ++obj->field_90 == 30)
        {
            obj->children[1] = func_080A34A8(obj, 0, 0, 0x70, -0x20, 0x400, 0, 0);
            obj->field_90 = 0;
            func_080A38B0(1);
            obj->field_8C++;
        }
        break;
    case 3:
        if (obj->children[1] == 0 && ++obj->field_90 == 30)
        {
            obj->children[1] = func_080A34A8(obj, 4, 0, obj->field_4, obj->field_8, 0x400, 0, 0);
            func_080A38B0(1);
            obj->field_8C++;
        }
        break;
    case 4:
        if (obj->children[1]->field_1A == 4)
        {
            bgPal = (u16 *)0x05000000;
            func_080C8B78(bgPal, D_0203796C[0], 0x20);
            objPal = (u16 *)0x05000200;
            func_080C8B78(objPal, D_02037A6C[0], 0x18);
            bg = 0x7FFF;
            func_080C8B7C((void *)&bg, D_0203796C[1], 0x01000040);
            sp = 0x7FFF;
            func_080C8B7C((void *)&sp, D_02037A6C[1], 0x01000040);
            func_0807806C(D_0203796C[1], bgPal, 0x80);
            func_0807806C(D_02037A6C[1], objPal, 0x60);
            obj->children[2] = func_080A34A8(obj, 5, 0, obj->field_4, obj->field_8, 0x400, 0, 0);
            obj->field_90 = 0;
            func_080A38B0(2);
            obj->field_8C++;
        }
        break;
    case 5:
        for (i = 0; i < 64; i++)
        {
            r = D_0203796C[0][i] & 31;
            g = (D_0203796C[0][i] >> 5) & 31;
            b = (D_0203796C[0][i] >> 10) & 31;
            r = (r + (((31 - r) * (31 - obj->field_90)) >> 5));
            g = g + (((31 - g) * (31 - obj->field_90)) >> 5);
            b = b + (((31 - b) * (31 - obj->field_90)) >> 5);
            D_0203796C[1][i] = r | (g << 5) | (b << 10);
        }
        for (i = 0; i < 48; i++)
        {
            r = D_02037A6C[0][i] & 31;
            g = (D_02037A6C[0][i] >> 5) & 31;
            b = (D_02037A6C[0][i] >> 10) & 31;
            r = (r + (((31 - r) * (31 - obj->field_90)) >> 5));
            g = g + (((31 - g) * (31 - obj->field_90)) >> 5);
            b = b + (((31 - b) * (31 - obj->field_90)) >> 5);
            D_02037A6C[1][i] = r | (g << 5) | (b << 10);
        }
        func_0807806C(D_0203796C[1], (void *)0x05000000, 0x80);
        func_0807806C(D_02037A6C[1], (void *)0x05000200, 0x60);
        if (++obj->field_90 == 32)
            obj->field_8C++;
        break;
    case 6:
        if (obj->children[0] == 0 && obj->children[1] == 0 && obj->children[2] == 0)
            func_08077E6C(obj);
        break;
    }
}
