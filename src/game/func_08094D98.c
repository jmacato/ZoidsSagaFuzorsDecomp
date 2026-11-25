#include "types.h"

struct TacticSet
{
    u8 count;
    u8 pad_1[0x63];
};

struct Pilot
{
    u8 pad_0[0x18];
    struct TacticSet sets[6];
};

struct Game
{
    u8 pad_0[0x222C];
    struct Pilot pilots[8];
};

extern struct Game D_02031A0C;

u8 func_08094D98(u8 mode, u8 cur, s8 dx, s8 dy, u8 side)
{
    s8 i;
    s8 row;

    if (dx == 0 && dy == 0)
    {
        for (i = 0; i <= 5; i++)
        {
            row = i - i % 3 + (2 - i % 3);
            if (D_02031A0C.pilots[side].sets[row].count != 0)
                break;
        }
        if (i <= 5)
            cur = row;
    }
    else if ((mode == 0 && dx == -1) || (mode == 1 && dx == 1))
    {
        if (cur > 2)
        {
            i = cur - 3;
            if (D_02031A0C.pilots[side].sets[i].count == 0)
            {
                if (cur < 5)
                {
                    for (i = 0; i <= 2; i++)
                        if (D_02031A0C.pilots[side].sets[i].count != 0)
                            break;
                    if (i <= 2)
                        cur = i;
                }
                else
                {
                    for (i = 2; i >= 0; i--)
                        if (D_02031A0C.pilots[side].sets[i].count != 0)
                            break;
                    if (i >= 0)
                        cur = i;
                }
            }
            else
            {
                cur = i;
            }
        }
    }
    else if ((mode == 0 && dx == 1) || (mode == 1 && dx == -1))
    {
        if (cur < 3)
        {
            i = cur + 3;
            if (D_02031A0C.pilots[side].sets[i].count == 0)
            {
                if (cur < 2)
                {
                    for (i = 3; i <= 5; i++)
                        if (D_02031A0C.pilots[side].sets[i].count != 0)
                            break;
                    if (i <= 5)
                        cur = i;
                }
                else
                {
                    for (i = 5; i > 2; i--)
                        if (D_02031A0C.pilots[side].sets[i].count != 0)
                            break;
                    if (i > 2)
                        cur = i;
                }
            }
            else
            {
                cur = i;
            }
        }
    }
    else if ((mode == 0 && dy == -1) || (mode == 1 && dy == 1))
    {
        row = cur - cur % 3;
        for (i = cur % 3 - 1; i >= 0; i--)
            if (D_02031A0C.pilots[side].sets[row + i].count != 0)
                break;
        if (i >= 0)
        {
            cur = row + i;
        }
        else
        {
            row = 3 - row;
            for (i = cur % 3 - 1; i >= 0; i--)
                if (D_02031A0C.pilots[side].sets[row + i].count != 0)
                    break;
            if (i >= 0)
                cur = row + i;
        }
    }
    else if ((mode == 0 && dy == 1) || (mode == 1 && dy == -1))
    {
        row = cur - cur % 3;
        for (i = cur % 3 + 1; i <= 2; i++)
            if (D_02031A0C.pilots[side].sets[row + i].count != 0)
                break;
        if (i <= 2)
        {
            cur = row + i;
        }
        else
        {
            row = 3 - row;
            for (i = cur % 3 + 1; i <= 2; i++)
                if (D_02031A0C.pilots[side].sets[row + i].count != 0)
                    break;
            if (i <= 2)
                cur = row + i;
        }
    }
    return cur;
}
