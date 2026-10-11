#include "types.h"

struct Obj
{
    u8 pad_0[0x8C];
    s32 field_8C;
};

struct Big
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[0x95A];
    u32 **field_95C;
};

struct PalState
{
    u8 pad_0[0x8];
    s32 field_8;
};

void func_080A12B0(s32, s32);
void func_080A38B0(u8);
void func_080C8B84(const void *, void *);

extern const void *const D_087B1940[];
extern struct Big D_02036E7C;
extern struct PalState D_020378EC;
extern u16 D_03000056;
extern u16 D_03000058;
extern u16 D_0300005A;

void func_080B1670(struct Obj *obj)
{
    obj->field_8C = 0;
    func_080A12B0(0x11, 0);
    func_080C8B84(D_087B1940[D_02036E7C.field_1], (u16 *)0x05000200 + D_020378EC.field_8 * 16);
    D_03000056 = 0xD91;
    D_03000058 = 0x10;
    D_0300005A = 0;
    if (D_02036E7C.field_95C != 0 && *D_02036E7C.field_95C != 0)
        **D_02036E7C.field_95C |= 0x400;
    func_080A38B0(0);
}
