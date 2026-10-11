#include "types.h"

struct Child
{
    u8 pad_0[0x1A];
    u16 field_1A;
    u16 field_1C;
};

struct Obj
{
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    struct Child *children[32];
    s32 field_8C;
    s32 field_90;
    u32 field_94;
};

struct PalState
{
    u8 pad_0[0x8];
    s32 field_8;
};

struct Child *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
struct Child *func_080A37EC(struct Obj *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_080A38B0(u8);
void func_080A12B0(s32, s32);
void func_08077E6C(void *);
void func_0807806C(const void *, void *, s32);
s16 func_08075AAC(s16);
s32 func_080C8BAC(s32);

extern s32 D_03000010;
extern const u8 D_08735B1C[];
extern const u16 D_0873595C[][16];
extern struct PalState D_020378EC;

void func_080B03A0(struct Obj *obj)
{
    u8 amp;
    u16 x;
    s16 y;
    u8 i;

    if (obj->field_8C == 0)
    {
        obj->children[0] = func_080A34A8(obj, 0, 1, 0x80, obj->field_8, 0x600, 0, 1);
        func_080A38B0(0);
        obj->field_8C++;
    }
    else if (obj->field_90 == 0 && obj->children[0]->field_1A == 2)
    {
        obj->field_90 = 1;
        func_080A12B0(6, 0);
        func_080A38B0(1);
    }
    if (obj->children[0] != 0 && obj->children[0]->field_1C == 0)
        func_0807806C(D_0873595C[D_08735B1C[obj->children[0]->field_1A]], (u16 *)0x05000200 + D_020378EC.field_8 * 16, 0x20);
    if (obj->field_90 != 0 && obj->field_94 <= 14)
    {
        amp = func_08075AAC((obj->field_94 << 7) / 14) / 4;
        x = obj->field_4 + obj->field_94 * 8 - 0x20;
        y = obj->field_8 + amp * (obj->field_94 & 3) / 3 - amp / 2 + (((u32)(func_080C8BAC(D_03000010) * 9) >> 15) - 4);
        obj->children[obj->field_94 + 1] = func_080A34A8(obj, 1, 0, x, y, 0x100, 0, 0);
        obj->children[obj->field_94 + 16] = func_080A37EC(obj, 2, 0, x, y, 0x20, 0, ((u32)(func_080C8BAC(D_03000010) * 257) >> 15) + 0x200, 0);
        obj->field_94++;
    }
    if (obj->field_94 == 15)
    {
        for (i = 0; i < 31; i++)
        {
            if (obj->children[i] != 0)
                break;
        }
        if (i == 31)
            func_08077E6C(obj);
    }
}
