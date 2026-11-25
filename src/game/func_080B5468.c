#include "types.h"

struct Win
{
    u8 pad_0[0x14];
    u8 field_14;
    u8 field_15;
    u8 field_16;
    u8 pad_17[0x4B9];
};

struct Zoid
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u16 field_4;
    u16 field_6;
    u8 pad_8[0xA];
    u16 field_12[5][4];
    u16 field_3A[5][4];
    u16 field_62;
    u8 pad_64[0x30];
};

struct Pilot
{
    u8 pad_0[0x40];
};

struct Save
{
    u8 pad_0[0x3C];
    struct Zoid zoids[186];
    u8 pad_6BC4[0x79D6 - 0x3C - 186 * 0x94];
    u8 counts[0x86];
    u32 money;
};

struct Item
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 pad_3;
    u32 field_4;
};

struct Obj
{
    u32 flags;
};

struct Ctx
{
    u8 pad_0[0x10];
    struct Zoid *field_10;
};

void func_0807C290(const void *);
void func_080B4D10(u8);
void func_0808B098(u8);
void func_0808A7F8(u8, u8, u8, u8);
void func_080B4D70(void);
void func_0808FC78(u8, u32);
void func_080B4D54(void);
void func_080BD488(u8, u8, struct Zoid *);
void func_0808D7C0(u8);
s32 func_080B4DFC(u8, u8);
s32 func_080B4EB0(u8);
u32 func_080BE144(void);
void func_0808A890(u32);
void func_0808A8B4(u32);
void func_0808A86C(u8);
u8 func_080B512C(struct Zoid *);
void func_0808AC1C(u8, u32);
struct Obj *func_080771BC(const void *, const void *, u16, s16, s16, u16, u16, u32, u32);
s32 func_0808B590(struct Zoid *, u8, struct Obj *, struct Obj *, u8);
void func_08075F20(u16);
void func_080771F4(struct Obj *);
s32 func_080B5028(struct Zoid *);
u8 func_080BD304(u8);
void func_080BE0D4(struct Zoid *, u8, u8);
void func_080BDDE4(struct Zoid *, struct Pilot *, u8);
void func_080BDF14(struct Zoid *, u8);
u32 func_0807EC90(u8, u8);

extern struct Win D_02009480[];
extern u16 D_02030F92[];
extern struct Zoid D_02031254;
extern struct Ctx D_0201F5F8;
extern u8 D_0200C4A0;
extern u8 D_0200C4A1;
extern u8 D_0200C4A2;
extern u16 D_0200C4A4;
extern u32 D_0200C4AC;
extern u8 D_0200C4BC;
extern u8 D_02030B6C[];
extern struct Save D_02020E4C;
extern struct Pilot D_02027A10[];
extern const struct Item D_08759BF4[];
extern const u8 D_08006423[];
extern const u8 D_080067D0[];
extern const u8 D_0800689E[];
extern const u8 D_0800647B[];
extern const u8 D_08006477[];
extern const u8 D_0800652F[];
extern const u8 D_08006662[];
extern const u8 D_08424594[];
extern const u8 D_084245A0[];
extern const u8 D_080F2354[];
extern const u8 D_080F2390[];
extern const u8 D_080067F8[];
extern const u8 D_08006686[];
extern const u8 D_0800668F[];
extern const u8 D_0800668A[];
extern const u8 D_080065FF[];
extern const u8 D_08006772[];
extern const u8 D_0800679C[];
extern const u8 D_08006846[];

