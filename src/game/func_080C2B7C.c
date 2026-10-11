#include "types.h"

struct Sprite
{
    u32 flags;
    s32 x;
    s32 y;
};

struct Menu
{
    struct Sprite *sprites[6];
    struct Sprite *icons[6];
    u32 field_30;
    struct Sprite *cursor;
};

struct Obj
{
    u8 field_0;
    u8 pad1[3];
    u16 flags;
};

struct Template
{
    u8 field_0;
    u8 field_1;
    u8 type;
    u8 pad3[0x31];
};

struct Data
{
    u8 pad0[0x2208];
    u8 slots[6];
};

struct Scroll
{
    s32 pad0[2];
    s32 field_8;
    s32 field_C;
};

extern struct Data D_02031A0C;
extern struct Menu D_02020E04;
extern u8 D_02030C25;
extern u8 D_02030B6C[];
extern u32 D_0201F5C4;
extern u16 D_0300004C;
extern u16 D_03000050;
extern struct Scroll D_03000060;
extern u32 D_03000084;
extern u16 D_030057EC;
extern u16 D_0300000E;
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern s16 D_0873555C[][2];
extern struct Template D_0873FCC8[];
extern const u8 *D_087A43E0[];
extern const u8 D_0800365D[];
extern const u8 D_0800375E[];
extern const u8 D_0800394E[];
extern const u8 D_080F5C80[];
extern const u8 D_08735574[];
extern const u8 D_087B4C9C[];

u32 func_0809A99C(u8, u8);
struct Obj *func_0809A908(u8, u8);
void func_0807C290(const u8 *);
void func_080C2920(void);
void func_080C8B7C(const void *, void *, u32);
void func_080780C0(const u8 *, u32, u32, u32, u32, u32);
void func_080C2988(u8);
void func_0807FF9C(const u8 *, u32, u32, u32);
void func_080C2AAC(u8);
void func_0808A7F8(u32, u32, u32, u32);
void func_0807B748(const u8 *, u32, u32, u32, s16);
void func_08090BB0(struct Obj *, u32, u8);
void func_0807A1A4(void);
void func_080C8FCC(u32);
void func_08075F20(u32);
void func_080C2878(u8);
void func_080771F4(struct Sprite *);
void func_0807BE64(u32);
void func_0807BEF4(u32, const u8 *, u8);
u32 func_08090F8C(struct Obj *, s32, u8, u8);
void func_080C28B4(u8, u8);
void func_0808A890(u32);
void func_0808A8B4(u32);

