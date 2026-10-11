#include "types.h"

struct Item
{
    u16 flags;
    s16 value;
};

struct Zoid
{
    u8 species;
    u8 pad_1[3];
    u16 flags;
    s16 hp;
    u8 pad_8[0x5A];
    s16 maxhp;
    u8 pad_64[0x30];
};

struct Warp
{
    u8 field_0;
    u8 kind;
    u8 pad_2[2];
    s32 x;
    s32 y;
};

struct Map
{
    u16 field_0;
    u8 pad_2[0x18];
    u16 area;
    u8 pad_1C[0x408];
    struct Warp *warp;
};

struct Save
{
    u32 flags;
    u8 pad_4[0xC];
    s32 field_10;
    s32 field_14;
    u8 pad_18[8];
    u8 field_20;
    u8 pad_21[2];
    u8 field_23;
    u16 field_24;
    u16 field_26;
    u16 field_28;
    u8 field_2A;
    u8 pad_2B;
    s32 field_2C;
    s32 field_30;
    s32 field_34;
    s32 field_38;
};

struct Menu
{
    u8 pad_0[0x1824];
    u8 field_1824;
    u8 field_1825;
    u8 field_1826;
};

extern struct Save D_02020E4C;
extern struct Map D_020209D8;
extern struct Menu D_02009480;
extern struct Zoid D_02020E88[];
extern u8 D_0201F6DC;
extern u8 D_02030F90;
extern u8 D_02030F7E[][2];
extern u8 D_02030B6C[];
extern u8 D_0200C4A0;
extern u8 D_0200C4A1;
extern u8 D_0200C4A2;
extern u16 D_0200C4A4;
extern u32 D_0200C4AC;
extern u8 D_0200C4BC;
extern u8 D_0200C4D0;
extern const struct Item D_08759BCC[];
extern const u8 *D_087A5574[];
extern const u16 D_08785FDC[][26][5];
extern const u8 D_08001F23[];
extern const u8 D_08000BB4[];
extern const u8 D_08001F2A[];
extern const u8 D_08000BD3[];
extern const u8 D_08001EE2[];
extern const u8 D_08001FE5[];
extern const u8 D_08001F1F[];
extern const u8 D_0800216E[];
extern const u8 D_0800229E[];
extern const u8 D_080021B1[];
extern const u8 D_08002259[];
extern const u8 D_08002200[];
extern const u8 D_0800212B[];
extern const u8 D_08001F62[];
extern const u8 D_0800200B[];
extern const u8 D_08001FA3[];
extern const u8 D_080020D2[];
extern const u8 D_08001FAC[];
extern const u8 D_08002051[];
extern const u8 D_0800202F[];
extern const u8 D_08002073[];
extern const u8 D_08001FA7[];
extern const u8 D_080022E9[];
void func_0808A3A0(u32);
void func_0807C290(const u8 *);
void func_0808A86C(u32);
void func_0808AB28(void);
void func_08075F20(u32);
void func_0808AC08(void);
void func_0808B028(u8);
void func_0808A7F8(u32, u32, u32, u32);
void func_0807BD4C(u8);
void func_0807B77C(const u8 *, u32, u32);
void func_08089CE0(void *, s32);
void func_0808AC1C(u8, u32);
s32 func_0808A8DC(struct Zoid *);
void func_0807BA24(s32, u8, u8, u8, u8, u8, u8);
void func_0808A890(u32);
void func_0808A8B4(u32);
void func_080BE06C(struct Zoid *, s16);
u32 func_0807F15C(u8, u8);
s32 func_0808B2F8(u8, u32, u32);
void func_08079544(u8, u8);
void func_0807970C(void);
s32 func_08092B60(u8);
void func_08088D98(u16, s32, s32, s8);
u8 func_08082F4C(u8);
void func_08091DB4(void);
void func_0807A1A4(void);
void func_08075FC0(u16);
u8 func_080796EC(void);
s32 func_08075F5C(u16);
void func_080C8FCC(u32);

