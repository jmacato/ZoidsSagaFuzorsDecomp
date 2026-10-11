#include "types.h"

struct Pilot
{
    u8 id;
    u8 pad_1;
    u8 level;
    u8 pad_3;
    u32 exp;
    u8 pad_8[0x27];
    s8 growthStats[5];
    s16 stats[5];
    u8 pad_3E;
    u8 growth;
};

struct Obj
{
    u32 flags;
    s32 field_4;
    s32 field_8;
};

extern struct Pilot D_02027A10[];
extern const u32 D_08747168[];
extern const u16 D_087472F4[][5];
extern const u8 D_08747388[][56][10];
extern const u8 *const D_087A5AE4[];
extern u32 (*D_03000010)(void);
extern u16 D_030057EC;
extern u16 D_0300000E;
extern u8 D_02001480[];
extern u8 D_0200C4C0;
extern u32 D_0200C4AC;
extern const u8 D_0800525F[];
extern const u8 D_08005218[];
extern const u8 D_080052C7[];
extern const u8 D_080052FD[];
extern const u8 D_08005340[];
extern const u8 D_08005343[];
extern const u8 D_080C9680[];
extern const u8 D_080C96B4[];

void func_08075EE0(u16 se);
void func_08075F20(u32 se);
void func_0807C290(const u8 *);
void func_0809E1B4(struct Pilot *p, s16 *bonus);
void func_0807FF2C(u8, u8, u16, u8, u8 *);
struct Obj *func_080771BC(const u8 *, const u8 *, u32, u32, u32, u32, u32, u32, u32);
void func_080771F4(struct Obj *);
void func_0807BA24(s16 value, u8 digits, u8 a, u8 b, u8 c, u16 x, u16 y);
void func_0807A1A4(void);
void func_080C8FCC(u32);
void func_0807B748(const u8 *, u32, u32, u32, u32);
void func_080BF93C(struct Pilot *, u8, u8);
void func_0807BD4C(u8);

void func_0809E34C(u8 id)
{
    struct Pilot *p;
    s16 bonus[5];
    struct Obj *obj;
    u8 i, sel, points, done, n, cnt, j, k;

    p = &D_02027A10[id];
    while (p->exp >= D_08747168[p->level] && p->level <= 0x62)
    {
        func_08075EE0(0x6B);
        p->level++;
        func_0807C290(D_0800525F);
        if (p->growth <= 3)
        {
            bonus[0] = D_087472F4[p->growth][0];
            bonus[1] = D_087472F4[p->growth][1];
            bonus[2] = D_087472F4[p->growth][2];
            bonus[3] = D_087472F4[p->growth][3];
            bonus[4] = D_087472F4[p->growth][4];
        }
        else if (p->growth == 4)
        {
            bonus[0] = p->growthStats[0];
            bonus[1] = p->growthStats[1];
            bonus[2] = p->growthStats[2];
            bonus[3] = p->growthStats[3];
            bonus[4] = p->growthStats[4];
        }
        else if (p->growth == 5)
        {
            for (i = 0; i < 5; i++)
                bonus[i] = 0;
            for (i = 0; i < 10; i++)
                bonus[(D_03000010() * 5) >> 15]++;
        }
        else if (p->growth == 6)
        {
            for (i = 0; i < 5; i++)
                bonus[i] = 0;
        }
        func_0809E1B4(p, bonus);
        if (p->id == 1 || p->id == 0x12 || p->id == 0x31 || p->id == 0x32 || p->id == 0x33 || p->id == 0x34 || p->id == 0x35 || p->id == 0x36)
            n = 5;
        else
            n = 2;
        func_0807FF2C(p->id, n, 0x300, 0xC, D_02001480);
        {
            u8 *dst = &D_0200C4C0;
            u8 id = p->id;
            i = 0;
            *dst = id;
        }
        D_0200C4AC = p->level;
        func_0807C290(D_08005218);
        if (p->growth == 6)
        {
            func_0807C290(D_080052C7);
            obj = func_080771BC(D_080C9680, D_080C96B4, 0, 0x98, 0, 0x3EE, 0xF, 0x20, 0);
            sel = 0;
            points = 10;
            done = 0;
            while (!done)
            {
                obj->field_8 = (sel + 5) << 11;
                func_0809E1B4(p, bonus);
                func_0807BA24(points, 2, 0, 0x12, 4, 9, 0);
                func_0807A1A4();
                for (;;)
                {
                    func_080C8FCC(1);
                    if (D_030057EC & 0x40)
                    {
                        func_08075F20(0xCC);
                        if (sel != 0)
                            sel--;
                        else
                            sel = 4;
                        break;
                    }
                    if (D_030057EC & 0x80)
                    {
                        func_08075F20(0xCC);
                        if (sel <= 3)
                            sel++;
                        else
                            sel = 0;
                        break;
                    }
                    if (D_030057EC & 0x20)
                    {
                        if (bonus[sel] != 0)
                        {
                            func_08075F20(0xCC);
                            bonus[sel]--;
                            points++;
                            break;
                        }
                        func_08075F20(0x114);
                    }
                    else if (D_030057EC & 0x10)
                    {
                        if (points != 0)
                        {
                            func_08075F20(0xCC);
                            bonus[sel]++;
                            points--;
                            break;
                        }
                        func_08075F20(0x114);
                    }
                    else if (D_0300000E & 1)
                    {
                        if (points == 0)
                        {
                            func_08075F20(0xCA);
                            done = 1;
                            break;
                        }
                        func_08075F20(0x114);
                        obj->flags |= 0x20000;
                        func_0807C290(D_080052FD);
                        obj->flags &= ~0x20000;
                    }
                }
            }
            func_0807C290(D_08005340);
            func_080771F4(obj);
        }
        if (p->stats[0] + bonus[0] < 999)
            p->stats[0] += bonus[0];
        else
            p->stats[0] = 999;
        if (p->stats[1] + bonus[1] < 999)
            p->stats[1] += bonus[1];
        else
            p->stats[1] = 999;
        if (p->stats[2] + bonus[2] < 999)
            p->stats[2] += bonus[2];
        else
            p->stats[2] = 999;
        if (p->stats[3] + bonus[3] < 999)
            p->stats[3] += bonus[3];
        else
            p->stats[3] = 999;
        if (p->stats[4] + bonus[4] < 999)
            p->stats[4] += bonus[4];
        else
            p->stats[4] = 999;
        cnt = 0;
        for (j = 0; j < 56; j++)
        {
            for (k = 0; k < 10; k++)
            {
                if (D_08747388[p->id][j][k] == p->level)
                {
                    if (cnt % 3 == 0)
                    {
                        if (cnt == 0)
                        {
                            func_08075EE0(0x66);
                            func_0807C290(D_08005343);
                        }
                        else
                            func_0807BD4C(3);
                    }
                    func_0807B748(D_087A5AE4[j], 0, 3, 0, (u8)(cnt % 3) * 2);
                    func_080BF93C(p, j, 1);
                    cnt++;
                    if (cnt % 3 == 0)
                    {
                        func_0807A1A4();
                        do
                            func_080C8FCC(1);
                        while (!(D_0300000E & 3));
                        func_08075F20(0xCD);
                    }
                }
            }
        }
        if (cnt % 3 != 0)
        {
            func_0807A1A4();
            do
                func_080C8FCC(1);
            while (!(D_0300000E & 3));
            func_08075F20(0xCD);
        }
    }
}
