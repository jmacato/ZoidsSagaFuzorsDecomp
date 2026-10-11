#include "types.h"

struct Tactic
{
    u8 used;
    u8 pad_1;
    s16 attack;
    s16 special;
    u8 pad_6[2];
};

struct TacticSet
{
    u8 count;
    u8 pad_1[3];
    struct Tactic t[2][6];
};

struct Pilot
{
    u8 flags;
    u8 pad_1[5];
    u8 range;
    u8 shape;
    u8 pad_8[0x10];
    struct TacticSet sets[6];
};

struct Move
{
    u16 field_0;
    u16 id;
};

struct Zoid
{
    u8 pad_0[0x74];
    struct Move moves[8];
};

struct Game
{
    u8 pad_0[0x244];
    u8 side;
    u8 slot;
    u8 field_246;
    u8 pad_247[5];
    struct Zoid *zoid;
    u8 pad_250[0x222C - 0x250];
    struct Pilot pilots[8];
};

extern struct Game D_02031A0C;

void func_080C8B7C(const void *, void *, u32);
void func_080C05A4(u8, u8, u8, u8, struct Pilot *);
u8 func_080C005C(u8 a, u8 b, u8 c, u8 d);
s32 func_0809A99C(u8 side, u8 slot);
void func_080C0A38(u8 ag, u8 au, u8 dg, u8 du, struct Pilot *s, s16 *out);

void func_0809C650(void)
{
    u32 zero;
    struct Pilot *pilot;
    u8 lo, hi;
    u8 i, s, x, w, h, k, y, u, r;

    zero = 0;
    func_080C8B7C(&zero, D_02031A0C.pilots, 0x050004E0);
    for (i = 0; i < 8; i++)
    {
        pilot = &D_02031A0C.pilots[i];
        if (D_02031A0C.zoid->moves[i].id != 0)
        {
            func_080C05A4(D_02031A0C.side, D_02031A0C.slot, D_02031A0C.field_246, i, pilot);
            if (!(pilot->flags & 1))
            {
                if (pilot->shape != 6)
                    lo = hi = D_02031A0C.side ^ 1;
                else
                {
                    lo = 0;
                    hi = 2;
                }
        }
        else
            lo = hi = D_02031A0C.side;
        switch (pilot->shape)
        {
        case 0:
            h = 1;
            w = 1;
            break;
        case 1:
            w = 2;
            h = 1;
            break;
        case 2:
            w = 3;
            h = 1;
            break;
        case 3:
            w = 1;
            h = 2;
            break;
        case 4:
            w = 2;
            h = 2;
            break;
        case 5:
            w = 3;
            h = 2;
            break;
        case 6:
            w = 3;
            h = 2;
            break;
        case 7:
            h = 1;
            w = 1;
            break;
        }
        for (k = 0; k < 6; k++)
        {
            pilot->sets[k].count = 0;
            if (k % 3 + w > 3)
                continue;
            if (k / 3 + h > 2)
                continue;
            if (!(pilot->flags & 1))
            {
                r = func_080C005C(D_02031A0C.side, D_02031A0C.slot, D_02031A0C.side ^ 1, k);
                switch (pilot->range)
                {
                case 0:
                    if (r != 1)
                        continue;
                    break;
                case 1:
                    if (r < 1 || r > 2)
                        continue;
                    break;
                case 2:
                    if (r < 1 || r > 3)
                        continue;
                    break;
                case 3:
                    if (r != 2)
                        continue;
                    break;
                case 4:
                    if (r < 2 || r > 3)
                        continue;
                    break;
                case 5:
                    if (r != 3)
                        continue;
                    break;
                }
            }
            else if (pilot->shape == 7 && k != D_02031A0C.slot)
                continue;
            for (s = lo; s <= hi; s++)
            {
                for (x = 0; x < w; x++)
                {
                    for (y = 0; y < h; y++)
                    {
                        u = k + x + y * 3;
                        if (func_0809A99C(s, u))
                        {
                            pilot->sets[k].t[s][u].used = 1;
                            func_080C0A38(D_02031A0C.side, D_02031A0C.slot, s, u, pilot, &pilot->sets[k].t[s][u].attack);
                            pilot->sets[k].count++;
                        }
                        else
                            pilot->sets[k].t[s][u].used = 0;
                    }
                }
            }
        }
        }
        else
        {
            for (k = 0; k < 6; k++)
                pilot->sets[k].count = 0;
        }
    }
}
