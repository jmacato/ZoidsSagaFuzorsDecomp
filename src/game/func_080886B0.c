#include "types.h"

struct Actor
{
    u8 field_0;
    u8 kind;
    u8 pad_2[2];
    s32 x;
    s32 y;
    s32 vx;
    s32 vy;
    u8 pad_14[6];
    u8 flags;
    u8 pad_1B[0x29];
};

struct Map
{
    u16 id;
    u8 pad_2[0x12];
    u16 width;
    u16 height;
    u8 mode;
    u8 pad_19[3];
    u8 entry;
    u8 pad_1D[3];
    s32 field_20;
    s32 field_24;
    s32 field_28;
    s32 field_2C;
    u8 pad_30[0x3F4];
    struct Actor *current;
};

struct EncSlot
{
    u8 field_0;
    u8 pad_1[0x2F];
};

struct Enc
{
    u8 field_0;
    u8 weight;
    u8 pad_2[2];
    struct EncSlot slots[6];
};

struct Battle
{
    u8 pad_0[2];
    u8 group;
    u8 index;
};

extern struct Map D_020209D8;
extern struct Battle D_02020E3C;
extern u16 *D_0877C444[];
extern u16 D_0877C454[];
extern u16 D_0877C4E6[][3];
extern struct Enc D_0875A0C4[][15];
extern u32 (*D_03000010)(void);
u16 func_080C8B8C(s32);
u8 func_08082F4C(u8);

s32 func_080886B0(void)
{
    struct Actor *a;
    u16 rate;
    u16 kind;
    u16 cell;
    s32 hw;
    s32 tx;
    s32 ty;
    u16 r;
    u16 sum;
    u8 found;
    u8 i;
    u8 k;

    if ((u8)(D_020209D8.current->kind + 0x78) > 1)
        return 0;
    a = D_020209D8.current;
    D_020209D8.field_20 += func_080C8B8C(a->vx * a->vx + a->vy * a->vy);
    if ((D_020209D8.field_20 & 0xFFFFF000) != (D_020209D8.field_24 & 0xFFFFF000) && !(D_020209D8.current->flags & 0x40))
    {
        a = D_020209D8.current;
        if (D_020209D8.mode != 0)
        {
            tx = (a->x / 0x1000) % (hw = D_020209D8.width >> 1);
            ty = (a->y / 0x1000) % (D_020209D8.height >> 1);
            cell = *(D_0877C444[D_020209D8.id] + tx + ty * hw);
            rate = D_0877C454[cell >> 8];
            kind = cell & 0xFF;
            if (kind == 0)
                return 0;
            kind--;
            if (func_08082F4C(0x5E))
            {
                if (kind == 3)
                    kind = 6;
                else if (kind == 0x17)
                    kind = 0x1A;
            }
        }
        else
        {
            rate = D_0877C4E6[D_020209D8.entry][1] * 8 / 10;
            kind = D_0877C4E6[D_020209D8.entry][2];
        }
        D_020209D8.field_2C -= rate;
        if (D_020209D8.field_28 > D_020209D8.field_2C)
        {
            D_02020E3C.group = kind;
            r = D_03000010() * 100 >> 15;
            sum = 0;
            found = 0;
            for (i = 0; i < 15 && !found; i++)
            {
                for (k = 0; k < 6; k++)
                {
                    if (D_0875A0C4[kind][i].slots[k].field_0 != 0)
                    {
                        sum += D_0875A0C4[kind][i].weight;
                        if (r < sum)
                        {
                            D_02020E3C.index = i;
                            found = 1;
                        }
                        break;
                    }
                }
            }
            if (found)
                return 1;
        }
    }
    D_020209D8.field_24 = D_020209D8.field_20;
    return 0;
}
