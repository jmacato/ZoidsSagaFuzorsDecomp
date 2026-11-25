#include "types.h"

struct Obj
{
    u32 flags;
};

struct Unit
{
    u8 pad_0[7];
    u8 formation;
};

struct Big
{
    u8 pad_0[0x4EA4];
    struct Obj *objs[7];
};

extern struct Big D_02031A0C;
void func_080944D4(u8, s16, s16);

void func_0809459C(u8 side, u8 slot, struct Unit *unit)
{
    u8 i;
    s16 x;
    s16 y;

    for (i = 1; i < 7; i++)
    {
        D_02031A0C.objs[i]->flags &= ~0x1000;
        switch (unit->formation)
        {
        case 0:
            x = (1 - slot / 3) * 32 + 24;
            y = (2 - slot % 3) * 32 + 24;
            break;
        case 3:
            if (i == 1)
            {
                x = (1 - slot / 3) * 32 + 24;
                y = (2 - slot % 3) * 32 + 24;
            }
            else
            {
                x = (1 - (slot + 3) / 3) * 32 + 24;
                y = (2 - (slot + 3) % 3) * 32 + 24;
            }
            break;
        case 1:
            if (i == 1)
            {
                x = (1 - slot / 3) * 32 + 24;
                y = (2 - slot % 3) * 32 + 24;
            }
            else
            {
                x = (1 - (slot + 1) / 3) * 32 + 24;
                y = (2 - (slot + 1) % 3) * 32 + 24;
            }
            break;
        case 2:
            switch (i)
            {
            default:
                x = (1 - (slot + 2) / 3) * 32 + 24;
                y = (2 - (slot + 2) % 3) * 32 + 24;
                break;
            case 1:
                x = (1 - slot / 3) * 32 + 24;
                y = (2 - slot % 3) * 32 + 24;
                break;
            case 2:
                x = (1 - (slot + 1) / 3) * 32 + 24;
                y = (2 - (slot + 1) % 3) * 32 + 24;
                break;
            }
            break;
        case 4:
            switch (i)
            {
            case 1:
                x = (1 - slot / 3) * 32 + 24;
                y = (2 - slot % 3) * 32 + 24;
                break;
            case 2:
                x = (1 - (slot + 1) / 3) * 32 + 24;
                y = (2 - (slot + 1) % 3) * 32 + 24;
                break;
            case 3:
                x = (1 - (slot + 3) / 3) * 32 + 24;
                y = (2 - (slot + 3) % 3) * 32 + 24;
                break;
            default:
                x = (1 - (slot + 4) / 3) * 32 + 24;
                y = (2 - (slot + 4) % 3) * 32 + 24;
                break;
            }
            break;
        case 5:
            switch (i)
            {
            case 1:
                x = (1 - slot / 3) * 32 + 24;
                y = (2 - slot % 3) * 32 + 24;
                break;
            case 2:
                x = (1 - (slot + 1) / 3) * 32 + 24;
                y = (2 - (slot + 1) % 3) * 32 + 24;
                break;
            case 3:
                x = (1 - (slot + 2) / 3) * 32 + 24;
                y = (2 - (slot + 2) % 3) * 32 + 24;
                break;
            case 4:
                x = (1 - (slot + 3) / 3) * 32 + 24;
                y = (2 - (slot + 3) % 3) * 32 + 24;
                break;
            case 5:
                x = (1 - (slot + 4) / 3) * 32 + 24;
                y = (2 - (slot + 4) % 3) * 32 + 24;
                break;
            default:
                x = (1 - (slot + 5) / 3) * 32 + 24;
                y = (2 - (slot + 5) % 3) * 32 + 24;
                break;
            }
            break;
        }
        if (side == 0)
        {
            x = 0x50 - x;
            y = 0x70 - y;
        }
        func_080944D4(i, x, y);
    }
}
