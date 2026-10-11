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
    u8 pad28[4];
    u32 field_2C;
    u8 pad30[0x10];
};

extern struct Sprite D_030031C8[128];

struct Sprite *func_080770CC(u32 x, u32 y, u16 tile, u32 a3, u32 a4, u16 a5, u16 a6, u32 flags, u32 a8)
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
    sprite->x = x;
    sprite->y = y;
    sprite->field_2C = a8;
    return sprite;
}
