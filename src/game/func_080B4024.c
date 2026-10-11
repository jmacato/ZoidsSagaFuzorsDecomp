#include "types.h"

struct Game
{
    u8 pad_0[0x7904];
    u8 owned[0x158];
    u32 money;
};

struct Part
{
    u8 data[0x18];
};

void func_0808A340(u8);
void func_0807C290(const void *);
void func_0808AE2C(u8, u32);
void func_0808A7F8(u8, u8, u8, u8);
void func_0808BCA8(u32, const struct Part *, u32, u32);
void func_0807BA24(u32, u8, u8, u8, u8, u8, u8);
void func_0807B77C(const void *, u8, u8);
void func_0808A86C(u8);
s32 func_080B3CCC(s32, u8, u8, u8, u8);
void func_0808ADB8(s32, u8, u8, void *, void *);
void func_0807B748(const void *, u8, u8, s32, s16);
void func_0807F0F8(u8, u8);
void func_0807F2D4(u32);
void func_080B3C9C(void);
void func_08075F20(u16);
void func_0808BB48(void);

extern u16 D_02030F7C;
extern u16 D_02030C5C[][2];
extern const struct Part D_08741EF4[];
extern const u32 D_0877D15C[];
extern const u8 D_080F524C[];
extern u8 D_0200C4A0;
extern u8 D_0200C4A1;
extern u8 D_0200C4A2;
extern struct Game D_02020E4C;
extern u8 D_0203198C[];
extern u8 D_020319CC[];
extern const u8 D_0800608D[];
extern const u8 D_0800618C[];
extern const u8 D_080060BD[];
extern const u8 D_080061B6[];
extern const u8 D_08006142[];
extern const u8 D_080060C6[];
extern const u8 D_080060E2[];
extern const u8 D_0800615A[];
extern const u8 D_080060C1[];
extern const u8 D_080061D0[];

void func_080B4024(void)
{
    u32 item;
    u16 sel;
    u8 done;
    s32 count;
    s32 n;
    u32 total;

    func_0808A340(0);
    if (D_02030F7C != 0)
    {
        func_0807C290(D_0800608D);
        func_0808AE2C(4, 0);
        item = D_02030C5C[0][0];
        done = 0;
        do
        {
            func_0808A7F8(0, 1, 0xD8, 0x98);
            func_0807C290(D_0800618C);
            while (1)
            {
                func_0808BCA8(5, &D_08741EF4[item], 0, 1);
                func_0807BA24(D_0877D15C[item] / 2, 9, 0, 0x12, 5, 3, 0xA);
                func_0807B77C(D_080F524C, 0, 5);
                func_0807C290(D_080060BD);
                sel = D_0200C4A0;
                item = D_02030C5C[sel][0];
                if (D_0200C4A2 == 1)
                {
                    count = D_02020E4C.owned[item];
                    n = 1;
                    while (1)
                    {
                        func_0808A7F8(0, 3, 0xC8, 0x98);
                        func_0807C290(D_080061B6);
                        n = func_080B3CCC(n, count, 4, item, (D_0200C4A0 - D_0200C4A1) * 2);
                        if (n == 0)
                            break;
                        total = D_0877D15C[item] / 2 * n;
                        if (total > 999999999)
                            total = 999999999;
                        func_0808A86C(0);
                        func_0807C290(D_08006142);
                        func_0807C290(D_080060C6);
                        func_0808ADB8(item, n, 0xB, D_0203198C, D_020319CC);
                        func_0807B748(D_0203198C, 0, 6, 0, 0);
                        func_0807BA24(total, 9, 0, 0x12, 6, 4, 3);
                        func_0807C290(D_080060E2);
                        if (D_0200C4A2 == 1)
                        {
                            if (D_0200C4A0 == 0)
                            {
                                func_0807C290(D_0800615A);
                                func_0807F0F8(item, n);
                                func_0807F2D4(total);
                                func_0808A340(0);
                                func_080B3C9C();
                            }
                            break;
                        }
                    }
                    if (D_02030F7C != 0)
                    {
                        if (D_02030F7C <= sel)
                            sel = D_02030F7C - 1;
                        item = D_02030C5C[sel][0];
                        func_0808AE2C(4, 0);
                    }
                    else
                    {
                        func_08075F20(0x114);
                        func_0808BB48();
                        func_0807C290(D_080060C1);
                        func_0808A86C(0);
                        func_0807C290(D_080061D0);
                        return;
                    }
                    break;
                }
                if (D_0200C4A2 == 2)
                {
                    func_0808BB48();
                    func_0807C290(D_080060C1);
                    func_0808A86C(0);
                    done = 1;
                    break;
                }
            }
        } while (!done);
    }
    else
    {
        func_08075F20(0x114);
        func_0808A86C(0);
        func_0807C290(D_080061D0);
    }
}