void func_080B5468(u8 mode)
{
    struct Obj *a;
    struct Obj *b;
    u8 cur1;
    u8 sel1;
    u8 cur2;
    u8 sel2;
    u8 ret;
    u8 done;
    s32 state;
    struct Zoid *z;
    const struct Item *e;
    u16 *p;
    u8 i;
    u8 j;

    cur1 = 0;
    sel1 = 0;
    state = 0;
    done = 0;
    while (!done)
    {
        switch (state)
        {
        case 0:
            func_0807C290(D_08006423);
            D_02009480[6].field_14 = D_02009480[6].field_15 = cur1;
            D_02009480[6].field_16 = sel1;
            func_080B4D10(4);
            func_0808B098(6);
            state = 0x10;
            break;
        case 0x10:
            func_0808A7F8(0, 1, 0xD8, 0x98);
            func_0808A7F8(1, 0x10, 0xA0, 0x98);
            func_0808A7F8(2, 0xF, 0x60, 0x98);
            func_080B4D70();
            if (mode == 0)
                func_0807C290(D_080067D0);
            else
                func_0807C290(D_0800689E);
            state = 0x20;
            break;
        case 0x20:
            while (1)
            {
                func_0808FC78(D_02030F92[sel1], 1);
                func_0807C290(D_08006477);
                cur1 = D_0200C4A1;
                sel1 = D_0200C4A0;
                if (D_0200C4A2 == 1)
                {
                    state = 0x1000;
                    break;
                }
                if (D_0200C4A2 == 2)
                {
                    done = 1;
                    break;
                }
                if (D_0200C4A4 & 8)
                {
                    if (func_080B4DFC(6, mode))
                        sel1 = 0;
                }
                else if (D_0200C4A4 & 4)
                {
                    func_0807C290(D_0800647B);
                    func_080B4D54();
                    func_080BD488(D_02030F92[sel1], 0, &D_02031254);
                    D_0201F5F8.field_10 = &D_02031254;
                    func_0808D7C0(1);
                    state = 0;
                    break;
                }
            }
            break;
        case 0x1000:
            p = &D_02030F92[sel1];
            if (func_080B4EB0(*p) == 0)
                state = 0x20;
            else if (D_08759BF4[*p].field_2 == 0)
                state = 0x1100;
            else
            {
                sel2 = 0;
                cur2 = 0;
                state = 0x1200;
            }
            break;
        case 0x1100:
            if (func_080BE144() > 0x95)
            {
                func_0808A890(0);
                func_0808A890(1);
                func_0808A890(2);
                D_0200C4AC = 0x96;
                func_0807C290(D_0800652F);
                func_0808A8B4(0);
                func_0808A8B4(1);
                func_0808A8B4(2);
                state = 0x20;
                break;
            }
            func_080B4D54();
            func_0808A86C(0);
            func_0808A86C(1);
            func_0808A86C(2);
            func_080BD488(D_02030F92[sel1], 0, &D_02031254);
            ret = func_080B512C(&D_02031254);
            if (ret == 0xFF)
                state = 0x10;
            else
                state = 0x2000;
            break;
        case 0x1200:
            func_0807C290(D_08006662);
            D_02009480[8].field_14 = D_02009480[8].field_15 = cur2;
            D_02009480[8].field_16 = sel2;
            func_0808AC1C(8, 0x18);
            a = func_080771BC(D_08424594, D_084245A0, 0, 0xC8, 0x68, 0, 0, 8, 0);
            b = func_080771BC(D_080F2354, D_080F2390, 0, 0x88, 0x50, 0x30D, 0xF, 8, 0);
            state = 0x1210;
            break;
        case 0x1210:
            func_0807C290(D_080067F8);
            func_0808A7F8(0, 3, 0xC8, 0x98);
            func_0808A86C(1);
            func_0808A86C(2);
            while (1)
            {
                func_0808B590(&D_02020E4C.zoids[D_02030B6C[sel2]], 9, a, b, 0);
                func_0807C290(D_08006686);
                cur2 = D_0200C4A1;
                sel2 = D_0200C4A0;
                if (D_0200C4A2 == 1)
                {
                    if (D_02020E4C.zoids[D_02030B6C[sel2]].field_4 & 0xC)
                    {
                        func_08075F20(0x114);
                        func_0807C290(D_0800668F);
                        continue;
                    }
                    state = mode == 0 ? 0x1220 : 0x1230;
                    break;
                }
                if (D_0200C4A2 == 2)
                {
                    func_0807C290(D_0800668A);
                    func_080771F4(a);
                    func_080771F4(b);
                    state = 0x10;
                    break;
                }
            }
            break;
        case 0x1220:
            func_0808A86C(0);
            func_0808A86C(1);
            func_0808A86C(2);
            if (func_080B5028(&D_02020E4C.zoids[D_02030B6C[sel2]]) == 0)
            {
                state = 0x1210;
                break;
            }
            a->flags |= 0x20000;
            b->flags |= 0x20000;
            func_080B4D54();
            func_080BD488(D_02030F92[sel1], 0, &D_02031254);
            ret = func_080B512C(&D_02031254);
            a->flags &= ~0x20000;
            b->flags &= ~0x20000;
            if (ret == 0xFF)
            {
                func_080B4D70();
                state = 0x1210;
                break;
            }
            state = 0x1240;
            break;
        case 0x1230:
            if ((D_02020E4C.zoids[D_02030B6C[sel2]].field_3 >> func_080BD304(D_02030F92[sel1])) & 1)
            {
                func_0808A86C(0);
                func_0808A86C(1);
                func_0808A86C(2);
                func_0807C290(D_080065FF);
                state = 0x1210;
                break;
            }
            state = 0x1240;
            break;
        case 0x1240:
            func_0807C290(D_0800668A);
            func_080771F4(a);
            func_080771F4(b);
            func_0808A86C(0);
            func_0808A86C(1);
            func_0808A86C(2);
            state = 0x2000;
            break;
        case 0x2000:
            func_080B4D70();
            D_0200C4BC = D_02030F92[sel1];
            if (mode == 0)
                func_0807C290(D_08006772);
            else
                func_0807C290(D_0800679C);
            if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
            {
                func_0807C290(D_08006846);
                if (D_08759BF4[D_02030F92[sel1]].field_2 != 0)
                {
                    z = &D_02020E4C.zoids[D_02030B6C[sel2]];
                    if (mode == 0)
                    {
                        for (i = 0; i < 4; i++)
                            func_080BE0D4(z, i, 0);
                        z->field_0 = D_02030F92[sel1];
                        z->field_1 = ret;
                        for (i = 0; i < 5; i++)
                        {
                            for (j = 0; j < 4; j++)
                                z->field_12[i][j] = z->field_3A[i][j] = 0;
                        }
                        if (z->field_2 != 0xFF)
                            func_080BDDE4(z, &D_02027A10[z->field_2], 0);
                        else
                            func_080BDDE4(z, 0, 0);
                        z->field_4 &= ~2;
                        z->field_6 = z->field_62;
                    }
                    else
                    {
                        func_080BDF14(z, D_02030F92[sel1]);
                    }
                }
                else
                {
                    func_0807EC90(D_02030F92[sel1], ret);
                }
                e = &D_08759BF4[D_02030F92[sel1]];
                if (e->field_0 != 0)
                    D_02020E4C.counts[e->field_0]--;
                if (e->field_1 != 0)
                    D_02020E4C.counts[e->field_1]--;
                D_02020E4C.money -= e->field_4;
                func_080B4D10(4);
            }
            func_080B4D54();
            state = 0x10;
            break;
        }
    }
    func_0807C290(D_0800647B);
    func_0808A86C(0);
    func_0808A86C(1);
    func_0808A86C(2);
}
