#include "types.h"

struct Unit
{
    u8 zoid;
    u8 pad_1[0x107];
};

struct Move
{
    u16 field_0;
    u16 id;
};

struct Zoid
{
    u8 type;
    u8 pad_1[3];
    u16 flags;
    u8 pad_6[0x6E];
    struct Move moves[4];
    u8 pad_84[0x10];
};

struct Game
{
    u8 pad_0[0x258];
    struct Unit units[2][7];
    struct Zoid zoids[2][11];
    u8 pad_1D80[0x30EF];
    u8 mode;
    u8 pad_4E70[0x100];
    u8 lost[6];
    u8 lostCount;
};

extern struct Game D_02031A0C;
extern u32 (*D_03000010)(void);
extern u8 D_0200C4BC;
extern u8 D_0200C4D4;
extern u16 D_0200C4C8;
extern const u8 D_08005102[];
extern const u8 D_08005176[];
extern const u8 D_0800514C[];
extern const u8 D_080051DE[];
extern const u8 D_0800512C[];
extern const u8 D_080051AE[];
extern const u8 D_08759BF4[][8];

struct Zoid *func_0809A908(u8 side, u8 slot);
void func_08075EE0(u16 se);
void func_0807BD4C(u8 a);
void func_0807C290(const u8 *script);
s32 func_0807F18C(u8 type);
u8 func_080BD3C0(u8 type);
s32 func_0807F1D0(u8 item, u8 n);
s32 func_0807F0C4(u8 move, u8 n);

void func_0809E89C(void)
{
    u8 ids[8];
    u16 list[24];
    u8 n, i, j, cnt, k;
    u16 v;
    const u8 *p;
    struct Zoid *zp;
    n = 0;
    for (k = 0; k < 6; k++)
    {
        if (D_02031A0C.units[1][k].zoid != 0xFF && !(func_0809A908(1, k)->flags & 0x10))
        {
            ids[n] = D_02031A0C.units[1][k].zoid;
            n++;
        }
    }
    if ((u8)(D_02031A0C.mode - 8) <= 1 || (D_03000010() * 10) >> 15 == 0)
    {
        if (D_02031A0C.mode == 9)
        {
            if (D_02031A0C.lostCount == 0)
                goto items;
            v = D_02031A0C.zoids[1][D_02031A0C.lost[(D_03000010() * D_02031A0C.lostCount) >> 15]].type;
        }
        else if (n != 0)
            v = D_02031A0C.zoids[1][ids[(D_03000010() * n) >> 15]].type;
        else
            v = 0;
        if (v != 0)
        {
            func_08075EE0(0x67);
            func_0807BD4C(0);
            D_0200C4BC = v;
            func_0807C290(D_08005102);
            if (!func_0807F18C(v))
            {
                func_0807BD4C(0);
                func_0807C290(D_08005176);
            }
        }
    }
items:
    if ((u8)(D_02031A0C.mode - 0xA) <= 1 || (D_03000010() * 6) >> 15 == 0)
    {
        cnt = 0;
        if (D_02031A0C.mode == 0xB)
        {
            for (i = 0; i < D_02031A0C.lostCount; i++)
            {
                p = D_08759BF4[func_080BD3C0(D_02031A0C.zoids[1][D_02031A0C.lost[i]].type)];
                for (j = 0; j < 2; j++)
                {
                    if (p[j])
                    {
                        list[cnt] = p[j];
                        cnt++;
                    }
                }
            }
        }
        else
        {
            for (i = 0; i < n; i++)
            {
                p = D_08759BF4[func_080BD3C0(D_02031A0C.zoids[1][ids[i]].type)];
                for (j = 0; j < 2; j++)
                {
                    if (p[j])
                    {
                        list[cnt] = p[j];
                        cnt++;
                    }
                }
            }
        }
        if (cnt != 0)
        {
            func_08075EE0(0x67);
            v = list[(D_03000010() * cnt) >> 15];
            func_0807BD4C(0);
            D_0200C4D4 = v;
            func_0807C290(D_0800514C);
            if (!func_0807F1D0(v, 1))
            {
                func_0807BD4C(0);
                func_0807C290(D_080051DE);
            }
        }
    }
    if (D_02031A0C.mode == 0xC || D_02031A0C.mode == 0x2A)
    {
        cnt = 0;
        if (D_02031A0C.mode == 0x2A)
        {
            for (i = 0; i < D_02031A0C.lostCount; i++)
            {
                zp = &D_02031A0C.zoids[1][D_02031A0C.lost[i]];
                for (j = 0; j < 4; j++)
                {
                    if (zp->moves[j].id)
                    {
                        list[cnt] = zp->moves[j].id;
                        cnt++;
                    }
                }
            }
        }
        else
        {
            for (i = 0; i < n; i++)
            {
                zp = &D_02031A0C.zoids[1][ids[i]];
                for (j = 0; j < 4; j++)
                {
                    if (zp->moves[j].id)
                    {
                        list[cnt] = zp->moves[j].id;
                        cnt++;
                    }
                }
            }
        }
        if (cnt != 0)
        {
            func_08075EE0(0x67);
            v = list[(D_03000010() * cnt) >> 15];
            func_0807BD4C(0);
            D_0200C4C8 = v;
            func_0807C290(D_0800512C);
            if (!func_0807F0C4(v, 1))
            {
                func_0807BD4C(0);
                func_0807C290(D_080051AE);
            }
        }
    }
}
