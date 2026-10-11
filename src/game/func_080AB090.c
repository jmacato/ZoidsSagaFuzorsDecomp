#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    void *child[32];
    u32 count;
    s32 field_90;
    s32 field_94;
};

extern u32 (*D_03000010)(void);

s16 func_08075AAC(u8);
s16 func_08075AF8(u8);
u16 func_080C8B74(s16, s16);
u16 func_080C8B8C(u32);
void *func_080A34A8(void *, s32, u16, s16, s16, s32, void (*)(void *), s32);
void *func_080A3770(void *, s32, u16, s16, s16, s32, s32, s32, s32);
void *func_080A37EC(void *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_080A12B0(u8, s32);
s32 func_080A38B0(u8);
void func_08077E6C(struct Obj *);

void func_080AB090(struct Obj *obj)
{
    u8 i;
    u8 angle;
    s32 dy;
    s32 dx;
    s32 dist;

    if (obj->count < 8)
    {
        obj->child[obj->count] = func_080A34A8(obj, 0, 0, obj->field_90 - 224 + obj->count * 32, obj->field_94, 0x400, 0, 1);
        obj->count++;
    }
    else if (obj->count == 8)
    {
        for (i = 0; i < 8; i++)
            obj->child[i + 8] = func_080A3770(obj, 1, 0, obj->field_90, obj->field_94, 0,
                i * 16 / 7 - 10 + (D_03000010() * 5 >> 15), (D_03000010() * 1025 >> 15) + 0x200, 0);
        for (i = 0; i < 8; i++)
            obj->child[i + 16] = func_080A37EC(obj, 2, 0, obj->field_90, obj->field_94, 0x20,
                i * 32 / 7 - 20 + (D_03000010() * 9 >> 15), (D_03000010() * 513 >> 15) + 0x200, 0);
        for (i = 0; i < 16; i++)
        {
            angle = i * 16 + ((s32)(D_03000010() * 17 >> 15) - 8);
            dx = func_08075AF8(angle);
            dy = func_08075AAC(angle) * 3;
            angle = func_080C8B74(dx, dy) >> 8;
            dist = func_080C8B8C(dx * dx + dy * dy);
            dist -= dist * (s32)(D_03000010() * 129 >> 15) / 256;
            func_080A3770(obj, 3, 0, obj->field_90, obj->field_94, 0x500, angle, dist, 0);
        }
        func_080A12B0(6, 0);
        func_080A38B0(1);
        obj->count++;
    }
    else
    {
        for (i = 0; i < 24 && obj->child[i] == 0; i++)
            ;
        if (i == 24)
            func_08077E6C(obj);
    }
}
