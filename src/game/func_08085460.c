#include "types.h"

struct Actor
{
    u8 flags;
    u8 pad_1[3];
    s32 x;
    s32 y;
    u8 pad_C[0x38];
};

struct Map
{
    u8 pad_0[0x14];
    u16 width;
    u16 height;
    u8 pad_18[0x54];
    struct Actor actors[14];
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

extern struct Script D_0201F6DC;
extern struct Map D_020209D8;
u8 func_08080C54(u8);
void func_08083C5C(u8, s32, s32);

s32 func_08085460(u8 id, u8 **pc)
{
    struct Script *script = &D_0201F6DC;
    u8 slot;
    s32 lo = 0;
    script->field_0 = 1;
    slot = func_08080C54((*pc)[1]);
    if (slot != 0xFF)
    {
        script->field_1138 = D_020209D8.actors[slot].x - 0x7800;
        script->field_113C = D_020209D8.actors[slot].y - 0x5000;
        if (script->field_1138 < lo)
            script->field_1138 = lo;
        if (script->field_1138 > (D_020209D8.width << 11) - 0xF000)
            script->field_1138 = (D_020209D8.width << 11) - 0xF000;
        if (script->field_113C < lo)
            script->field_113C = lo;
        if (script->field_113C > (D_020209D8.height << 11) - 0xA000)
            script->field_113C = (D_020209D8.height << 11) - 0xA000;
        script->field_1140 = ((*pc)[3] << 8) | (*pc)[2];
        script->field_1135 = 1;
    }
    func_08083C5C(id, -1, 0);
    return 0;
}
