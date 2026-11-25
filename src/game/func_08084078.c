#include "types.h"

struct Actor
{
    u8 flags;
    u8 id;
    u8 pad_2;
    u8 field_3;
    s32 x;
    s32 y;
};

struct Map
{
    u8 pad_0[0x14];
    u16 width;
    u16 height;
    u8 pad_18[0x40C];
    struct Actor *current;
    u8 field_428;
};

struct Script
{
    u8 field_0;
    u8 pad_1[0x1134];
    u8 field_1135;
    u8 pad_1136[2];
    s32 field_1138;
    s32 field_113C;
    u16 field_1140;
};

struct Cam
{
    s32 x;
    s32 y;
};

extern struct Script D_0201F6DC;
extern struct Map D_020209D8;
extern struct Cam D_03000060;
u16 func_080C8B8C(s32);

void func_08084078(struct Actor *a, u8 mode)
{
    s32 dx, dy;
    if (a->field_3 == 0)
        D_020209D8.current = a;
    if (mode != 0 && mode != 6 && (a->field_3 == 0 || a->field_3 == 6))
    {
        D_0201F6DC.field_1138 = a->x - 0x7800;
        D_0201F6DC.field_113C = a->y - 0x5000;
        if (D_0201F6DC.field_1138 < 0)
            D_0201F6DC.field_1138 = 0;
        if (D_0201F6DC.field_1138 > (D_020209D8.width << 11) - 0xF000)
            D_0201F6DC.field_1138 = (D_020209D8.width << 11) - 0xF000;
        if (D_0201F6DC.field_113C < 0)
            D_0201F6DC.field_113C = 0;
        if (D_0201F6DC.field_113C > (D_020209D8.height << 11) - 0xA000)
            D_0201F6DC.field_113C = (D_020209D8.height << 11) - 0xA000;
        dx = (D_0201F6DC.field_1138 - D_03000060.x) / 256;
        dy = (D_0201F6DC.field_113C - D_03000060.y) / 256;
        D_0201F6DC.field_1140 = func_080C8B8C(dx * dx + dy * dy);
        D_0201F6DC.field_1135 = 1;
        D_020209D8.field_428 = 1;
    }
}
