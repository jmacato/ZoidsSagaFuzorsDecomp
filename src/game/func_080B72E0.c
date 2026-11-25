#include "types.h"

struct Win
{
    u8 pad_0[0x16];
    u8 field_16;
    u8 pad_17[0x4B9];
};

struct Zoid
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 pad_3;
    u16 flags;
    u8 pad_6[0x8E];
};

struct Save
{
    u8 pad_0[0x7A5C];
    u32 money;
};

struct Obj
{
    u32 flags;
};

void func_0807C290(const void *);
void func_0808A7F8(u8, u8, u8, u8);
void func_080B4DE8(void);
void func_0808A86C(u8);
void func_080B4D70(void);
void func_080B4D10(u8);
void func_08089CE0(u8, u8);
void func_0808AC1C(u8, u32);
struct Obj *func_080771BC(const void *, const void *, s32, s32, s32, s32, s32, s32, s32);
void func_080771F4(struct Obj *);
void func_080B4D54(void);
void func_080B4DB4(void);
s32 func_0808B590(struct Zoid *, u8, struct Obj *, struct Obj *, u8);
void func_08075F20(u16);
void func_0808A890(u32);
void func_0808A8B4(u32);
s32 func_0808B2F8(u8, u32, u32);
void func_080B69B4(struct Zoid *);
void func_080B61F0(struct Zoid *);
u8 func_080B512C(struct Zoid *);
void func_0807BA24(s32, u8, u8, u8, u8, u8, u8);

extern struct Win D_02009480[];
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern u16 D_0200C4A4;
extern u8 D_02030B6C[];
extern struct Zoid D_02020E88[];
extern struct Save D_02020E4C;
extern const u8 D_08006B4B[];
extern const u8 D_08006BA4[];
extern const u8 D_08006B9D[];
extern const u8 D_08006BA1[];
extern const u8 D_08006C12[];
extern const u8 D_08424594[];
extern const u8 D_084245A0[];
extern const u8 D_080F2354[];
extern const u8 D_080F2390[];
extern const u8 D_08006F2A[];
extern const u8 D_08006E84[];
extern const u8 D_08006F90[];
extern const u8 D_08006C5B[];
extern const u8 D_08006C5F[];
extern const u8 D_08006FE8[];
extern const u8 D_0800703F[];
extern const u8 D_08006E35[];
extern const u8 D_08006E7E[];
extern const u8 D_08006FC2[];
extern const u8 D_08006BCC[];

void func_080B72E0(void)
{
    u8 mode;
    s32 state;
    u8 done;
    u8 sel;
    u8 ret;
    struct Obj *a;
    struct Obj *b;
    struct Zoid *z;

    mode = 0;
    state = 0;
    done = 0;
    while (!done)
    {
        switch (state)
        {
        case 0:
            func_0807C290(D_08006B4B);
            func_0808A7F8(0, 3, 0x58, 0x48);
            D_02009480[4].field_16 = mode;
            state = 0x10;
            break;
        case 0x10:
            func_0807C290(D_08006BA4);
            func_0807C290(D_08006B9D);
            mode = D_0200C4A0;
            if (D_0200C4A2 == 1)
            {
                func_080B4DE8();
                state = 0x1000;
            }
            else
            {
                done = 1;
            }
            func_0807C290(D_08006BA1);
            func_0808A86C(0);
            break;
        case 0x1000:
            func_0807C290(D_08006C12);
            func_080B4D70();
            func_080B4D10(8);
            func_08089CE0(0, 0);
            func_0808AC1C(6, 8);
            a = func_080771BC(D_08424594, D_084245A0, 0, 0xC8, 0x68, 0x180, 3, 8, 0);
            b = func_080771BC(D_080F2354, D_080F2390, 0, 0x88, 0x50, 0x30D, 0xF, 8, 0);
            sel = 0;
            state = 0x1010;
            break;
        case 0x1010:
            func_0808A7F8(0, 1, 0xD8, 0x98);
            func_0808A7F8(1, 0x10, 0xA0, 0x98);
            switch (mode)
            {
            case 0:
                func_0807C290(D_08006F2A);
                break;
            case 1:
                func_0807C290(D_08006E84);
                break;
            case 2:
                func_0807C290(D_08006F90);
                break;
            }
            while (1)
            {
                z = &D_02020E88[D_02030B6C[sel]];
                func_0808B590(z, 7, a, b, 0);
                func_0807C290(D_08006C5B);
                sel = D_0200C4A0;
                if (D_0200C4A2 == 1)
                {
                    if (!(z->flags & 4))
                    {
                        state = 0x1020;
                        break;
                    }
                    func_08075F20(0x114);
                    func_0808A890(0);
                    func_0808A890(1);
                    if (z->field_2 != 0xFF)
                        func_0807C290(D_08006FE8);
                    else
                        func_0807C290(D_0800703F);
                    func_0808A8B4(0);
                    func_0808A8B4(1);
                }
                else if (D_0200C4A2 == 2)
                {
                    func_0807C290(D_08006C5F);
                    func_080771F4(a);
                    func_080771F4(b);
                    func_080B4D54();
                    func_080B4DB4();
                    state = 0;
                    break;
                }
                else if (D_0200C4A4 & 8)
                {
                    a->flags |= 0x20000;
                    if (func_0808B2F8(6, 0, 8))
                        sel = 0;
                    a->flags &= ~0x20000;
                }
            }
            func_0808A86C(0);
            func_0808A86C(1);
            break;
        case 0x1020:
            switch (mode)
            {
            case 0:
                state = 0x2000;
                break;
            case 1:
                state = 0x3000;
                break;
            case 2:
                state = 0x4000;
                break;
            }
            break;
        case 0x2000:
            a->flags = (a->flags & ~0xC0) | 0x40;
            b->flags = (b->flags & ~0xC0) | 0x40;
            func_080B69B4(z);
            a->flags &= ~0xC0;
            b->flags &= ~0xC0;
            state = 0x1010;
            break;
        case 0x3000:
            a->flags = (a->flags & ~0xC0) | 0x40;
            b->flags = (b->flags & ~0xC0) | 0x40;
            func_080B61F0(z);
            a->flags &= ~0xC0;
            b->flags &= ~0xC0;
            state = 0x1010;
            break;
        case 0x4000:
            a->flags |= 0x20000;
            b->flags |= 0x20000;
            func_080B4D54();
            ret = func_080B512C(z);
            a->flags &= ~0x20000;
            b->flags &= ~0x20000;
            func_080B4D70();
            if (ret != 0xFF && ret != z->field_1)
            {
                func_0807C290(D_08006E35);
                func_0807BA24(100, 9, 0, 0x12, 0, 8, 0);
                func_0807C290(D_08006E7E);
                if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
                {
                    if (D_02020E4C.money >= 100)
                    {
                        z->field_1 = ret;
                        D_02020E4C.money -= 100;
                        func_0808B590(z, 7, a, b, 0);
                        func_080B4D10(8);
                        func_0807C290(D_08006FC2);
                    }
                    else
                    {
                        func_08075F20(0x114);
                        func_0807C290(D_08006BCC);
                    }
                }
            }
            state = 0x1010;
            break;
        }
    }
}
