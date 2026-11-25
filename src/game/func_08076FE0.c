#include "types.h"

struct Sprite
{
    u32 flags;
    u32 field_4;
    u32 field_8;
    u16 field_C;
    u16 field_E;
    u16 scaleX;
    u16 scaleY;
    u16 field_14;
    u8 field_16;
    u8 field_17;
    u16 tile;
    u16 field_1A;
    u16 field_1C;
    u8 pad1E[2];
    u32 x;
    u32 y;
    u32 field_28;
    u32 field_2C;
    u8 pad30[0x10];
};

extern struct Sprite D_030031C8[128];

struct Frame
{
    u32 x;
    u32 y;
};

struct PalFrame
{
    u32 x;
    u32 y;
    u32 field_8;
    const void *pal;
};

void func_080C8B78(const void *, void *, u32);

struct Sprite *func_08076FE0(const void *table, u16 frame, u16 tile, u32 a3, u32 a4, u16 a5, u16 a6, u32 flags, u32 a8)
{
    s16 i;
    struct Sprite *sprite;

    for (i = 127; i >= 0; i--)
    {
        sprite = &D_030031C8[i];
        if (!(sprite->flags & 3))
            break;
    }
    if (i == -1)
        return 0;
    sprite->flags = flags | 1;
    sprite->field_4 = a3;
    sprite->field_8 = a4;
    sprite->field_C = sprite->field_E = 0;
    sprite->field_17 = 0;
    sprite->scaleX = sprite->scaleY = 0x100;
    sprite->field_14 = a5;
    sprite->field_16 = a6;
    sprite->tile = tile;
    sprite->field_1A = 0;
    sprite->field_1C = 0;
    if (!(flags & 0x400000))
    {
        const struct Frame *f = &((const struct Frame *)table)[frame];
        sprite->x = f->x;
        sprite->y = f->y;
    }
    else
    {
        const struct PalFrame *f = &((const struct PalFrame *)table)[frame];
        sprite->x = f->x;
        sprite->y = f->y;
        sprite->field_28 = f->field_8;
        func_080C8B78(f->pal, (void *)(0x05000200 + sprite->field_16 * 32), 8);
    }
    sprite->field_2C = a8;
    return sprite;
}
