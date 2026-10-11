#include "types.h"

struct Map
{
    u8 pad_0[0x14];
    u16 width;
    u16 height;
    u8 pad_18[2];
    u16 field_1A;
};

struct Cam
{
    s32 x;
    s32 y;
};

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    u8 pad_C[0x24];
    s32 field_30;
};

extern struct Map D_020209D8;
extern struct Cam D_03000060;
extern s16 D_08785D6C[][26][3];

void func_08087DD0(struct Obj *obj)
{
    s16 *e = D_08785D6C[D_020209D8.field_1A][obj->field_30];
    if (D_03000060.x < (D_020209D8.width - 0x20) << 11 || (e[1] << 11) >= D_03000060.x - 0x10000)
        obj->x = e[1] << 11;
    else
        obj->x = (e[1] + D_020209D8.width) << 11;
    if (D_03000060.y < (D_020209D8.height - 0x20) << 11 || (e[2] << 11) >= D_03000060.y - 0x10000)
        obj->y = e[2] << 11;
    else
        obj->y = (e[2] + D_020209D8.height) << 11;
}
