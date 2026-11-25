#include "types.h"

struct Child
{
    u32 flags;
    u8 pad_4[0xC];
    s16 field_10;
    s16 field_12;
};

struct Obj
{
    u8 pad_0[0xC];
    struct Child *field_C;
    struct Child *field_10;
    struct Child *field_14;
    u8 pad_18[0x74];
    u32 field_8C;
    u8 pad_90[0x14];
    s32 field_A4;
    s32 field_A8;
};

struct Child *func_080B2C38(struct Obj *, u16, u16, s16, s16, u8, u32, s32);
void func_08075F20(u16);
s32 func_080C8BE8(s32, s32);
void func_0809F724(u8, u8);
void func_080B2D78(struct Obj *);

void func_080B2EF8(struct Obj *obj)
{
    struct Child *c;

    if (obj->field_8C < 22)
    {
        if (obj->field_8C == 20)
        {
            obj->field_10 = func_080B2C38(obj, 1, 0, 0, -0x20, 0, 0x300, 0);
            obj->field_10->field_10 *= 2;
            obj->field_10->field_12 *= 2;
            if (obj->field_10->field_10 > 0x100)
                obj->field_10->flags |= 0x80000;
            func_08075F20(0xF1);
        }
        else if (obj->field_8C == 21)
        {
            obj->field_14 = func_080B2C38(obj, 1, 0, 0, -0x40, 0, 0x200, 0);
            c = obj->field_14;
            c->field_10 = func_080C8BE8(obj->field_C->field_10 * 15, 10);
            c = obj->field_14;
            c->field_12 = func_080C8BE8(obj->field_C->field_12 * 15, 10);
            if (obj->field_14->field_10 > 0x100)
                obj->field_14->flags |= 0x80000;
            func_0809F724(obj->field_A4, obj->field_A8);
        }
        obj->field_8C++;
    }
    func_080B2D78(obj);
}
