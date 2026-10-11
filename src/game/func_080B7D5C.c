#include "types.h"

struct Entry
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[2];
    u8 field_4;
    u8 field_5;
    u8 pad_6[2];
    u32 field_8;
    u8 pad_C[4];
};

struct Obj
{
    u32 flags;
};

struct Scroll
{
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
};

void func_080C8B7C(const void *, void *, u32);
void func_0807C290(const void *);
void func_080B7CC8(u8, u8, u8);
void func_080B7D3C(u8, u8);
struct Obj *func_080771BC(const void *, const void *, s32, s32, s32, s32, s32, s32, s32);
void func_080785C0(u8, u8, u8, u8, u8);
void func_08078688(u8);
void func_0808A7F8(u8, u8, u8, u8);
void func_0807A1A4(void);
void func_080C8FCC(u32);
void func_08075F20(u16);
void func_0808A86C(u8);
void func_080B792C(u8, u8);
void func_080784F8(void);
void func_080771F4(struct Obj *);

extern u16 D_0300004C;
extern u16 D_03000050;
extern s16 D_03000052;
extern u16 D_03000056;
extern u16 D_0300005A;
extern u16 D_0300000E;
extern u16 D_030057EC;
extern struct Scroll D_03000060;
extern u32 D_0201F5C4;
extern u8 D_0200C4A2;
extern u8 D_0200C4A0;
extern const struct Entry D_0877C7FC[][10];
extern const u8 D_080071E2[];
extern const u8 D_08007243[];
extern const u8 D_0800726F[];
extern const u8 D_08007233[];
extern const u8 D_08007293[];
extern const u8 D_080071ED[];
extern const u8 D_080C9748[];
extern const u8 D_080C977C[];

void func_080B7D5C(u8 id)
{
    vu16 fill;
    const struct Entry *e;
    struct Obj *arrows[2];
    u8 sel;
    u8 prev;
    u8 count;
    s32 state;
    u8 done;
    s8 i;

    D_0300004C |= 0x200;
    D_03000050 = 0x4209;
    D_03000060.x1 = D_03000060.y1 = 0;
    D_03000052 = (D_03000052 & 0x3FFF) | 0xC000;
    fill = D_0201F5C4;
    func_080C8B7C(&fill, (void *)0x06000800, 0x01000C00);
    func_0807C290(D_080071E2);
    sel = 0;
    for (count = 0; count < 10; count++)
    {
        e = &D_0877C7FC[id][count];
        if (e->field_0 == 0 && e->field_4 == 0 && e->field_8 == 0)
            break;
    }
    func_080B7CC8(id, 0, count);
    func_080B7CC8(id, 1, count);
    arrows[0] = func_080771BC(D_080C9748, D_080C977C, 0, 0x2C, 0x38, 0x3F4, 0xF, 0x8020, 0);
    arrows[1] = func_080771BC(D_080C9748, D_080C977C, 0, 0xC4, 0x38, 0x3F4, 0xF, 0x20, 0);
    func_080785C0(0x28, 0, 0xC8, 0x80, 0x1F);
    func_08078688(0x3F);
    D_03000056 = 0xC2;
    D_0300005A = 8;
    state = 0;
    done = 0;
    while (!done)
    {
        switch (state)
        {
        case 0:
            func_0808A7F8(0, 1, 0xD8, 0x98);
            func_0807C290(D_08007243);
            func_0807A1A4();
            state = 0x10;
            break;
        case 0x10:
            prev = sel;
            if (sel == 0)
                arrows[0]->flags |= 0x20000;
            else
                arrows[0]->flags &= ~0x20000;
            if (sel == count - 1)
                arrows[1]->flags |= 0x20000;
            else
                arrows[1]->flags &= ~0x20000;
            for (;;)
            {
                func_080C8FCC(1);
                if ((D_030057EC & 0x20) && sel != 0)
                {
                    func_08075F20(0xCC);
                    sel--;
                    state = 0x20;
                    break;
                }
                if ((D_030057EC & 0x10) && sel < count - 1)
                {
                    func_08075F20(0xCC);
                    sel++;
                    state = 0x20;
                    break;
                }
                if (D_0300000E & 1)
                {
                    func_08075F20(0xCA);
                    state = 0x1000;
                    break;
                }
                if (D_0300000E & 2)
                {
                    func_08075F20(0xCB);
                    done = 1;
                    break;
                }
            }
            break;
        case 0x20:
            if (sel > prev)
            {
                func_080B7CC8(id, sel + 1, count);
                for (i = 0; i < 8; i++)
                {
                    D_03000060.x1 += 0x1400;
                    if (i == 4)
                        func_080B7D3C(sel - 2, count);
                    func_080C8FCC(1);
                }
            }
            else
            {
                func_080B7CC8(id, sel - 1, count);
                for (i = 0; i < 8; i++)
                {
                    D_03000060.x1 -= 0x1400;
                    if (i == 4)
                        func_080B7D3C(sel + 2, count);
                    func_080C8FCC(1);
                }
            }
            state = 0x10;
            break;
        case 0x1000:
            func_0808A86C(0);
            func_0807C290(D_0800726F);
            func_0807C290(D_08007233);
            if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
            {
                func_0807C290(D_08007293);
                func_080B792C(id, sel);
                done = 1;
            }
            else
            {
                state = 0;
            }
            break;
        }
    }
    D_03000056 = 0;
    func_080784F8();
    func_080771F4(arrows[0]);
    func_080771F4(arrows[1]);
    func_0807C290(D_080071ED);
    for (i = sel - 1; i < sel + 2; i++)
        func_080B7D3C(i, count);
    D_0300004C &= ~0x200;
    D_03000052 &= 0x3FFF;
}
