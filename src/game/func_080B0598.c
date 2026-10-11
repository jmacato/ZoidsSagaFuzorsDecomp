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
    struct Child *field_C;
    u8 pad_10[0x7C];
    s32 field_8C;
};

struct PalState
{
    u8 pad_0[0x8];
    s32 field_8;
};

struct Child *func_080A34A8(struct Obj *, s32, u16, s16, s16, s32, void *, s32);
void func_080A38B0(u8);
void func_08077E6C(void *);
void func_0807806C(const void *, void *, s32);

extern const u8 D_08735B1C[];
extern const u16 D_0873595C[][16];
extern struct PalState D_020378EC;

void func_080B0598(struct Obj *obj)
{
    if (obj->field_8C == 0)
    {
        obj->field_C = func_080A34A8(obj, 0, 1, 0x80, obj->field_8, 0x400, 0, 1);
        func_080A38B0(0);
        obj->field_8C++;
    }
    else if (obj->field_C == 0)
    {
        func_08077E6C(obj);
    }
    else if (obj->field_C->field_1C == 0)
    {
        func_0807806C(D_0873595C[D_08735B1C[obj->field_C->field_1A]], (u16 *)0x05000200 + D_020378EC.field_8 * 16, 0x20);
    }
}
