#include "types.h"

struct Obj
{
    u8 pad_0[0x8C];
    s32 field_8C;
};

void func_080C8B78(const void *, void *, u32);
void func_080C8B7C(const void *, void *, u32);
void func_0807806C(const void *, void *, s32);

extern u16 D_0203796C[];
extern u16 D_02037A6C[];

void func_080AFC28(struct Obj *obj)
{
    vu16 bg;
    vu16 sp;
    u16 *bgPal;
    u16 *objPal;

    obj->field_8C = 0;
    bgPal = (u16 *)0x05000000;
    func_080C8B78(bgPal, D_0203796C, 0x20);
    objPal = (u16 *)0x05000200;
    func_080C8B78(objPal, D_02037A6C, 0x18);
    bg = 0x7FFF;
    func_080C8B7C((void *)&bg, D_0203796C + 0x40, 0x01000040);
    sp = 0x7FFF;
    func_080C8B7C((void *)&sp, D_02037A6C + 0x30, 0x01000030);
    func_0807806C(D_0203796C + 0x40, bgPal, 0x80);
    func_0807806C(D_02037A6C + 0x30, objPal, 0x60);
}
