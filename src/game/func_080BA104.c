#include "types.h"

struct Win
{
    u8 pad_0[0x14];
    u8 field_14;
    u8 field_15;
    u8 field_16;
    u8 pad_17[0x4B9];
};

struct Save
{
    u32 seen[5];
    u32 owned[5];
};

void func_080B9EFC(void);
void func_0808A7F8(u8, u8, s16, s16);
void func_0807A1A4(void);
void func_0807970C(void);
void func_0807C290(const void *);
void func_0808A86C(u8);
void func_0807BEF4(u8, const void *, u8);
void func_08075F20(u16);
void func_08079544(s32, s32);
void func_080B975C(const u8 *, u8);
void func_080B9A78(const u8 *, u8);
const u8 *func_08082E70(u8);
void func_080B9D88(void);

extern struct Win D_02009480[];
extern u8 D_0200C4A0;
extern u8 D_0200C4A1;
extern u8 D_0200C4A2;
extern struct Save D_02030504;
extern const u8 D_0873F644[][5][33];
extern const u8 D_0873F833[][3][31];
extern const u8 *const D_087A43E0[];
extern const u8 D_080F5B80[];
extern const u8 D_08007434[];
extern const u8 D_0800743E[];
extern const u8 D_08007449[];
extern const u8 D_08007473[];
extern const u8 D_08007477[];
extern const u8 D_0800747A[];
extern const u8 D_08007485[];
extern const u8 D_080074A5[];
extern const u8 D_080074B0[];
extern const u8 D_080074DD[];
extern const u8 D_080074E8[];
extern const u8 D_08007520[];
extern const u8 D_08007524[];
extern const u8 D_08007527[];
extern const u8 D_08007541[];
extern const u8 D_08007545[];
extern const u8 D_08007576[];
extern const u8 D_08007581[];
extern const u8 D_08007592[];
extern const u8 D_08007596[];
extern const u8 D_08007599[];
extern const u8 D_080075A4[];
extern const u8 D_080075D2[];
extern const u8 D_080075DD[];
extern const u8 D_08007625[];
extern const u8 D_08007629[];
extern const u8 D_0800762C[];
extern const u8 D_08007645[];
extern const u8 D_08007649[];

