#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
};

struct Task
{
    u8 pad_0[0x8C];
    s32 field_8C;
};

struct AnimFrame
{
    s32 offset;
    s32 duration;
};

struct Pair
{
    u16 field_0;
    u16 id;
};

struct Tiles
{
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    u16 data[1];
};

struct State
{
    u8 stage;
    u8 pad_1[0x73];
    struct Pair pairs[4];
    u8 pad_84[0x14];
    u8 mirror;
    u8 pad_99;
    u8 field_9A;
    u8 field_9B;
    u8 field_9C;
    u8 pad_9D;
    u16 frame;
    u16 timer;
    u8 pad_A2[2];
    s32 anim[1];
};

extern struct State D_02036E7C;
extern struct Obj *D_02030B4C[3];
extern struct Task *D_02030B48;
extern u16 D_02001920[];
extern const s16 D_087AD848[][8][2];
extern const s16 D_087B0FC4[];
extern const u8 D_087AEBA8[][3];

void func_08075F20(u16 se);
void func_080780C0(const void *src, u8 a, u16 x, u16 y, u16 w, u16 h);

void func_080A0758(void)
{
    s32 done;
    u8 i, k;
    u16 x;
    s16 center;
    if (D_02036E7C.field_9B == 0)
        return;
    if (D_02036E7C.field_9A <= 3)
    {
        if (D_02036E7C.field_9A <= 2 && D_02030B4C[D_02036E7C.field_9A] != 0 && (D_02030B4C[D_02036E7C.field_9A]->flags & 4))
        {
            D_02036E7C.field_9B = 0;
            D_02036E7C.field_9C = 1;
        }
        return;
    }
    if (D_02036E7C.field_9B == 1)
    {
        if (D_02036E7C.timer == D_02036E7C.anim[D_02036E7C.frame * 2 + 1])
        {
            done = 0;
            do
            {
                D_02036E7C.frame++;
                while (D_02036E7C.anim[D_02036E7C.frame * 2] == -3)
                {
                    func_08075F20(D_02036E7C.anim[D_02036E7C.frame * 2 + 1]);
                    D_02036E7C.frame++;
                }
                if (D_02036E7C.anim[D_02036E7C.frame * 2] == -1)
                {
                    D_02036E7C.field_9B = 0;
                    D_02036E7C.field_9C = 1;
                    return;
                }
                if (D_02036E7C.anim[(D_02036E7C.frame + 1) * 2] == -2)
                {
                    D_02036E7C.field_9C = 1;
                    done = 1;
                    break;
                }
            } while (D_02036E7C.anim[D_02036E7C.frame * 2 + 1] == 0);
            if (D_02036E7C.anim[D_02036E7C.frame * 2] != 0)
            {
                struct Tiles *t = (struct Tiles *)((u8 *)D_02036E7C.anim + D_02036E7C.anim[D_02036E7C.frame * 2]);
                if (D_02036E7C.mirror == 0)
                    func_080780C0(t->data, 0, t->x, t->y, t->w, t->h);
                else
                {
                    u16 *dst = D_02001920;
                    u16 row, col;
                    for (row = 0; row < t->h; row++)
                    {
                        u16 *src = &t->data[(row + 1) * t->w] - 1;
                        for (col = 0; col < t->w; col++)
                        {
                            *dst = *src ^ 0x400;
                            dst++;
                            src--;
                        }
                    }
                    func_080780C0(D_02001920, 0, 0x20 - t->w - t->x, t->y, t->w, t->h);
                }
                if (done)
                    D_02036E7C.frame = 0;
            }
            D_02036E7C.timer = 0;
            if ((((D_02036E7C.stage == 0x30 && D_02036E7C.field_9A == 6) || (D_02036E7C.stage == 0x32 && D_02036E7C.field_9A == 5)
                     || (D_02036E7C.stage == 0x33 && D_02036E7C.field_9A == 5) || (D_02036E7C.stage == 0x5A && D_02036E7C.field_9A == 6))
                    && D_02036E7C.frame == 2)
                || (((D_02036E7C.stage == 0x30 && D_02036E7C.field_9A == 0xB) || (D_02036E7C.stage == 0x32 && D_02036E7C.field_9A == 0xA)
                        || (D_02036E7C.stage == 0x33 && D_02036E7C.field_9A == 0xA) || (D_02036E7C.stage == 0x5A && D_02036E7C.field_9A == 0xB))
                    && D_02036E7C.frame == 4))
            {
                switch (D_02036E7C.stage)
                {
                case 0x30:
                    center = 0xC0;
                    break;
                case 0x32:
                case 0x33:
                    center = 0xB0;
                    break;
                case 0x5A:
                    center = 0xA8;
                    break;
                }
                for (i = 0; i < 3; i++)
                {
                    if (D_02030B4C[i] == 0)
                        continue;
                    k = i;
                    if (D_02036E7C.field_9A <= 8 && i != 0)
                        k ^= 3;
                    x = D_087AD848[D_02036E7C.stage][k][0] - (k == 2 ? D_087B0FC4[D_02036E7C.pairs[i].id] : 0);
                    if (D_02036E7C.field_9A <= 8)
                    {
                        s16 sx = x;
                        x = sx + (center - sx) * 2;
                    }
                    if (D_02036E7C.mirror == 0)
                        D_02030B4C[i]->x = (s16)x << 8;
                    else
                        D_02030B4C[i]->x = (0x100 - (s16)x) << 8;
                    D_02030B4C[i]->flags = (D_02030B4C[i]->flags ^ 0x8000) & ~0xC0;
                    D_02030B4C[i]->flags |= D_087AEBA8[D_02036E7C.stage][k] << 6;
                }
            }
            if (D_02036E7C.stage == 0x1B && D_02036E7C.field_9A == 6 && D_02036E7C.frame == 1)
            {
                for (i = 0; i < 3; i++)
                    D_02030B4C[i]->y -= 0x300;
            }
        }
        D_02036E7C.timer++;
    }
    else if (D_02036E7C.field_9B == 2)
    {
        if (D_02030B48 == 0 || D_02030B48->field_8C == 0xFF)
        {
            D_02036E7C.field_9B = 0;
            D_02036E7C.field_9C = 1;
        }
    }
}
