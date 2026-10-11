#include "types.h"

struct Obj
{
    u8 pad0[6];
    u16 field_6;
    u16 field_8;
    u8 padA[0x58];
    u16 field_62;
    u16 field_64;
};

struct Slot
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 flags;
    u8 pad4[0x3C];
};

extern struct Slot D_0203378C[][7];

void func_080BE46C(u8, u8);
struct Obj *func_0809A908(u8, u8);

void func_080BFFA4(u8 a, u8 b, u8 c)
{
    struct Slot *s = &D_0203378C[a][c];
    struct Obj *obj;
    s->flags |= 0x80;
    func_080BE46C(a, b);
    obj = func_0809A908(a, b);
    obj->field_6 = obj->field_62;
    obj->field_8 = obj->field_64;
}
