#include "types.h"

struct Obj
{
    u8 active;
    u8 pad1[0x43];
};

struct FieldState
{
    u8 pad0[0x6C];
    struct Obj objs[14];
    u32 field_424;
    u8 field_428;
    u8 field_429;
};

struct Event
{
    u8 flags;
    u8 type;
    u8 pos;
    u8 kind;
    s16 x;
    s16 y;
};

struct Save
{
    u8 pad0[0x7A70];
    struct Event events[14];
};

extern struct FieldState D_020209D8;
extern struct Save D_02020E4C;
extern u8 D_0201F5F5;

void func_08080B00(u8, u8, s32, s32, u8, u8, u8, u32);

void func_08080640(void)
{
    u8 i;

    for (i = 0; i < 14; i++)
        D_020209D8.objs[i].active = 0;
    D_020209D8.field_428 = 0;
    D_020209D8.field_429 = 0xFF;
    D_020209D8.field_424 = 0;
    if (D_0201F5F5)
    {
        for (i = 0; i < 14; i++)
        {
            if ((D_02020E4C.events[i].flags & 1) && D_02020E4C.events[i].kind != 0 && D_02020E4C.events[i].kind != 5)
                func_08080B00(D_02020E4C.events[i].type, D_02020E4C.events[i].pos >> 4, D_02020E4C.events[i].x << 8, D_02020E4C.events[i].y << 8, D_02020E4C.events[i].pos & 0xF, D_02020E4C.events[i].flags, D_02020E4C.events[i].kind, 0);
        }
    }
}
