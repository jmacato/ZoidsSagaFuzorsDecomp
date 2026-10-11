#include "types.h"

struct Slot
{
    u8 pad_0[0xC];
    s32 field_C;
    u8 pad_10[0x8];
};

struct Obj
{
    u8 pad_0[0x8C];
    u32 field_8C;
    u8 pad_90[0x14];
    s32 field_A4;
    s32 field_A8;
};

void func_080B2D78(struct Obj *);

extern struct Slot D_02037B6C[][6];
extern const s32 D_08736488[];

void func_080B2E2C(struct Obj *obj)
{
    if (obj->field_8C < 9)
    {
        D_02037B6C[obj->field_A4][obj->field_A8].field_C += D_08736488[obj->field_8C];
        obj->field_8C++;
    }
    func_080B2D78(obj);
}
