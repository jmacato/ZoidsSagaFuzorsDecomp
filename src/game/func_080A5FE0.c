#include "types.h"

struct Child
{
    u8 pad_00[0x30];
    s32 speed;
};

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    struct Child *child[32];
    u32 count;
    s32 field_90;
    s32 field_94;
};

extern u32 (*D_03000010)(void);

void func_080A3578(void *);
void func_080771F4(struct Child *);
struct Child *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
struct Child *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);
struct Child *func_080A37EC(void *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080A5FE0(struct Obj *obj)
{
    u8 i;

    if (obj->count < 8)
    {
        if (obj->count == 0)
        {
            obj->child[0] = func_080A34A8(obj, 1, 0, obj->field_90 - 256, obj->field_94, 0x10, func_080A3578, 1);
            obj->child[0]->speed = 32;
            func_080A38B0(0);
        }
        obj->child[obj->count + 1] = func_080A34A8(obj, 0, 0, obj->field_90 - 256 + obj->count * 32, obj->field_94, 0x400, 0, 1);
        obj->count++;
    }
    else if (obj->count == 8)
    {
        obj->child[9] = func_080A34A8(obj, 2, 0, obj->field_90, obj->field_94, 0x400, 0, 0);
        for (i = 0; i < 8; i++)
            obj->child[i + 10] = func_080A3770(obj, 5, 0, obj->field_90, obj->field_94, 0x400, i * 64 / 7 - 0x24 + (D_03000010() * 9 >> 15), (D_03000010() * 257 >> 15) + 0x100, 0);
        for (i = 0; i < 8; i++)
            obj->child[i + 18] = func_080A37EC(obj, 4, 0, obj->field_90, obj->field_94, 0x20, i * 64 / 7 - 0x24 + (D_03000010() * 9 >> 15), (D_03000010() * 513 >> 15) + 0x200, 0);
        func_080A12B0(6, 0);
        func_080A38B0(1);
        obj->count++;
    }
    else if (obj->count == 9)
    {
        for (i = 0; i < 26 && obj->child[i] == 0; i++)
            ;
        if (i == 26)
        {
            for (i = 0; i < 8; i++)
            {
                func_080771F4(obj->child[i]);
                obj->child[i] = func_080A3770(obj, 3, 0, obj->field_90, obj->field_94, 0, i * 16 / 7 + 0x76 + (D_03000010() * 5 >> 15), (D_03000010() * 1025 >> 15) + 0x200, 0);
            }
            for (i = 0; i < 8; i++)
                obj->child[i + 8] = func_080A3770(obj, 5, 0, obj->field_90, obj->field_94, 0x400, i * 64 / 7 + 0x5C + (D_03000010() * 9 >> 15), (D_03000010() * 257 >> 15) + 0x100, 0);
            obj->child[16] = func_080A34A8(obj, 2, 1, obj->field_90, obj->field_94, 0x400, 0, 0);
            for (i = 0; i < 8; i++)
                obj->child[i + 17] = func_080A37EC(obj, 4, 0, obj->field_90, obj->field_94, 0x20, i * 32 / 7 + 0x6C + (D_03000010() * 9 >> 15), (D_03000010() * 513 >> 15) + 0x200, 0);
            func_080A12B0(6, 0);
            func_080A38B0(2);
            obj->count++;
        }
    }
    else
    {
        for (i = 0; i < 25 && obj->child[i] == 0; i++)
            ;
        if (i == 25)
            func_08077E6C(obj);
    }
}
