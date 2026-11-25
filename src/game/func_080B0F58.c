#include "types.h"

struct Child
{
    u8 pad_0[0x30];
    s32 field_30;
};

struct Obj
{
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    struct Child *children[32];
    u32 field_8C;
};

struct Big
{
    u8 pad_0[0x8A8];
    s32 field_8A8;
};

struct Child *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
struct Child *func_080A3770(struct Obj *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_080A38B0(u8);
void func_08077E6C(void *);
void func_080A3578(void);
s32 func_080C8BAC(s32);

extern struct Big D_02036E7C;
extern s32 D_02037724;
extern s32 D_03000010;
extern const u8 D_08735B44[];

void func_080B0F58(struct Obj *obj)
{
    u8 i;
    u8 r;
    s32 y;

    switch (obj->field_8C)
    {
    case 0:
        obj->children[0] = func_080A34A8(obj, 0, 0, 0x80 - D_02036E7C.field_8A8 / 256, 8, 0x400, 0, 0);
        func_080A38B0(0);
        obj->field_8C++;
        break;
    case 1:
        for (i = 1; i < 32; i++)
        {
            if (obj->children[i] == 0)
            {
                s32 *scroll;

                r = (u32)(func_080C8BAC(D_03000010) * 17) >> 15;
                y = ((u32)(func_080C8BAC(D_03000010) * 257) >> 15) + 0x200;
                scroll = &D_02037724;
                obj->children[i] = func_080A3770(obj, 1, 0, D_08735B44[r] + 0x80 - *scroll / 256, r + 16, 0x500, 0, y, 0);
                break;
            }
        }
        if (obj->children[0] == 0)
        {
            obj->children[0] = func_080A34A8(obj, 2, 0, obj->field_4, obj->field_8, 0x420, func_080A3578, 0);
            obj->children[0]->field_30 = 0x10;
            func_080A38B0(1);
            obj->field_8C++;
        }
        break;
    case 2:
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
