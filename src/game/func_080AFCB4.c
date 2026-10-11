#include "types.h"

struct Obj
{
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    u8 pad_C[0x80];
    u32 field_8C;
};

void *func_080A3770(struct Obj *, s32, u16, s16, s16, s32, s32, s32, s32);
u8 func_080796EC(void);
void func_0807806C(const void *, void *, s32);
void func_08077E6C(void *);

extern u32 (*D_03000010)(void);

extern u16 D_0203796C[2][64];
extern u16 D_02037A6C[2][48];

void func_080AFCB4(struct Obj *obj)
{
    u8 i;
    u8 r;
    u8 g;
    u8 b;

    func_080A3770(obj, 0, 0,
        obj->field_4 + ((u32)(D_03000010() * 65) >> 15) - 0x20,
        obj->field_8 + ((u32)(D_03000010() * 65) >> 15) - 0x20,
        0, 0, ((u32)(D_03000010() * 257) >> 15) + 0x200, 0);
    if (obj->field_8C == 0)
    {
        if (func_080796EC())
            obj->field_8C = 1;
        if (obj->field_8C == 0)
            return;
    }
    if (obj->field_8C < 32)
    {
        for (i = 0; i < 64; i++)
        {
            r = D_0203796C[0][i] & 31;
            g = (D_0203796C[0][i] >> 5) & 31;
            b = (D_0203796C[0][i] >> 10) & 31;
            r = r + (((31 - r) * (31 - obj->field_8C)) >> 5);
            g = g + (((31 - g) * (31 - obj->field_8C)) >> 5);
            b = b + (((31 - b) * (31 - obj->field_8C)) >> 5);
            D_0203796C[1][i] = r | (g << 5) | (b << 10);
        }
        for (i = 0; i < 48; i++)
        {
            r = D_02037A6C[0][i] & 31;
            g = (D_02037A6C[0][i] >> 5) & 31;
            b = (D_02037A6C[0][i] >> 10) & 31;
            r = r + (((31 - r) * (31 - obj->field_8C)) >> 5);
            g = g + (((31 - g) * (31 - obj->field_8C)) >> 5);
            b = b + (((31 - b) * (31 - obj->field_8C)) >> 5);
            D_02037A6C[1][i] = r | (g << 5) | (b << 10);
        }
        func_0807806C(D_0203796C[1], (void *)0x05000000, 0x80);
        func_0807806C(D_02037A6C[1], (void *)0x05000200, 0x60);
        obj->field_8C++;
    }
    else
    {
        func_08077E6C(obj);
    }
}
