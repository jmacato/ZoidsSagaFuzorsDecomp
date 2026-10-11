#include "types.h"

struct Info
{
    u8 pad_0[0x2F];
    s8 stats[5];
    u8 pad_34[0xB];
    u8 field_3F;
};

struct State
{
    u8 pad_0[9];
    u8 field_9;
    u8 field_A;
    u8 pad_B[9];
    struct Info *info;
};

struct Win
{
    u8 pad_0[6];
    u16 top;
    u8 pad_8[0xC];
    u8 field_14;
    u8 field_15;
    u8 field_16;
    u8 pad_17[0x4B9];
};

struct Obj
{
    u8 pad_0[8];
    s32 y;
};

struct Camera
{
    u8 pad_0[0x10];
    s32 y;
};

extern struct State D_0201F5F8;
extern struct Win D_02009480[];
extern struct Camera D_03000060;
extern u8 D_0200C4A0;
extern u8 D_0200C4A1;
extern u8 D_0200C4A2;
extern u16 D_0200C4A4;
extern u16 D_030057EC;
extern u16 D_0300000E;
extern const s16 D_087472F4[][5];
extern const u8 *D_08735490[];
extern const u8 D_08001A84[];
extern const u8 D_08001A31[];
extern const u8 D_080F3874[];
extern const u8 D_080F387C[];
extern const u8 D_080F3884[];
extern const u8 D_080F388C[];
extern const u8 D_080F3790[];
extern const u8 D_080F38A0[];
extern const u8 D_080F38A4[];
extern const u8 D_080C9680[];
extern const u8 D_080C96B4[];
void func_0807C290(const u8 *);
void func_0807BAD4(u8, u8, u8, u8, u8, u8);
void func_0807B748(const u8 *, u32, u32, u32, u32);
void func_0807BA24(s32, u8, u8, u8, u8, u8, u8);
void func_0807B77C(const u8 *, u32, u32);
void func_0807BD8C(u8);
void func_0808DECC(void);
void func_0808E1B0(void);
struct Obj *func_080771BC(const u8 *, const u8 *, u32, u32, u32, u32, u32, u32, u32);
void func_0808A890(u32);
void func_0808A8B4(u32);
void func_0808A86C(u32);
void func_0808A7F8(u32, u32, u32, u32);
void func_080C8FCC(u32);
void func_08075F20(u32);
void func_0807A1A4(void);
void func_080771F4(struct Obj *);

