#include "types.h"

struct Game
{
    u8 pad_0[0x79CC];
    u8 owned[0x90];
    u32 money;
};

void func_0808A3A0(u8);
void func_0807C290(const void *);
void func_0808B028(u8);
void func_0808A7F8(u8, u8, u8, u8);
void func_0807BD4C(u8);
void func_0807B77C(const void *, u8, u8);
void func_0807BA24(u32, u8, u8, u8, u8, u8, u8);
void func_0808A86C(u8);
s32 func_080B469C(s32, u8, u8, u8, u8);
void func_0808AFB4(s32, u8, u8, void *, void *);
void func_0807B748(const void *, u8, u8, s32, s16);
void func_0807F15C(u8, u8);
void func_0807F2D4(u32);
void func_080B4360(void);
void func_08075F20(u16);

extern u8 D_02030F90;
extern u8 D_02030F7E[][2];
extern const u8 *const D_087A5574[];
extern const u32 D_0877D47C[];
extern const u8 D_080F5250[];
extern u8 D_0200C4A0;
extern u8 D_0200C4A1;
extern u8 D_0200C4A2;
extern struct Game D_02020E4C;
extern u8 D_0203198C[];
extern u8 D_020319CC[];
extern const u8 D_08005E22[];
extern const u8 D_08005F64[];
extern const u8 D_08005E55[];
extern const u8 D_08005F98[];
extern const u8 D_08005F04[];
extern const u8 D_08005E5E[];
extern const u8 D_08005E7A[];
extern const u8 D_08005F22[];
extern const u8 D_08005E59[];
extern const u8 D_08005FBC[];

void func_080B49E4(void)
{
    u32 item;
    u16 sel;
    u8 done;
    s32 count;
    s32 n;
    u32 total;

    func_0808A3A0(0);
    if (D_02030F90 != 0)
    {
        func_0807C290(D_08005E22);
        func_0808B028(4);
        item = D_02030F7E[0][0];
        done = 0;
        do
        {
            func_0808A7F8(0, 1, 0xD8, 0x98);
            func_0807C290(D_08005F64);
            while (1)
            {
                func_0807BD4C(5);
                func_0807B77C(D_087A5574[item], 0, 5);
                func_0807BA24(D_0877D47C[item] / 2, 9, 0, 0x12, 5, 3, 0xA);
                func_0807B77C(D_080F5250, 0, 5);
                func_0807C290(D_08005E55);
                sel = D_0200C4A0;
                item = D_02030F7E[sel][0];
                if (D_0200C4A2 == 1)
                {
                    count = D_02020E4C.owned[item];
                    n = 1;
                    while (1)
                    {
                        func_0808A7F8(0, 3, 0xC8, 0x98);
                        func_0807C290(D_08005F98);
                        n = func_080B469C(n, count, 4, item, (D_0200C4A0 - D_0200C4A1) * 2);
                        if (n == 0)
                            break;
                        total = D_0877D47C[item] / 2 * n;
                        if (total > 999999999)
                            total = 999999999;
                        func_0808A86C(0);
                        func_0807C290(D_08005F04);
                        func_0807C290(D_08005E5E);
                        func_0808AFB4(item, n, 0xB, D_0203198C, D_020319CC);
                        func_0807B748(D_0203198C, 0, 6, 0, 0);
                        func_0807BA24(total, 9, 0, 0x12, 6, 4, 3);
                        func_0807C290(D_08005E7A);
                        if (D_0200C4A2 == 1)
                        {
                            if (D_0200C4A0 == 0)
                            {
                                func_0807C290(D_08005F22);
                                func_0807F15C(item, n);
                                func_0807F2D4(total);
                                func_0808A3A0(0);
                                func_080B4360();
                            }
                            break;
                        }
                    }
                    if (D_02030F90 != 0)
                    {
                        if (D_02030F90 <= sel)
                            sel = D_02030F90 - 1;
                        item = D_02030F7E[sel][0];
                        func_0808B028(4);
                    }
                    else
                    {
                        func_08075F20(0x114);
                        func_0807C290(D_08005E59);
                        func_0808A86C(0);
                        func_0807C290(D_08005FBC);
                        return;
                    }
                    break;
                }
                if (D_0200C4A2 == 2)
                {
                    func_0807C290(D_08005E59);
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
        func_0807C290(D_08005FBC);
    }
}
