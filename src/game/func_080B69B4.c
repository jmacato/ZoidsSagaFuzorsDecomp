#include "types.h"

struct Zoid
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 pad_3[7];
    s16 field_A;
    s16 field_C;
    s16 field_E;
    s16 field_10;
    u8 pad_12[0x56];
    s16 field_68;
    s16 field_6A;
    s16 field_6C;
    s16 field_6E;
    u8 pad_70[0x24];
};

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
};

struct Delta
{
    s16 a;
    s16 b;
    s16 c;
    s16 d;
};

struct Pilot
{
    u8 pad_0[0x40];
};

struct Scroll
{
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
};

void func_080C8B7C(const void *, void *, u32);
void *memcpy(void *, const void *, u32);
void func_080BD57C(struct Zoid *);
void func_080BDCD8(struct Zoid *);
void func_0807C290(const void *);
void func_080B4D70(void);
void func_080B4D54(void);
void func_080B4D10(u8);
void func_0808A7F8(u8, u8, u8, u8);
void func_0808A86C(u8);
void func_08075F20(u16);
void func_0807BA24(s32, u8, u8, u8, u8, u8, u8);
struct Obj *func_080771BC(const void *, const void *, u16, s16, s16, u16, u16, u32, u32);
void func_080771F4(struct Obj *);
void func_0807A1A4(void);
void func_080C8FCC(u32);
void func_080BDDE4(struct Zoid *, struct Pilot *, u8);

extern u16 D_0300004C;
extern u16 D_03000050;
extern s16 D_03000052;
extern u16 D_0300000E;
extern u16 D_030057EC;
extern u32 D_0201F5C4;
extern struct Scroll D_03000060;
extern struct Zoid D_02031254;
extern u32 D_020288A8;
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern struct Pilot D_02027A10[];
extern const u8 *const D_08736624[];
extern const struct Delta D_08741ECC[];
extern const u8 D_08006CF0[];
extern const u8 D_080C9680[];
extern const u8 D_080C96B4[];
extern const u8 D_08006D66[];
extern const u8 D_08006DC4[];
extern const u8 D_08006E7E[];
extern const u8 D_08006F58[];