s32 func_0808E608(void)
{
    u8 win;
    u8 next;
    u8 lim;
    u8 cur;
    u8 used;
    u8 i;
    u8 pts[5];
    struct Obj *cursor;
    u16 down;
    u16 dec;

    func_0807C290(D_08001A84);
    win = 5;
    while (1)
    {
        lim = (D_02009480[1].field_16 - D_02009480[1].field_14) * 2 + 1;
        if (lim > 6)
            lim = 6;
        func_0807BAD4(win, 7, lim + 0x20, 9, 7, 0);
        func_0807B748(D_080F3874, 0, win, 0, 0);
        func_0807B748(D_080F387C, 0, win, 0, 1);
        func_0807B748(D_080F3884, 0, win, 0, 2);
        func_0807B748(D_080F388C, 0, win, 0, 3);
        func_0807B748(D_080F3790, 0, win, 0, 4);
        if (D_0201F5F8.field_9 < 4)
        {
            func_0807BA24(D_087472F4[D_0201F5F8.field_9][0], 2, 0, 0x16, win, 4, 0);
            func_0807BA24(D_087472F4[D_0201F5F8.field_9][1], 2, 0, 0x16, win, 4, 1);
            func_0807BA24(D_087472F4[D_0201F5F8.field_9][2], 2, 0, 0x16, win, 4, 2);
            func_0807BA24(D_087472F4[D_0201F5F8.field_9][3], 2, 0, 0x16, win, 4, 3);
            func_0807BA24(D_087472F4[D_0201F5F8.field_9][4], 2, 0, 0x16, win, 4, 4);
        }
        else if (D_0201F5F8.field_9 == 4)
        {
            func_0807BA24(D_0201F5F8.info->stats[0], 2, 0, 0x16, win, 4, 0);
            func_0807BA24(D_0201F5F8.info->stats[1], 2, 0, 0x16, win, 4, 1);
            func_0807BA24(D_0201F5F8.info->stats[2], 2, 0, 0x16, win, 4, 2);
            func_0807BA24(D_0201F5F8.info->stats[3], 2, 0, 0x16, win, 4, 3);
            func_0807BA24(D_0201F5F8.info->stats[4], 2, 0, 0x16, win, 4, 4);
        }
        else
        {
            func_0807B748(D_080F38A0, 0, win, 4, 0);
            func_0807B748(D_080F38A0, 0, win, 4, 1);
            func_0807B748(D_080F38A0, 0, win, 4, 2);
            func_0807B748(D_080F38A0, 0, win, 4, 3);
            func_0807B748(D_080F38A0, 0, win, 4, 4);
        }
        func_0807C290(D_08735490[D_0201F5F8.field_9]);
        func_0807C290(D_08001A31);
        D_0201F5F8.field_A = D_0200C4A1;
        D_0201F5F8.field_9 = D_0200C4A0;
        next = win == 5 ? 6 : 5;
        if (D_0200C4A2 == 1)
        {
            D_0201F5F8.info->field_3F = D_0201F5F8.field_9;
            func_0808DECC();
            func_0808E1B0();
            if (D_0201F5F8.info->field_3F == 4)
            {
                cursor = func_080771BC(D_080C9680, D_080C96B4, 0, 0x38, 0, 0x3EE, 0xF, 0x20, 0);
                used = 0;
                cur = 0;
                pts[0] = D_0201F5F8.info->stats[0];
                pts[1] = D_0201F5F8.info->stats[1];
                pts[2] = D_0201F5F8.info->stats[2];
                pts[3] = D_0201F5F8.info->stats[3];
                pts[4] = D_0201F5F8.info->stats[4];
                func_0807BAD4(next, 7, lim + 0x27, 9, 3, 0);
                func_0807B77C(D_080F38A4, 0, next);
                func_0807BA24(used, 2, 0, 0x12, next, 5, 0);
                func_0808A890(0);
                func_0808A890(1);
                func_0808A7F8(2, 3, 0x58, (lim + 9) * 8);
                while (1)
                {
                    cursor->y = ((s16)(cur - 0x20) + D_02009480[win].top + 1) << 11;
                    func_080C8FCC(1);
                    if (D_030057EC & 0x40)
                    {
                        func_08075F20(0xCC);
                        if (cur != 0)
                            cur--;
                        else
                            cur = 4;
                    }
                    else if ((down = D_030057EC & 0x80) != 0)
                    {
                        func_08075F20(0xCC);
                        if (cur < 4)
                            cur++;
                        else
                            cur = 0;
                    }
                    else if ((dec = D_030057EC & 0x20) != 0)
                    {
                        if (pts[cur] == 0)
                        {
                            func_08075F20(0x114);
                        }
                        else
                        {
                            func_08075F20(0xCC);
                            pts[cur]--;
                            used++;
                            func_0807BA24(pts[cur], 2, 0, 0x16, win, 4, cur);
                            func_0807BA24(used, 2, 0, 0x12, next, 5, down);
                            func_0807A1A4();
                        }
                    }
                    else if (D_030057EC & 0x10)
                    {
                        if (used == 0)
                        {
                            func_08075F20(0x114);
                        }
                        else
                        {
                            func_08075F20(0xCC);
                            pts[cur]++;
                            used--;
                            func_0807BA24(pts[cur], 2, 0, 0x16, win, 4, cur);
                            func_0807BA24(used, 2, 0, 0x12, next, 5, dec);
                            func_0807A1A4();
                        }
                    }
                    else if (D_0300000E & 1)
                    {
                        if (used != 0)
                        {
                            func_08075F20(0x114);
                        }
                        else
                        {
                            func_08075F20(0xCA);
                            D_0201F5F8.info->stats[0] = pts[0];
                            D_0201F5F8.info->stats[1] = pts[1];
                            D_0201F5F8.info->stats[2] = pts[2];
                            D_0201F5F8.info->stats[3] = pts[3];
                            D_0201F5F8.info->stats[4] = pts[4];
                            break;
                        }
                    }
                    else if (D_0300000E & 2)
                    {
                        func_08075F20(0xCB);
                        break;
                    }
                }
                func_0807BD8C(next);
                func_0807A1A4();
                func_080771F4(cursor);
                func_0808A8B4(0);
                func_0808A8B4(1);
                func_0808A86C(2);
                func_080C8FCC(1);
            }
        }
        else if (D_0200C4A2 == 2)
        {
            func_0807BD8C(win);
            return -1;
        }
        else if (D_0200C4A4 & 0x200)
        {
            func_0807BD8C(win);
            func_0807A1A4();
            for (i = 0; i < 8; i++)
            {
                D_03000060.y -= 0xF00;
                func_080C8FCC(1);
            }
            return 0;
        }
        func_0807BD8C(win);
        win = next;
    }
}