void func_080C2B7C(void)
{
    vu16 fill;
    u8 prev, held, sel;
    u8 i, j, cur, hl, k, mode, done;

    D_02030C25 = 0;
    for (i = 0; i < 6; i++)
    {
        if (func_0809A99C(0, i))
        {
            D_02031A0C.slots[i] = i;
            D_02030B6C[D_02030C25] = i;
            D_02030C25++;
        }
        else
        {
            D_02031A0C.slots[i] = 0xFF;
        }
    }
    func_0807C290(D_0800365D);
    func_080C2920();
    sel = 0;
    fill = D_0201F5C4;
    func_080C8B7C(&fill, (void *)0x06000800, 0x01000400);
    D_0300004C |= 0x200;
    D_03000050 = 0x109;
    D_03000060.field_8 = D_03000060.field_C = 0;
    func_080780C0(D_08735574, 1, 0x11, 4, 5, 2);
    func_080780C0(D_08735574, 1, 0x11, 9, 5, 2);
    func_080780C0(D_08735574, 1, 0x11, 0xE, 5, 2);
    func_080780C0(D_08735574, 1, 0x18, 4, 5, 2);
    func_080780C0(D_08735574, 1, 0x18, 9, 5, 2);
    func_080780C0(D_08735574, 1, 0x18, 0xE, 5, 2);
    for (i = 0; i < 6; i++)
        func_080C2988(i);
    func_0807FF9C(D_087B4C9C, 0, 0x1C0, 0xC);
    held = 0xFF;
    prev = 0;
    cur = 0;
    D_02020E04.cursor = 0;
    func_080C2AAC(0xFF);
    D_02020E04.field_30 = 0;
    func_0808A7F8(0, 1, 0xD8, 0x98);
    done = 0;
    while (!done)
    {
        hl = 0xFF;
        D_02020E04.cursor->x = D_0873555C[cur][0] << 8;
        D_02020E04.cursor->y = D_0873555C[cur][1] << 8;
        if (held != 0xFF)
        {
            if (D_02031A0C.slots[prev] != 0xFF)
            {
                D_02020E04.sprites[prev]->flags &= ~0x200000;
                func_0807B748(D_087A43E0[func_0809A908(0, D_02031A0C.slots[prev])->field_0], 0, 4, 0, prev * 2);
            }
            if (D_02031A0C.slots[cur] != 0xFF)
            {
                hl = cur;
                D_02020E04.sprites[cur]->flags |= 0x200000;
            }
        }
        if (cur % 3 != 1)
        {
            k = cur - cur % 3 + 1;
            if (D_02031A0C.slots[k] != 0xFF && D_0873FCC8[func_0809A908(0, D_02031A0C.slots[k])->field_0].type == 4)
                mode = 1;
            else
                mode = 2;
        }
        else
        {
            k = cur - 1;
            if (D_02031A0C.slots[k] != 0xFF && D_0873FCC8[func_0809A908(0, D_02031A0C.slots[k])->field_0].type != 0)
                mode = 2;
            else
            {
                k += 2;
                if (D_02031A0C.slots[k] != 0xFF && D_0873FCC8[func_0809A908(0, D_02031A0C.slots[k])->field_0].type != 0)
                    mode = 2;
                else
                    mode = 0;
            }
        }
        if (D_02031A0C.slots[cur] != 0xFF)
            func_08090BB0(func_0809A908(0, D_02031A0C.slots[cur]), mode, 1);
        else
            func_08090BB0(0, mode, 1);
        while (1)
        {
            if (hl != 0xFF)
            {
                if (!(D_03000084 & 0x3F) || (prev != cur && !(D_03000084 & 0x20)))
                {
                    func_0807B748(D_080F5C80, 0, 4, 0, hl * 2);
                    func_0807A1A4();
                }
                else if ((D_03000084 & 0x3F) == 0x20 || (prev != cur && (D_03000084 & 0x20)))
                {
                    func_0807B748(D_087A43E0[func_0809A908(0, D_02031A0C.slots[hl])->field_0], 0, 4, 0, hl * 2);
                    func_0807A1A4();
                }
            }
            prev = cur;
            func_080C8FCC(1);
            if (D_030057EC & 0x40)
            {
                func_08075F20(0xCC);
                if (cur % 3)
                    cur--;
                else
                    cur += 2;
                break;
            }
            if (D_030057EC & 0x80)
            {
                func_08075F20(0xCC);
                if (cur % 3 <= 1)
                    cur++;
                else
                    cur -= 2;
                break;
            }
            if (D_030057EC & 0x30)
            {
                func_08075F20(0xCC);
                if (cur / 3)
                    cur -= 3;
                else
                    cur += 3;
                break;
            }
            if (D_0300000E & 1)
            {
                func_08075F20(0xCA);
                if (held == 0xFF)
                {
                    if (D_02031A0C.slots[cur] != 0xFF)
                    {
                        held = D_02031A0C.slots[cur];
                        func_080C2878(cur);
                        func_080771F4(D_02020E04.sprites[cur]);
                        func_080771F4(D_02020E04.icons[cur]);
                        func_080C2920();
                        func_080C2AAC(held);
                        func_0808A7F8(0, 3, 0xC8, 0x98);
                        break;
                    }
                    func_0807BE64(7);
                    for (i = 0; i < D_02030C25; i++)
                        func_0807BEF4(7, D_087A43E0[func_0809A908(0, D_02030B6C[i])->field_0], func_0809A908(0, D_02030B6C[i])->flags & 1);
                    func_0808A7F8(0, 3, 0xC8, 0x98);
                    while (1)
                    {
                        u16 res;
                        func_08090BB0(func_0809A908(0, D_02030B6C[sel]), mode, 1);
                        func_0807C290(D_0800375E);
                        sel = D_0200C4A0;
                        res = D_0200C4A2;
                        if (res == 1)
                        {
                            if (func_08090F8C(func_0809A908(0, D_02030B6C[sel]), mode, cur, 1))
                            {
                                if (res &= func_0809A908(0, D_02030B6C[sel])->flags)
                                {
                                    for (i = 0; i < 6 && D_02031A0C.slots[i] != D_02030B6C[sel]; i++)
                                        ;
                                    func_080771F4(D_02020E04.sprites[i]);
                                    func_080771F4(D_02020E04.icons[i]);
                                }
                                func_08075F20(0xDD);
                                func_080C28B4(D_02030B6C[sel], cur);
                                func_080C2988(cur);
                                break;
                            }
                        }
                        else if (res == 2)
                            break;
                    }
                    func_080C2920();
                }
                else
                {
                    if (!func_08090F8C(func_0809A908(0, held), mode, cur, 1))
                        continue;
                    func_08075F20(0xDD);
                    if (D_02031A0C.slots[cur] != 0xFF)
                    {
                        func_080771F4(D_02020E04.sprites[cur]);
                        func_080771F4(D_02020E04.icons[cur]);
                    }
                    k = D_02031A0C.slots[cur];
                    func_080C28B4(held, cur);
                    func_080C2988(cur);
                    func_080C2920();
                    held = k;
                    func_080C2AAC(k);
                }
                func_0808A7F8(0, 1, 0xD8, 0x98);
                break;
            }
            if (D_0300000E & 2)
            {
                func_08075F20(0xCB);
                if (held == 0xFF)
                {
                    for (i = 0; i <= 5; i++)
                    {
                        if (func_0809A99C(0, i) && !(func_0809A908(0, i)->flags & 1))
                            break;
                    }
                    if (i == 6)
                    {
                        done = 1;
                        break;
                    }
                    func_0808A890(0);
                    func_0807C290(D_0800394E);
                    func_0808A8B4(0);
                }
                else
                {
                    held = 0xFF;
                    func_080C2AAC(0xFF);
                    if (hl != 0xFF)
                    {
                        D_02020E04.sprites[hl]->flags &= ~0x200000;
                        func_0807B748(D_087A43E0[func_0809A908(0, D_02031A0C.slots[hl])->field_0], 0, 4, 0, hl * 2);
                        func_0807A1A4();
                    }
                    func_0808A7F8(0, 1, 0xD8, 0x98);
                }
                break;
            }
        }
    }
    for (i = 0, j = 0; i <= 5; i++)
    {
        if (D_02031A0C.slots[i] == 0xFF)
        {
            while (j <= 5 && func_0809A99C(0, j))
                j++;
            D_02031A0C.slots[i] = j;
            j++;
        }
    }
}