s32 func_0808F094(void)
{
    const struct Item *item;
    u8 opened;
    u8 sel1;
    u8 sel;
    s32 state;
    struct Zoid *zoid;
    s16 *maxhp;
    u8 idx;
    u16 full;
    u16 half;
    s32 r;
    u8 done;

    sel = 0;
    sel1 = 0;
    state = 0;
    opened = 0;
    done = 0;
    do
    {
        switch (state)
        {
        case 0:
            func_0808A3A0(0);
            if (D_02030F90 == 0)
            {
                if (opened)
                {
                    func_0807C290(D_08001F23);
                    func_0808A86C(0);
                    func_0808AB28();
                    func_0807C290(D_08000BB4);
                }
                func_08075F20(0x114);
                func_0807C290(D_08001F2A);
                return 0;
            }
            if (D_02030F90 <= sel)
                sel = D_02030F90 - 1;
            if (!opened)
            {
                func_0808AC08();
                func_0807C290(D_08000BD3);
                func_0807C290(D_08001EE2);
                opened = 1;
            }
            func_0808B028(5);
            func_0807C290(D_08001FE5);
            state = 0x10;
            break;
        case 0x10:
            func_0808A7F8(0, 1, 0xD8, 0x98);
            do
            {
                func_0807BD4C(6);
                func_0807B77C(D_087A5574[D_02030F7E[sel][0]], 0, 6);
                func_0807C290(D_08001F1F);
                sel1 = D_0200C4A1;
                sel = D_0200C4A0;
                if (D_0200C4A2 == 1)
                {
                    state = 0x20;
                    goto next;
                }
            } while (D_0200C4A2 != 2);
            func_0807C290(D_08001F23);
            func_0808A86C(0);
            func_0808AB28();
            func_0807C290(D_08000BB4);
            return 0;
        case 0x20:
            func_0808A86C(0);
            item = &D_08759BCC[D_02030F7E[sel][0]];
            if (item->flags & 7)
            {
                state = 0x1000;
            }
            else if (item->flags & 0x20)
            {
                if (D_0201F6DC != 0 || (D_02020E4C.flags & 4))
                {
                    func_08075F20(0x114);
                    func_0807C290(D_0800216E);
                    state = 0x10;
                }
                else if ((u16)(D_020209D8.field_0 - 0xA8) <= 3)
                {
                    func_08075F20(0x114);
                    func_0807C290(D_0800229E);
                    state = 0x10;
                }
                else if (D_020209D8.warp->kind == 0x8A)
                {
                    func_08075F20(0x114);
                    func_0807C290(D_080021B1);
                    state = 0x10;
                }
                else if (D_020209D8.warp->kind == 1)
                {
                    func_08075F20(0x114);
                    func_0807C290(D_08002259);
                    state = 0x10;
                }
                else
                {
                    state = 0x2000;
                }
            }
            else if (item->flags & 0x40)
            {
                if (D_0201F6DC != 0 || (D_02020E4C.flags & 4))
                {
                    func_08075F20(0x114);
                    func_0807C290(D_0800216E);
                    state = 0x10;
                }
                else if ((u16)(D_020209D8.field_0 - 0xA8) <= 3)
                {
                    func_08075F20(0x114);
                    func_0807C290(D_0800229E);
                    state = 0x10;
                }
                else if (D_020209D8.warp->kind == 0x8A)
                {
                    func_08075F20(0x114);
                    func_0807C290(D_080021B1);
                    state = 0x10;
                }
                else if (D_020209D8.warp->kind == 1)
                {
                    func_08075F20(0x114);
                    func_0807C290(D_08002259);
                    state = 0x10;
                }
                else if (D_02020E4C.field_26 == 0xFFFF)
                {
                    func_08075F20(0x114);
                    func_0807C290(D_08002200);
                    state = 0x10;
                }
                else
                {
                    state = 0x3000;
                }
            }
            else
            {
                func_0807C290(D_0800212B);
                state = 0x10;
            }
            break;
        case 0x1000:
            func_0807C290(D_08001F62);
            func_0807C290(D_0800200B);
            func_08089CE0(0, 0);
            func_0808AC1C(8, 2);
            func_0808A7F8(0, 3, 0xC8, 0x98);
            func_0808A7F8(1, 0x10, 0x90, 0x98);
            idx = 0;
            while (1)
            {
                zoid = &D_02020E88[D_02030B6C[idx]];
                func_0807BA24(zoid->hp, 4, func_0808A8DC(zoid), 0x12, 9, 4, 0);
                maxhp = &zoid->maxhp;
                func_0807BA24(*maxhp, 4, 0, 0x12, 9, 9, 0);
                func_0807C290(D_08001FA3);
                idx = D_0200C4A0;
                if (D_0200C4A2 == 1)
                {
                    if (zoid->flags & 2)
                    {
                        func_08075F20(0x114);
                        func_0808A890(0);
                        func_0808A890(1);
                        func_0807C290(D_080020D2);
                        func_0808A8B4(0);
                        func_0808A8B4(1);
                    }
                    else if (zoid->hp < *maxhp)
                    {
                        D_0200C4D0 = D_02030F7E[sel][0];
                        D_0200C4BC = zoid->species;
                        func_0807C290(D_08001FAC);
                        if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
                        {
                            func_08075F20(0xE6);
                            func_0808A86C(0);
                            func_0808A86C(1);
                            D_0200C4BC = zoid->species;
                            if ((full = item->flags & 4) != 0)
                            {
                                zoid->hp = *maxhp;
                                func_0807BA24(zoid->hp, 4, func_0808A8DC(zoid), 0x12, 9, 4, 0);
                                func_0807C290(D_08002051);
                            }
                            else if ((half = item->flags & 2) != 0)
                            {
                                D_0200C4AC = *maxhp / 2;
                                func_080BE06C(zoid, *maxhp / 2);
                                func_0807BA24(zoid->hp, 4, func_0808A8DC(zoid), 0x12, 9, 4, full);
                                func_0807C290(D_0800202F);
                            }
                            else
                            {
                                D_0200C4AC = item->value;
                                func_080BE06C(zoid, item->value);
                                func_0807BA24(zoid->hp, 4, func_0808A8DC(zoid), 0x12, 9, 4, half);
                                func_0807C290(D_0800202F);
                            }
                            func_0807F15C(D_02030F7E[sel][0], 1);
                            state = 0;
                            break;
                        }
                    }
                    else
                    {
                        func_08075F20(0x114);
                        func_0808A890(0);
                        func_0808A890(1);
                        func_0807C290(D_08002073);
                        func_0808A8B4(0);
                        func_0808A8B4(1);
                    }
                }
                else if (D_0200C4A2 == 2)
                {
                    func_0808A86C(0);
                    func_0808A86C(1);
                    state = 0x10;
                    break;
                }
                else if ((D_0200C4A4 & 8) && func_0808B2F8(8, 0, 2))
                {
                    idx = 0;
                }
            }
            func_0807C290(D_08001FA7);
            break;
        case 0x2000:
            func_08079544(0x10, 0);
            func_0807970C();
            r = func_08092B60(1);
            if (r != -1)
            {
                D_02020E4C.field_26 = D_020209D8.field_0;
                D_02020E4C.field_2A = D_02020E4C.field_20;
                D_02020E4C.field_2C = D_020209D8.warp->x;
                D_02020E4C.field_30 = D_020209D8.warp->y;
                if (D_020209D8.area == 0 || func_08082F4C(0xFF))
                {
                    D_02020E4C.field_28 = D_02020E4C.field_24;
                    D_02020E4C.field_34 = D_02020E4C.field_10;
                    D_02020E4C.field_38 = D_02020E4C.field_14;
                }
                func_08088D98(D_08785FDC[D_020209D8.area][r][0], D_08785FDC[D_020209D8.area][r][1] << 11, D_08785FDC[D_020209D8.area][r][2] << 11, 0);
                if (D_02020E4C.field_23 != 0 && (D_020209D8.area == 0 || func_08082F4C(0xFF)))
                {
                    D_02020E4C.field_24 = D_020209D8.area;
                    D_02020E4C.field_10 = D_08785FDC[D_020209D8.area][r][3] << 11;
                    D_02020E4C.field_14 = D_08785FDC[D_020209D8.area][r][4] << 11;
                }
                func_0807F15C(D_02030F7E[sel][0], 1);
                return 1;
            }
            func_08091DB4();
            func_0807C290(D_08001EE2);
            D_02009480.field_1824 = D_02009480.field_1825 = sel1;
            D_02009480.field_1826 = sel;
            func_0808B028(5);
            func_0807C290(D_08001FE5);
            func_0807B77C(D_087A5574[D_02030F7E[sel][0]], 0, 6);
            func_0807A1A4();
            func_08079544(0xF, 0);
            func_0807970C();
            state = 0x10;
            break;
        case 0x3000:
            func_0807C290(D_080022E9);
            if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
            {
                func_08088D98(D_02020E4C.field_26, D_02020E4C.field_2C, D_02020E4C.field_30, 0);
                D_02020E4C.field_20 = D_02020E4C.field_2A;
                if (D_020209D8.area == 0 || func_08082F4C(0xFF))
                {
                    D_02020E4C.field_24 = D_02020E4C.field_28;
                    D_02020E4C.field_10 = D_02020E4C.field_34;
                    D_02020E4C.field_14 = D_02020E4C.field_38;
                }
                func_0807F15C(D_02030F7E[sel][0], 1);
                func_08075F20(0xCE);
                func_08075FC0(0x20);
                func_08079544(6, 0);
                while (!func_080796EC() || !func_08075F5C(0xCE))
                    func_080C8FCC(1);
                return 1;
            }
            state = 0x10;
            break;
        }
    next:;
    } while (done == 0);
    return 0;
}