void func_080BA104(void)
{
    u8 sel[2];
    u8 top[2];
    u8 last;
    u8 idx;
    s32 x;
    s32 y;
    s32 state;
    u8 done;
    u8 i;
    u8 n;
    u8 id;

    last = 0;
    state = 0;
    done = 0;
    while (!done)
    {
        switch (state)
        {
        case 0:
            func_080B9EFC();
            state = 0x10;
            break;
        case 0x10:
            func_0808A7F8(0, 1, 0xD8, 0x98);
            func_0807A1A4();
            func_0807970C();
            state = 0x20;
            break;
        case 0x20:
            D_02009480[1].field_16 = last;
            func_0807C290(D_08007434);
            if (D_0200C4A2 == 1)
            {
                last = D_0200C4A0;
                func_0808A86C(0);
                top[0] = sel[0] = 0;
                switch (D_0200C4A0)
                {
                case 0:
                    state = 0x1000;
                    break;
                case 1:
                    state = 0x2000;
                    break;
                case 2:
                    state = 0x3000;
                    break;
                }
            }
            else
            {
                done = 1;
            }
            break;
        case 0x1000:
            func_0807C290(D_0800743E);
            D_02009480[2].field_14 = D_02009480[2].field_15 = top[0];
            D_02009480[2].field_16 = sel[0];
            func_0807C290(D_08007449);
            state = 0x1010;
            break;
        case 0x1010:
            func_0808A7F8(0, 3, 0x48, 0x70);
            func_0807C290(D_08007473);
            if (D_0200C4A2 == 1)
            {
                top[0] = D_0200C4A1;
                sel[0] = D_0200C4A0;
                sel[1] = 0;
                top[1] = 0;
                state = 0x1100;
            }
            else
            {
                func_0807C290(D_08007477);
                state = 0x10;
            }
            func_0808A86C(0);
            break;
        case 0x1100:
            switch (sel[0])
            {
            case 0:
                func_0807C290(D_0800747A);
                D_02009480[3].field_14 = D_02009480[3].field_15 = top[1];
                D_02009480[3].field_16 = sel[1];
                func_0807C290(D_08007485);
                x = 0x40;
                y = 0x78;
                break;
            case 1:
                func_0807C290(D_080074A5);
                D_02009480[3].field_14 = D_02009480[3].field_15 = top[1];
                D_02009480[3].field_16 = sel[1];
                func_0807C290(D_080074B0);
                x = 0x60;
                y = 0x68;
                break;
            case 2:
                func_0807C290(D_080074DD);
                D_02009480[3].field_14 = D_02009480[3].field_15 = top[1];
                D_02009480[3].field_16 = sel[1];
                func_0807C290(D_080074E8);
                x = 0x48;
                y = 0x98;
                break;
            }
            state = 0x1110;
            break;
        case 0x1110:
            func_0808A7F8(0, 3, x, y);
            func_0807A1A4();
            func_0807970C();
            state = 0x1120;
            break;
        case 0x1120:
            func_0807C290(D_08007520);
            if (D_0200C4A2 == 1)
            {
                top[1] = D_0200C4A1;
                sel[1] = D_0200C4A0;
                state = 0x1200;
            }
            else
            {
                func_0807C290(D_08007524);
                state = 0x1010;
            }
            func_0808A86C(0);
            break;
        case 0x1200:
            func_0808A7F8(0, 3, 0xB8, 0x98);
            func_0807C290(D_08007527);
            n = D_0873F644[sel[0]][sel[1]][0];
            for (i = 0; i < n; i++)
            {
                id = D_0873F644[sel[0]][sel[1]][i + 1];
                if (D_02030504.seen[id >> 5] & (1 << (id & 31)))
                    func_0807BEF4(4, D_087A43E0[id], 0);
                else
                    func_0807BEF4(4, D_080F5B80, 0);
            }
            state = 0x1210;
            break;
        case 0x1210:
            func_0807C290(D_08007541);
            if (D_0200C4A2 == 1)
            {
                idx = D_0200C4A0 + 1;
                id = D_0873F644[sel[0]][sel[1]][idx];
                if (D_02030504.seen[id >> 5] & (1 << (id & 31)))
                    state = 0x1300;
                else
                    func_08075F20(0x114);
            }
            else
            {
                func_0807C290(D_08007545);
                func_0808A86C(0);
                state = 0x1110;
            }
            break;
        case 0x1300:
            func_08079544(0x10, 0);
            func_0807970C();
            func_080B975C(D_0873F644[sel[0]][sel[1]], idx);
            func_080B9EFC();
            func_0807C290(D_0800743E);
            D_02009480[2].field_14 = D_02009480[2].field_15 = top[0];
            D_02009480[2].field_16 = sel[0];
            func_0807C290(D_08007449);
            state = 0x1100;
            break;
        case 0x2000:
            func_0807C290(D_08007576);
            D_02009480[2].field_14 = D_02009480[2].field_15 = top[0];
            D_02009480[2].field_16 = sel[0];
            func_0807C290(D_08007581);
            state = 0x2010;
            break;
        case 0x2010:
            func_0808A7F8(0, 3, 0x1B, 0x60);
            func_0807C290(D_08007592);
            if (D_0200C4A2 == 1)
            {
                top[0] = D_0200C4A1;
                sel[0] = D_0200C4A0;
                sel[1] = 0;
                top[1] = 0;
                state = 0x2100;
            }
            else
            {
                func_0807C290(D_08007596);
                state = 0x10;
            }
            func_0808A86C(0);
            break;
        case 0x2100:
            switch (sel[0])
            {
            case 0:
                func_0807C290(D_08007599);
                D_02009480[3].field_14 = D_02009480[3].field_15 = top[1];
                D_02009480[3].field_16 = sel[1];
                func_0807C290(D_080075A4);
                x = 0x58;
                y = 0x80;
                break;
            case 1:
                func_0807C290(D_080075D2);
                D_02009480[3].field_14 = D_02009480[3].field_15 = top[1];
                D_02009480[3].field_16 = sel[1];
                func_0807C290(D_080075DD);
                x = 0x70;
                y = 0x80;
                break;
            }
            state = 0x2110;
            break;
        case 0x2110:
            func_0808A7F8(0, 3, x, y);
            func_0807A1A4();
            func_0807970C();
            state = 0x2120;
            break;
        case 0x2120:
            func_0807C290(D_08007625);
            if (D_0200C4A2 == 1)
            {
                top[1] = D_0200C4A1;
                sel[1] = D_0200C4A0;
                state = 0x2200;
            }
            else
            {
                func_0807C290(D_08007629);
                state = 0x2010;
            }
            func_0808A86C(0);
            break;
        case 0x2200:
            func_0808A7F8(0, 3, 0xB8, 0x98);
            func_0807C290(D_0800762C);
            n = D_0873F833[sel[0]][sel[1]][0];
            for (i = 0; i < n; i++)
            {
                id = D_0873F833[sel[0]][sel[1]][i + 1];
                if (D_02030504.owned[id >> 5] & (1 << (id & 31)))
                    func_0807BEF4(4, func_08082E70(id), 0);
                else
                    func_0807BEF4(4, D_080F5B80, 0);
            }
            state = 0x2210;
            break;
        case 0x2210:
            func_0807C290(D_08007645);
            if (D_0200C4A2 == 1)
            {
                idx = D_0200C4A0 + 1;
                id = D_0873F833[sel[0]][sel[1]][idx];
                if (D_02030504.owned[id >> 5] & (1 << (id & 31)))
                    state = 0x2300;
                else
                    func_08075F20(0x114);
            }
            else
            {
                func_0807C290(D_08007649);
                func_0808A86C(0);
                state = 0x2110;
            }
            break;
        case 0x2300:
            func_08079544(0x10, 0);
            func_0807970C();
            func_080B9A78(D_0873F833[sel[0]][sel[1]], idx);
            func_080B9EFC();
            func_0807C290(D_08007576);
            D_02009480[2].field_14 = D_02009480[2].field_15 = top[0];
            D_02009480[2].field_16 = sel[0];
            func_0807C290(D_08007581);
            state = 0x2100;
            break;
        case 0x3000:
            func_080B9D88();
            state = 0x10;
            break;
        }
    }
    func_08079544(0x10, 0);
    func_0807970C();
}
