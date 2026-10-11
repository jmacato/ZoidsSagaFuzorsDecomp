#include "types.h"

struct Actor
{
    u8 flags;
    u8 owner;
    u8 id;
    u8 kind;
    s32 x;
    s32 y;
    s32 field_C;
    s32 field_10;
    u8 field_14;
    u8 pad_15;
    u8 dir;
    u8 dir2;
    u8 field_18;
    u8 field_19;
    u8 pad_1A[0xA];
    u32 data[8];
};

struct Map
{
    u8 pad_0[0x6C];
    struct Actor actors[14];
};

extern struct Map D_020209D8;
extern s32 D_08734B24[][2];
void func_08080974(struct Actor *);
void func_0808071C(struct Actor *);

struct Actor *func_08080B00(u8 owner, u8 id, s32 x, s32 y, u8 dir, u8 flags, u8 kind, u32 data)
{
    u8 i, slot;
    struct Actor *a;
    if (id > 13)
        return 0;
    slot = 0xFF;
    for (i = 0; i < 14; i++)
    {
        if (!(D_020209D8.actors[i].flags & 1))
        {
            if (slot == 0xFF)
                slot = i;
        }
        else if (D_020209D8.actors[i].id == id)
            break;
    }
    if (i < 14 || slot == 0xFF)
        return 0;
    a = &D_020209D8.actors[slot];
    a->flags = flags | 1;
    a->owner = owner;
    a->id = id;
    a->kind = kind;
    a->x = x;
    a->y = y;
    if (kind == 4)
    {
        a->x = (D_08734B24[dir][0] << 4) + x;
        a->y = (D_08734B24[dir][1] << 4) + y;
    }
    a->field_C = a->field_10 = 0;
    a->field_14 = 0;
    a->dir = a->dir2 = dir;
    a->field_18 = 0;
    if (kind != 5)
    {
        for (i = 0; i < 8; i++)
            a->data[i] = 0;
    }
    else
        a->data[0] = data;
    func_08080974(a);
    func_0808071C(a);
    a->field_19 = 0;
    return a;
}
