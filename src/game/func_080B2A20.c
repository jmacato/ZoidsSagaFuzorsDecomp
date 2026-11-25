#include "types.h"

struct Obj
{
    u32 flags;
    u8 pad_4[0x8];
    void *field_C;
    void *field_10;
    u8 pad_14[0x78];
    s32 field_8C;
};

void *func_080A0388(const void *, u16, u16, s16, u16, u16, u16, u32, s32, u8);

extern const u8 D_087AD370[];

void func_080B2A20(struct Obj *obj)
{
    obj->field_8C = 0;
    obj->field_C = func_080A0388(D_087AD370, 0x7F, 0, 0x90, 0x26, 0, 0, (obj->flags & 2) ? 0x9298 : 0x1298, 0, (obj->flags >> 1) & 1);
    obj->field_10 = func_080A0388(D_087AD370, 0x7F, 0, 0x80, 0x27, 0, 0, (obj->flags & 2) ? 0x90D8 : 0x10D8, 0, (obj->flags >> 1) & 1);
}
