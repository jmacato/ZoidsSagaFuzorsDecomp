#include "types.h"

struct Zoid
{
    u8 species;
    u8 pad_1[0x93];
};

struct Game
{
    u8 pad_0[0x3C];
    struct Zoid zoids[186];
    u8 pad_6BC4[0xE98];
    u32 money;
};

struct Win
{
    u32 flags;
};

void func_080B4DE8(void);
void func_0807C290(const void *);
struct Win *func_080771BC(const void *, const void *, u16, s16, s16, u16, u16, u32, u32);
void func_0808AC1C(u8, u8);
void func_0808A7F8(u8, u8, u8, u8);
u32 func_080BE174(struct Zoid *);
void func_0808B590(struct Zoid *, u8, struct Win *, struct Win *, u8);
void func_0807BA24(u32, u8, u8, u8, u8, u8, u8);
void func_0807B77C(const void *, u8, u8);
void func_080771F4(void *);
void func_080B4DB4(void);
s32 func_0808B2F8(u8, u8, u8);
void func_0808A86C(u8);
void func_080BE378(struct Zoid *);
void func_080B4D10(u8);
void func_08089CE0(u8, u8);
void func_08075F20(u16);

extern u8 D_02030B6C[];
extern struct Zoid D_02020E88[];
extern struct Game D_02020E4C;
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern u16 D_0200C4A4;
extern u8 D_0200C4BC;
extern u8 D_02030C25;
extern const u8 D_080068C6[];
extern const u8 D_08424594[];
extern const u8 D_084245A0[];
extern const u8 D_080F2354[];
extern const u8 D_080F2390[];
extern const u8 D_08006929[];
extern const u8 D_080F5AE0[];
extern const u8 D_080068F4[];
extern const u8 D_080068F8[];
extern const u8 D_080068FF[];
extern const u8 D_08006951[];
extern const u8 D_08006987[];
void func_080B5B88(void)
{
    s32 state;
    u8 sel;
    u8 done;
    struct Win *a;
    struct Win *b;
    struct Zoid *z;
    u32 cost;

    func_080B4DE8();
    func_0807C290(D_080068C6);
    a = func_080771BC(D_08424594, D_084245A0, 0, 0xC8, 0x68, 0, 0, 8, 0);
    b = func_080771BC(D_080F2354, D_080F2390, 0, 0x88, 0x50, 0x30D, 0xF, 8, 0);
    state = 0;
    sel = 0;
    done = 0;
    do
    {
        switch (state)
        {
        case 0:
            func_0807C290(D_08006929);
            func_0808AC1C(6, 0);
            state = 0x10;
            break;
        case 0x10:
            func_0808A7F8(0, 1, 0xD8, 0x98);
            func_0808A7F8(1, 0x10, 0xA0, 0x98);
            while (1)
            {
                z = &D_02020E88[D_02030B6C[sel]];
                cost = func_080BE174(z) / 20;
                func_0808B590(z, 7, a, b, 0);
                func_0807BA24(cost, 9, 0, 0x12, 7, 3, 0xD);
                func_0807B77C(D_080F5AE0, 0, 7);
                func_0807C290(D_080068F4);
                sel = D_0200C4A0;
                if (D_0200C4A2 == 1)
                {
                    state = 0x20;
                    break;
                }
                if (D_0200C4A2 == 2)
                {
                    func_0807C290(D_080068F8);
                    func_080771F4(a);
                    func_080771F4(b);
                    func_080B4DB4();
                    done = 1;
                    break;
                }
                if (D_0200C4A4 & 8)
                {
                    a->flags |= 0x20000;
                    if (func_0808B2F8(6, 2, 0))
                        sel = 0;
                    a->flags &= ~0x20000;
                }
            }
            func_0808A86C(0);
            func_0808A86C(1);
            break;
        case 0x20:
            D_0200C4BC = D_02020E4C.zoids[D_02030B6C[sel]].species;
            func_0807C290(D_080068FF);
            if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
            {
                if (D_02020E4C.money >= cost)
                {
                    func_0807C290(D_08006951);
                    func_080BE378(z);
                    D_02020E4C.money -= cost;
                    func_080B4D10(0);
                    func_08089CE0(2, 0);
                    if (D_02030C25 != 0)
                    {
                        if (D_02030C25 <= sel)
                            sel = D_02030C25 - 1;
                    }
                    else
                    {
                        func_0807C290(D_080068F8);
                        func_080771F4(a);
                        func_080771F4(b);
                        func_080B4DB4();
                        return;
                    }
                }
                else
                {
                    func_08075F20(0x114);
                    func_0807C290(D_08006987);
                }
                state = 0;
            }
            else
            {
                state = 0x10;
            }
            break;
        }
    } while (!done);
}
