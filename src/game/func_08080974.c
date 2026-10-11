#include "types.h"

struct Sprite
{
    u8 pad_0[0xC];
    u16 x;
    u16 y;
};

struct Actor
{
    u8 flags;
    u8 id;
    u8 owner;
    u8 kind;
    s32 x;
    s32 y;
    u8 pad_C[9];
    u8 field_15;
    u8 dir;
    u8 pad_17[5];
    struct Sprite *obj1;
    struct Sprite *obj2;
    u32 data[8];
};

struct Save
{
    u8 pad_0[0x7B00];
    u32 flags[1];
};

extern struct Save D_02020E4C;
extern const u8 D_087B1D90[];
extern const u8 D_085BF19C[];
extern const u8 D_085BF1A8[];
extern s32 D_08734B24[][2];
s32 func_080808CC(struct Actor *);
struct Sprite *func_08076FE0(const u8 *, u8, u16, s32, s32, s32, u8, u32, s32);
struct Sprite *func_080770CC(const u8 *, const u8 *, s32, s32, s32, s32, s32, s32, s32);
void func_08082FE4(u8);
void func_080830F4(u8, u8, u8, u16, u16, u8, u8);

void func_08080974(struct Actor *a)
{
    u16 frame;
    s32 pal;
    a->field_15 = 0;
    if (a->id == 0xB0)
    {
        a->obj1 = a->obj2 = 0;
        return;
    }
    if (a->kind != 5)
        frame = func_080808CC(a);
    else
        frame = (D_02020E4C.flags[a->data[0] >> 5] & (1 << (a->data[0] & 0x1F))) != 0;
    pal = a->owner << 4;
    a->obj1 = func_08076FE0(D_087B1D90, a->id, frame, a->x, a->y, pal, a->owner,
                            (a->id != 0x82 ? 0x4412C0 : 0x441280) | (a->kind != 5 ? 0x20 : 0x10), 0);
    if (a->kind != 2 && a->kind != 4 && a->kind != 5 && a->id != 0x67 && (a->id <= 0x87 || a->id == 0x8A))
    {
        a->obj2 = func_080770CC(D_085BF19C, D_085BF1A8, 0, a->x, a->y, 0x36A, 15, 0x12C8, 0);
        a->obj2->y += 0xE;
    }
    else
        a->obj2 = 0;
    if (a->kind != 2)
    {
        if (a->kind == 5)
            a->obj1->y = 8;
        else if (a->id <= 0x87)
        {
            if (a->kind != 4)
                a->obj1->y -= 2;
            else
            {
                a->obj1->x -= D_08734B24[a->dir][0] / 16;
                a->obj1->y -= D_08734B24[a->dir][1] / 16;
            }
        }
        else if (a->id == 0x8A && a->kind != 0xFF)
            a->obj1->y = 0xFFF0;
    }
    if (a->id == 0x9C)
    {
        func_08082FE4(8);
        func_080830F4(0, 8, 0, 0x960, 0x1C8, 1, 1);
    }
}
