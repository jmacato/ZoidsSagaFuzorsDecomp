#include "types.h"

struct Child
{
    u32 flags;
};

struct Obj
{
    u8 pad_0[0xC];
    struct Child *children[32];
    u32 field_8C;
    u32 field_90;
};

struct Big
{
    u8 pad_0[0x95C];
    u32 **field_95C;
};

struct Child *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
struct Child *func_080A3770(struct Obj *, s32, u16, s16, s16, s32, s32, s32, s32);
void func_080A38B0(u8);
void func_08077E6C(void *);
void func_08077204(void *, u16);
void func_080771F4(void *);
u32 func_080C8BAC(s32);

extern s32 D_03000010;
extern struct Big D_02036E7C;
extern u16 D_03000056;
extern u16 D_03000058;
extern u16 D_0300005A;

void func_080B0B8C(struct Obj *obj)
{
    if (obj->field_8C <= 2)
        func_080A3770(obj, 1, 0, 0x78, 0x40, 0x400, func_080C8BAC(D_03000010) >> 7, ((func_080C8BAC(D_03000010) * 257) >> 15) + 0x200, 2);
    switch (obj->field_8C)
    {
    case 0:
        obj->children[0] = func_080A34A8(obj, 0, 0, 0x78, 0x40, 0x520, 0, 2);
        func_080A38B0(0);
        obj->field_8C++;
        break;
    case 1:
        if (obj->children[0]->flags & 4)
        {
            obj->children[1] = func_080A34A8(obj, 2, 0, 0x78, 0x80, 0x110, 0, 2);
            func_080A38B0(1);
            obj->field_8C++;
        }
        break;
    case 2:
        if (obj->children[1]->flags & 4)
        {
            func_08077204(obj->children[1], 1);
            obj->children[1]->flags = (obj->children[1]->flags & ~0x30) | 0x20;
            func_080771F4(obj->children[0]);
            obj->field_90 = 0;
            obj->field_8C++;
        }
        break;
    case 3:
        if (++obj->field_90 == 60)
        {
            D_03000056 = 0xD95;
            D_03000058 = 0x10;
            D_0300005A = 0;
            if (D_02036E7C.field_95C != 0 && *D_02036E7C.field_95C != 0)
                **D_02036E7C.field_95C |= 0x400;
            obj->field_90 = 0;
            obj->field_8C++;
        }
        break;
    case 4:
        obj->field_90++;
        D_0300005A = obj->field_90 >> 2;
        if (obj->field_90 == 64)
        {
            func_080771F4(obj->children[1]);
            obj->field_90 = 0;
            obj->field_8C++;
        }
        break;
    case 5:
        func_080A34A8(obj, 3, 0, (s32)(func_080C8BAC(D_03000010) * 480) >> 16, (s32)(func_080C8BAC(D_03000010) * 256) >> 16, 0x400, 0, 2);
        if (!(obj->field_90 & 7))
            func_080A38B0(2);
        if (++obj->field_90 == 60)
            func_08077E6C(obj);
        break;
    }
}