void func_080B69B4(struct Zoid *z)
{
    u16 vals[4];
    vu16 fill;
    struct Obj *obj;
    s16 d0;
    s16 d1;
    s16 d2;
    s16 d3;
    u8 row;
    u32 cost;
    s32 state;
    u8 done;
    u16 *v;
    const struct Delta *p;
    struct Zoid *w;
    u32 *money;

    D_0300004C |= 0x200;
    D_03000050 = 0x108;
    D_03000052 = (D_03000052 & 0x3FFC) | 0x4001;
    fill = D_0201F5C4;
    func_080C8B7C(&fill, (void *)0x06000800, 0x01000400);
    D_03000060.x1 = D_03000060.y1 = 0;
    d0 = d1 = d2 = d3 = 0;
    vals[0] = vals[1] = vals[2] = vals[3] = d3;
    row = 0;
    w = &D_02031254;
    money = &D_020288A8;
    memcpy(w, z, 0x94);
    func_080BD57C(w);
    func_080BDCD8(w);
    state = 0;
    done = 0;
    while (!done)
    {
        switch (state)
        {
        case 0:
            func_080B4D54();
            func_0807C290(D_08006CF0);
            func_0808A7F8(0, 3, 0xB0, 0x68);
            func_0807BA24(w->field_68, 4, 0, 0x12, 9, 4, 2);
            func_0807BA24(w->field_6A, 4, 0, 0x12, 9, 4, 4);
            func_0807BA24(w->field_6C, 4, 0, 0x12, 9, 4, 6);
            func_0807BA24(w->field_6E, 4, 0, 0x12, 9, 4, 8);
            obj = func_080771BC(D_080C9680, D_080C96B4, 0, 0x18, 0, 0x3EE, 0xF, 0x5020, 0);
            func_0807BA24(*money, 9, 0, 0x12, 9, 0xC, 0xB);
            state = 0x10;
            break;
        case 0x10:
            func_0807C290(D_08736624[row]);
            state = 0x20;
            break;
        case 0x20:
            obj->y = (row << 12) + 0x1800;
            func_0807BA24(d0, 4, d0 != 0 ? (d0 > 0 ? 2 : 1) : 0, 0x16, 9, 0x11, 2);
            func_0807BA24(d1, 4, d1 != 0 ? (d1 > 0 ? 2 : 1) : 0, 0x16, 9, 0x11, 4);
            func_0807BA24(d2, 4, d2 != 0 ? (d2 > 0 ? 2 : 1) : 0, 0x16, 9, 0x11, 6);
            func_0807BA24(d3, 4, d3 != 0 ? (d3 > 0 ? 2 : 1) : 0, 0x16, 9, 0x11, 8);
            p = &D_08741ECC[row];
            func_0807BA24(p->a, 2, p->a != 0 ? (p->a > 0 ? 2 : 1) : 0, 0x16, 9, 9, 2);
            func_0807BA24(p->b, 2, p->b != 0 ? (p->b > 0 ? 2 : 1) : 0, 0x16, 9, 9, 4);
            func_0807BA24(p->c, 2, p->c != 0 ? (p->c > 0 ? 2 : 1) : 0, 0x16, 9, 9, 6);
            func_0807BA24(p->d, 2, p->d != 0 ? (p->d > 0 ? 2 : 1) : 0, 0x16, 9, 9, 8);
            func_0807BA24(vals[0], 4, 0, 0x12, 9, 0xD, 2);
            func_0807BA24(vals[1], 4, 0, 0x12, 9, 0xD, 4);
            func_0807BA24(vals[2], 4, 0, 0x12, 9, 0xD, 6);
            func_0807BA24(vals[3], 4, 0, 0x12, 9, 0xD, 8);
            cost = (vals[0] + vals[1] + vals[2] + vals[3]) * 1000;
            func_0807BA24(cost, 9, 0, 0x12, 9, 0xC, 0xA);
            func_0807A1A4();
            state = 0x30;
            break;
        case 0x30:
            for (;;)
            {
                func_080C8FCC(1);
                if (D_030057EC & 0x40)
                {
                    func_08075F20(0xCC);
                    if (row != 0)
                        row--;
                    else
                        row = 3;
                    state = 0x10;
                    break;
                }
                if (D_030057EC & 0x80)
                {
                    func_08075F20(0xCC);
                    if (row < 3)
                        row++;
                    else
                        row = 0;
                    state = 0x10;
                    break;
                }
                if (D_030057EC & 0x20)
                {
                    v = &vals[row];
                    if (*v != 0
                        && (u32)(w->field_68 + d0 - p->a - 1) < 9999
                        && (u32)(w->field_6A + d1 - p->b - 1) < 9999
                        && (u32)(w->field_6C + d2 - p->c - 1) < 9999
                        && (u32)(w->field_6E + d3 - p->d - 1) < 9999)
                    {
                        func_08075F20(0xCC);
                        d0 -= p->a;
                        d1 -= p->b;
                        d2 -= p->c;
                        d3 -= p->d;
                        (*v)--;
                        state = 0x20;
                        break;
                    }
                    func_08075F20(0x114);
                }
                else if (D_030057EC & 0x10)
                {
                    v = &vals[row];
                    if (*v < 9999 && cost + 1000 <= *money
                        && (u32)(w->field_68 + d0 + p->a - 1) < 9999
                        && (u32)(w->field_6A + d1 + p->b - 1) < 9999
                        && (u32)(w->field_6C + d2 + p->c - 1) < 9999
                        && (u32)(w->field_6E + d3 + p->d - 1) < 9999)
                    {
                        func_08075F20(0xCC);
                        d0 += p->a;
                        d1 += p->b;
                        d2 += p->c;
                        d3 += p->d;
                        (*v)++;
                        state = 0x20;
                        break;
                    }
                    func_08075F20(0x114);
                }
                else if (D_0300000E & 1)
                {
                    if (vals[0] != 0 || vals[1] != 0 || vals[2] != 0 || vals[3] != 0)
                    {
                        func_08075F20(0xCA);
                        func_0807C290(D_08006D66);
                        func_080771F4(obj);
                        func_0808A86C(0);
                        state = 0x1000;
                        break;
                    }
                    func_08075F20(0x114);
                }
                else if (D_0300000E & 2)
                {
                    func_08075F20(0xCB);
                    func_0807C290(D_08006D66);
                    func_080771F4(obj);
                    func_0808A86C(0);
                    done = 1;
                    break;
                }
            }
            break;
        case 0x1000:
            func_080B4D70();
            func_0807C290(D_08006DC4);
            func_0807BA24(w->field_68, 4, 0, 0x12, 0, 4, 0);
            func_0807BA24(w->field_6A, 4, 0, 0x12, 0, 4, 2);
            func_0807BA24(w->field_6C, 4, 0, 0x12, 0, 4, 4);
            func_0807BA24(w->field_6E, 4, 0, 0x12, 0, 4, 6);
            func_0807BA24(d0, 4, d0 != 0 ? (d0 > 0 ? 2 : 1) : 0, 0x16, 0, 8, 0);
            func_0807BA24(d1, 4, d1 != 0 ? (d1 > 0 ? 2 : 1) : 0, 0x16, 0, 8, 2);
            func_0807BA24(d2, 4, d2 != 0 ? (d2 > 0 ? 2 : 1) : 0, 0x16, 0, 8, 4);
            func_0807BA24(d3, 4, d3 != 0 ? (d3 > 0 ? 2 : 1) : 0, 0x16, 0, 8, 6);
            func_0807BA24(w->field_68 + d0, 4, 0, 0x12, 0, 0xE, 0);
            func_0807BA24(w->field_6A + d1, 4, 0, 0x12, 0, 0xE, 2);
            func_0807BA24(w->field_6C + d2, 4, 0, 0x12, 0, 0xE, 4);
            func_0807BA24(w->field_6E + d3, 4, 0, 0x12, 0, 0xE, 6);
            func_0807BA24(cost, 9, 0, 0x12, 0, 8, 8);
            func_0807C290(D_08006E7E);
            if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
            {
                func_08075F20(0xDB);
                z->field_A += d0;
                z->field_C += d1;
                z->field_E += d2;
                z->field_10 += d3;
                if (z->field_2 != 0xFF)
                    func_080BDDE4(z, &D_02027A10[z->field_2], 0);
                else
                    func_080BDDE4(z, 0, 0);
                *money -= cost;
                func_080B4D10(8);
                func_0807C290(D_08006F58);
                done = 1;
                break;
            }
            state = 0;
            break;
        }
    }
    D_0300004C &= 0xFDFF;
    D_03000052 &= 0x3FFC;
    func_080B4D70();
}
