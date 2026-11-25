#include "types.h"

struct Child
{
    u8 pad_0[0x1A];
    u16 field_1A;
    u8 pad_1C[0x14];
    s32 field_30;
};

struct Obj
{
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    struct Child *children[32];
    u32 field_8C;
    u32 field_90;
    s32 field_94;
    s32 field_98;
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

struct Child *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
struct Child *func_080A3770(struct Obj *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_080A38B0(u8);
void func_080A12B0(s32, s32);
void func_080ADE30(struct Obj *, s32);
void func_080771F4(void *);
void func_08077E6C(void *);
void func_080A3578(void);
u32 func_080C8BAC(s32);

extern s32 D_03000010;
extern struct Big D_02036E7C;
extern struct Scroll D_03000060;

void func_080B0640(struct Obj *obj)
{
    u8 i;

    switch (obj->field_8C)
    {
    case 0:
        if (obj->field_90 == 0)
            func_080A38B0(0);
        if ((obj->field_90 <= 0x30 || obj->children[0]->field_1A <= 7) && !(obj->field_90 & 1))
            func_080ADE30(obj, 1);
        if (obj->field_90 == 0x30)
        {
            obj->children[0] = func_080A34A8(obj, 0, 0, obj->field_4, obj->field_8, 0x500, 0, 0);
        }
        else if (obj->field_90 > 0x30 && obj->children[0] == 0)
        {
            for (i = 1; i < 32; i++)
            {
                if (obj->children[i] != 0)
                    func_080771F4(obj->children[i]);
            }
            obj->field_8C++;
        }
        obj->field_90++;
        break;
    case 1:
        for (i = 0; i < 8; i++)
            obj->children[i] = func_080A3770(obj, 2, 0, obj->field_4, obj->field_8, 0x500,
                (u8)((i << 5) / 7 + 0x6C + (s32)((func_080C8BAC(D_03000010) * 9) >> 15)),
                ((func_080C8BAC(D_03000010) * 513) >> 15) + 0x200, 0);
        for (i = 0; i < 6; i++)
            obj->children[i + 8] = func_080A3770(obj, 3, 0, obj->field_4, obj->field_8, 0x400,
                i * 4 - 10, ((func_080C8BAC(D_03000010) * 257) >> 15) + 0x300, 0);
        obj->children[31] = func_080A34A8(obj, 4, 0, obj->field_4, obj->field_8, 0x520, func_080A3578, 0);
        obj->children[31]->field_30 = 0x10;
        func_080A12B0(5, 0);
        obj->field_90 = 0;
        obj->field_94 = D_02036E7C.field_8A8;
        obj->field_98 = D_03000060.y;
        func_080A38B0(1);
        obj->field_8C++;
        break;
    case 2:
        if (!(obj->field_90 & 3))
            obj->children[(obj->field_90 >> 2) + 14] = func_080A3770(obj, 2, 0,
                obj->field_4 + (obj->field_94 - D_02036E7C.field_8A8) / 256,
                obj->field_8 + (obj->field_98 - D_03000060.y) / 256 + (obj->field_90 % 6 + (func_080C8BAC(D_03000010) >> 14) - 2),
                0x400, 0x80, 0x180, 0);
        if (++obj->field_90 == 50)
            obj->field_8C++;
        break;
    case 3:
        for (i = 0; i < 32; i++)
        {
            if (obj->children[i] != 0)
                break;
        }
        if (i == 32)
            func_08077E6C(obj);
        break;
    }
}
