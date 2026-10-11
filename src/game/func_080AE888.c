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
    u8 pad_94[0x14];
    u32 field_A8;
};

struct Child *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
struct Child *func_080A3770(struct Obj *, s32, u16, s16, s16, s32, s32, s32, s32);
struct Child *func_080A37EC(struct Obj *, s32, u16, s16, s16, s32, s32, s32, s32);
s32 func_080A38B0(u8);
void func_080A12B0(u8, s32);
void func_08077E6C(void *);

extern u32 (*D_03000010)(void);

void func_080AE888(struct Obj *obj)
{
    u8 i;
    u32 save;
    s16 x;
    s16 y;

    switch (obj->field_8C)
    {
    case 0:
        obj->children[0] = func_080A34A8(obj, 0, 1, obj->field_4 - 0x80, obj->field_8, 0x600, 0, 1);
        func_080A38B0(0);
        obj->field_8C++;
        break;
    case 1:
        if (obj->children[0]->field_1A == 4)
        {
            obj->children[1] = func_080A34A8(obj, 5, 0, obj->field_4, obj->field_8, 0x400, 0, 0);
            obj->field_8C++;
        }
        break;
    case 2:
        if (obj->children[0]->field_1A == 5)
        {
            save = obj->field_A8;
            obj->field_A8 = 0xC0;
            obj->children[2] = func_080A34A8(obj, 0, 1, obj->field_4 + 0x80, obj->field_8, 0x600, 0, 1);
            for (i = 0; i < 8; i++)
            {
                obj->children[3 + i] = func_080A37EC(obj, 3, 0, obj->field_4, obj->field_8, 0x20,
                    (i << 6) / 7 - 0x24 + (D_03000010() * 9 >> 15),
                    (D_03000010() * 513 >> 15) + 0x200, 0);
            }
            obj->field_A8 = save;
            func_080A12B0(6, 0);
            func_080A38B0(1);
            obj->field_8C++;
        }
        break;
    case 3:
        if (obj->children[0]->field_1A <= 0x15)
        {
            if (!(obj->field_90 & 3))
            {
                func_080A3770(obj, 4, 0, obj->field_4, obj->field_8 - 4, 0x500,
                    (D_03000010() * 33 >> 15) + 0x80,
                    (D_03000010() * 257 >> 15) + 0x100, 0);
                func_080A3770(obj, 4, 0, obj->field_4, obj->field_8 + 4, 0x500,
                    (D_03000010() * 33 >> 15) + 0x60,
                    (D_03000010() * 257 >> 15) + 0x100, 0);
            }
            obj->field_90++;
        }
        for (i = 0; i < 11 && obj->children[i] == 0; i++)
            ;
        if (i == 11)
        {
            obj->field_90 = 0;
            obj->field_8C++;
        }
        break;
    case 4:
        if (!(obj->field_90 & 1))
        {
            x = obj->field_4 + (D_03000010() * 9 >> 15) - 4;
            y = obj->field_8 + (D_03000010() * 9 >> 15) - 4;
            obj->children[i] = func_080A34A8(obj, 1, 0, x, y, 0, 0, 0);
            obj->children[i + 8] = func_080A3770(obj, 2, 0, x, y, 0x100, 0x80,
                ((D_03000010() * 1025 >> 15) + 0x200) * 2, 0);
            obj->children[i + 16] = func_080A37EC(obj, 3, 0, x, y, 0x120, 0x80,
                ((D_03000010() * 513 >> 15) + 0x200) * 2, 0);
            save = obj->field_A8;
            obj->field_A8 = 0xC0;
            obj->children[i + 24] = func_080A3770(obj, 2, 0, x, y, 0, 0,
                ((D_03000010() * 1025 >> 15) + 0x200) * 2, 0);
            obj->field_A8 = save;
            if (obj->field_90 == 0)
            {
                func_080A12B0(6, 0);
                func_080A38B0(1);
            }
        }
        if (++obj->field_90 == 16)
            obj->field_8C++;
        break;
    case 5:
        for (i = 0; i < 32 && obj->children[i] == 0; i++)
            ;
        if (i == 32)
            func_08077E6C(obj);
        break;
    }
}
