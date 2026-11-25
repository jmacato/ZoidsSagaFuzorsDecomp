#include "types.h"

struct Zoid
{
    u8 species;
    u8 pad_1[3];
    u16 flags;
    u8 pad_6[0x5C];
    s16 stats[7];
    u32 exp;
    u8 pad_74[0x20];
};

struct Save
{
    u8 pad_0[0x3C];
    struct Zoid zoids[186];
    u8 pad_6BC4[0x7A6A - 0x6BC4];
    u8 team[6];
    u8 pad_7A70[0x7B43 - 0x7A70];
    u8 sort_mode;
    u8 sort_order;
};

struct ZoidData
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 pad_3[0x31];
};

extern struct Save D_02020E4C;
extern struct Zoid D_02020E88[];
extern u8 D_02030C25;
extern u8 D_02030B6C[];
extern u8 D_08735100[];
extern struct ZoidData D_0873FCC8[];
s32 func_08089C98(struct Zoid *, u8);

void func_08089CE0(u32 flags, u32 arg)
{
    s16 i;
    s16 j;
    u8 key;
    u8 other;
    u8 a;
    u8 b;
    u8 res;
    struct Zoid *z;

    D_02030C25 = 0;
    for (i = 1; i <= 0xB9; i++)
    {
        z = &D_02020E88[i];
        if (z->species == 0)
            continue;
        if ((flags & 1) && !func_08089C98(z, arg))
            continue;
        if ((flags & 2) && !(z->flags & 2))
            continue;
        D_02030B6C[D_02030C25] = i;
        D_02030C25++;
    }
    for (i = 1; i < D_02030C25; i++)
    {
        key = D_02030B6C[i];
        for (j = i - 1; j >= 0; j--)
        {
            other = D_02030B6C[j];
            if (!(D_02020E4C.zoids[key].flags & 1))
            {
                if (!(D_02020E4C.zoids[other].flags & 1))
                    goto sort;
                break;
            }
            if (D_02020E4C.zoids[other].flags & 1)
            {
                for (a = 0; a < 6; a++)
                    if (D_02020E4C.team[a] == key)
                        break;
                for (b = 0; b < 6; b++)
                    if (D_02020E4C.team[b] == other)
                        break;
                if (a >= b)
                    break;
                D_02030B6C[j + 1] = other;
            }
            else
                D_02030B6C[j + 1] = other;
            continue;
        sort:
            res = 0;
            switch (D_02020E4C.sort_mode)
            {
            case 0:
                if (D_08735100[D_02020E4C.zoids[key].species] < D_08735100[D_02020E4C.zoids[other].species])
                    res = 1;
                break;
            case 1:
                if ((D_0873FCC8[D_02020E4C.zoids[key].species].field_0 & 0x3F) == (D_0873FCC8[D_02020E4C.zoids[other].species].field_0 & 0x3F))
                {
                    if (D_0873FCC8[D_02020E4C.zoids[key].species].field_1 < D_0873FCC8[D_02020E4C.zoids[other].species].field_1)
                        res = 1;
                }
                else if ((D_0873FCC8[D_02020E4C.zoids[key].species].field_0 & 0x3F) < (D_0873FCC8[D_02020E4C.zoids[other].species].field_0 & 0x3F))
                    res = 1;
                break;
            case 2:
                if (D_0873FCC8[D_02020E4C.zoids[key].species].field_2 < D_0873FCC8[D_02020E4C.zoids[other].species].field_2)
                    res = 1;
                break;
            case 3:
                if (D_02020E4C.zoids[key].stats[0] > D_02020E4C.zoids[other].stats[0])
                    res = 1;
                break;
            case 4:
                if (D_02020E4C.zoids[key].stats[1] > D_02020E4C.zoids[other].stats[1])
                    res = 1;
                break;
            case 5:
                if (D_02020E4C.zoids[key].stats[2] > D_02020E4C.zoids[other].stats[2])
                    res = 1;
                break;
            case 6:
                if (D_02020E4C.zoids[key].stats[3] > D_02020E4C.zoids[other].stats[3])
                    res = 1;
                break;
            case 7:
                if (D_02020E4C.zoids[key].stats[4] > D_02020E4C.zoids[other].stats[4])
                    res = 1;
                break;
            case 8:
                if (D_02020E4C.zoids[key].stats[5] > D_02020E4C.zoids[other].stats[5])
                    res = 1;
                break;
            case 9:
                if (D_02020E4C.zoids[key].exp > D_02020E4C.zoids[other].exp)
                    res = 1;
                break;
            case 10:
                if (D_02020E4C.zoids[key].stats[6] > D_02020E4C.zoids[other].stats[6])
                    res = 1;
                break;
            }
            if (D_02020E4C.sort_order == res)
                break;
            D_02030B6C[j + 1] = other;
        }
        D_02030B6C[j + 1] = key;
    }
}
