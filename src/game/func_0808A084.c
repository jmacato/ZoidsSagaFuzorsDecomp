#include "types.h"

struct Pilot
{
    u8 id;
    u8 pad_1;
    u8 level;
    u8 flags;
    u8 pad_4[0x2A];
    u8 zoid;
    u8 pad_2F[5];
    s16 stats[5];
    u8 pad_3E[2];
};

struct Save
{
    u8 pad_0[0x6BC4];
    struct Pilot pilots[58];
    u8 pad_7A44[0x7A6A - 0x7A44];
    u8 team[6];
    u8 pad_7A70[0x7B45 - 0x7A70];
    u8 sort_mode;
    u8 sort_order;
};

extern struct Save D_02020E4C;
extern u8 D_02030C5A;
extern u8 D_02030C26[];
extern u8 D_087351A4[];
extern u8 D_0873522B[];

void func_0808A084(void)
{
    s16 i;
    s16 j;
    u8 key;
    u8 other;
    u8 a;
    u8 b;
    u8 res;

    D_02030C5A = 0;
    for (i = 1; i <= 0x34; i++)
    {
        if (D_02020E4C.pilots[i].id != 0)
        {
            D_02030C26[D_02030C5A] = i;
            D_02030C5A++;
        }
    }
    for (i = 1; i < D_02030C5A; i++)
    {
        key = D_02030C26[i];
        for (j = i - 1; j >= 0; j--)
        {
            other = D_02030C26[j];
            if (!(D_02020E4C.pilots[key].flags & 1))
            {
                if (!(D_02020E4C.pilots[other].flags & 1))
                    goto sort;
                break;
            }
            if (D_02020E4C.pilots[other].flags & 1)
            {
                for (a = 0; a < 6; a++)
                    if (D_02020E4C.team[a] == D_02020E4C.pilots[key].zoid)
                        break;
                for (b = 0; b < 6; b++)
                    if (D_02020E4C.team[b] == D_02020E4C.pilots[other].zoid)
                        break;
                if (a >= b)
                    break;
                D_02030C26[j + 1] = other;
            }
            else
                D_02030C26[j + 1] = other;
            continue;
        sort:
            res = 0;
            switch (D_02020E4C.sort_mode)
            {
            case 0:
                if (D_087351A4[D_02020E4C.pilots[key].id] < D_087351A4[D_02020E4C.pilots[other].id])
                    res = 1;
                break;
            case 1:
                if (D_0873522B[D_02020E4C.pilots[key].id] < D_0873522B[D_02020E4C.pilots[other].id])
                    res = 1;
                break;
            case 3:
                if (D_02020E4C.pilots[key].stats[0] > D_02020E4C.pilots[other].stats[0])
                    res = 1;
                break;
            case 2:
                if (D_02020E4C.pilots[key].level > D_02020E4C.pilots[other].level)
                    res = 1;
                break;
            case 4:
                if (D_02020E4C.pilots[key].stats[1] > D_02020E4C.pilots[other].stats[1])
                    res = 1;
                break;
            case 5:
                if (D_02020E4C.pilots[key].stats[2] > D_02020E4C.pilots[other].stats[2])
                    res = 1;
                break;
            case 6:
                if (D_02020E4C.pilots[key].stats[3] > D_02020E4C.pilots[other].stats[3])
                    res = 1;
                break;
            case 7:
                if (D_02020E4C.pilots[key].stats[4] > D_02020E4C.pilots[other].stats[4])
                    res = 1;
                break;
            }
            if (D_02020E4C.sort_order == res)
                break;
            D_02030C26[j + 1] = other;
        }
        D_02030C26[j + 1] = key;
    }
}
