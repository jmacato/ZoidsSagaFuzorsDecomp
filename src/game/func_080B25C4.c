#include "types.h"

struct Obj
{
    u32 flags;
    u8 pad_4[0x8];
    void *field_C;
    u8 pad_10[0x7C];
    s32 field_8C;
};

void *func_080A0388(const void *, u16, u16, s16, u16, u16, u16, u32, s32, u8);

extern const u8 D_087AD370[];

void func_080B25C4(struct Obj *obj)
{
    obj->field_8C = 0;
    obj->field_C = func_080A0388(D_087AD370, 7, 0, 0x80, 0x50, 0, 0, (obj->flags & 2) ? 0x9298 : 0x1298, 0, (obj->flags >> 1) & 1);
}
