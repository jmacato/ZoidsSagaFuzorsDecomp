#include "types.h"

struct Vec3
{
    s32 x;
    s32 y;
    s32 z;
};

struct Slot
{
    u8 flags;
    u8 pad_1[0x3];
    u32 *attr;
    u8 pad_8[0x4];
    struct Vec3 pos;
};

struct Obj
{
    u8 pad_0[0xA4];
    s32 field_A4;
    s32 field_A8;
};

struct Child
{
    u8 pad_0[0x4];
    s32 x;
    s32 y;
    u8 pad_C[0x4];
    s16 scale;
    s16 field_12;
};

struct Point
{
    s16 x;
    s16 y;
};

struct Child *func_08076FE0(const void *, u16, u16, u32, u32, u16, u16, u32, u32);
s32 func_08076E48(struct Vec3 *, s16 *, s16 *);

extern struct Slot D_02037B6C[][6];
extern const u8 D_087B1D58[];

struct Child *func_080B2C38(struct Obj *obj, u16 kind, u16 a2, s16 dx, s16 dy, u8 pal, u32 flags)
{
    struct Slot *slot = &D_02037B6C[obj->field_A4][obj->field_A8];
    u16 tile;
    struct Child *child;
    s16 depth[2];
    s16 pt[2];

    if (kind < 3)
    {
        tile = 0;
    }
    else
    {
        switch (kind)
        {
        case 4:
            tile = 0x20;
            break;
        case 3:
            tile = 0;
            break;
        case 5:
            tile = 0x38;
            break;
        case 6:
            tile = 0x58;
            break;
        }
    }
    child = func_08076FE0(D_087B1D58, kind, a2, 0, 0, obj->field_A4 == 0 ? tile + 0x180 : tile,
                          (pal <= 5 && obj->field_A4 != 0) ? pal : pal + 6,
                          (*slot->attr & 0xC0) | flags | (obj->field_A4 != 0 ? 0x8000 : 0), 0);
    child->scale = child->field_12 = func_08076E48(&slot->pos, pt, depth);
    child->x = (pt[0] << 8) + (obj->field_A4 == 0 ? dx : -dx) * child->scale;
    child->y = (pt[1] << 8) + dy * child->scale;
    return child;
}
