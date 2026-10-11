#include "types.h"

struct Obj
{
    u32 flags;
    u8 pad_04[0xA4];
    u32 field_A8;
};

extern s32 D_020378EC[][4];
extern const u8 D_087B14E8[];

void *func_080A0388(const void *, u16, u16, s16, s16, u16, u16, u32, s32, u8);

void *func_080A34A8(struct Obj *obj, s32 type, u16 a2, u16 x, u16 y, u32 attr, s32 a6, s32 mode)
{
    u32 mirror;

    if (!(mode & 1))
        mirror = (obj->flags & 2) ? 0x8000 : 0;
    else
        mirror = (obj->flags & 2) ? 0 : 0x8000;
    return func_080A0388(D_087B14E8, D_020378EC[type][0], a2, x, y, D_020378EC[type][1], D_020378EC[type][2], attr | obj->field_A8 | mirror, a6, (obj->flags & 2) && !(mode & 2));
}
