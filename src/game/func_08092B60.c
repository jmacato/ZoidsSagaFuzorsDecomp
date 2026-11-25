#include "types.h"

struct Obj
{
    u8 pad_0[0xC];
    u16 field_C;
    u16 field_E;
};

struct Save
{
    u8 pad_0[0x10];
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1C;
    u8 field_20;
    u8 pad_21[2];
    u8 field_23;
    u16 field_24;
};

struct Map
{
    u8 pad_0[0x1A];
    u16 area;
};

struct Camera
{
    s32 x;
    s32 y;
};

extern struct Save D_02020E4C;
extern struct Map D_020209D8;
extern struct Camera D_03000060;
struct State
{
    u8 pad_0[0x94];
    struct Obj *objs[8];
};

extern struct State D_0201F5F8;
extern u32 D_0202896C[];
extern u16 D_0300004C;
extern u16 D_0300004E;
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern u8 D_0200C4E0[2];
extern char D_0203198C[];
extern char D_020319CC[];
extern const u16 D_087355E0[][5][3];
extern const s16 D_08785D66[][26][3];
extern const u16 D_08785FDC[][26][5];
extern const u8 *D_087A5CA4[][26];
extern const u8 D_080F0F84[];
extern const u8 D_080F273C[];
extern const u8 D_080F27D4[];
extern const u8 D_08003C7A[];
extern const u8 D_08003C97[];
extern const u8 D_08003CB9[];
extern const u8 D_08003CE9[];
extern const u8 D_08003CAA[];
extern const u8 D_08003C8F[];
extern const u8 D_08003C93[];
extern const u8 D_08003D0F[];
extern const char D_0801EC86[];
void func_08079EF4(u8, u8, u16, u16, u16, u8, u8, u8, u16, u8);
void func_080C8B84(const void *, void *);
void func_0808007C(s32, s32, s32, s32, s32);
void func_08076FA0(void);
void func_08092524(u8, u8);
struct Obj *func_080771BC(const u8 *, const u8 *, u32, s16, s16, u32, u32, u32, u32);
void func_0807C290(const u8 *);
void func_0807BEF4(u8, const void *, u8);
u8 func_08082F4C(u8);
char *func_080C8F78(char *, const char *);
void func_0807B830(u16, u8, u8, char *);
char *func_0807DB94(char *, const char *);
void func_08075DA8(u8, void (*)(void));
void func_08092698(void);
void func_0807A1A4(void);
void func_08079544(u8, u8);
void func_080928D8(s32, s32, u8);
void func_0807970C(void);
u8 func_080796EC(void);
s32 func_08075F5C(u16);
void func_08075F20(u32);
void func_08075FC0(u16);
void func_080C8FCC(u32);
void func_08075E28(u8);

s32 func_08092B60(u8 mode)
{
    u8 list[32];
    u8 i;
    u8 n;
    u8 sel;
    u8 shown;
    u8 result;
    s32 x;
    s32 y;
    const s16 (*row)[3];
    const s16 *elem;

    D_0300004C = 0x1D40;
    D_0300004E = 6;
    func_08079EF4(2, 3, 0, 0x1C0, 0x1C0, 1, 0xE, 0, 0x3E6, 0xF);
    func_080C8B84(D_080F0F84, (void *)0x060157A0);
    func_0808007C(3, 0, 0x1EF, 4, 4);
    func_08076FA0();
    func_08092524(1, 0);
    D_03000060.y = 0;
    D_03000060.x = 0;
    func_080771BC(D_080F273C, D_080F27D4, 0, D_02020E4C.field_18 / 0x1000 - 8, D_02020E4C.field_1C / 0x1000 - 4, 0x358, 0xF, 0x11A0, 0);
    for (i = 0; i < 8; i++)
    {
        D_0201F5F8.objs[i] = func_080771BC(D_080F273C, D_080F27D4, 1, 0, 0, 0x358, 0xF, 0x10A0, 0);
        D_0201F5F8.objs[i]->field_C = 0xFFF8;
        D_0201F5F8.objs[i]->field_E = 0xFFFC;
    }
    n = 0;
    func_0807C290(D_08003C7A);
    if (mode == 0)
    {
        func_0807BEF4(0, D_08003C97, 2);
        list[0] = 0x7E;
        n = 1;
        func_0807C290(D_08003CB9);
    }
    else
    {
        func_0807C290(D_08003CE9);
    }
    if (D_02020E4C.field_23 != 0 && D_02020E4C.field_20 != 0x8A && D_02020E4C.field_24 == D_020209D8.area)
    {
        func_080771BC(D_080F273C, D_080F27D4, 2, D_02020E4C.field_10 / 0x1000 - 8, D_02020E4C.field_14 / 0x1000 - 4, 0x358, 0xF, 0x13A0, 0);
        if (mode == 0)
        {
            func_0807BEF4(0, D_08003CAA, 1);
            list[n] = 0x7F;
            n++;
        }
    }
    for (i = 1; i < 0x18; i++)
    {
        if (D_0202896C[(i >> 5) + D_020209D8.area] & (1 << (i & 31)))
        {
            if (mode == 0)
            {
                if (D_020209D8.area == 1 && (i == 7 || i == 0x12))
                    continue;
                if (D_020209D8.area == 2 && i == 0x13)
                    continue;
                if (D_020209D8.area == 3 && i == 2)
                    continue;
                func_0807BEF4(0, D_087A5CA4[D_020209D8.area][i], 0);
                list[n] = i;
                n++;
            }
            else if (D_08785FDC[D_020209D8.area][i - 1][0] != 0)
            {
                func_0807BEF4(0, D_087A5CA4[D_020209D8.area][i], 0);
                list[n] = i;
                n++;
            }
        }
    }
    if (mode == 0 && func_08082F4C(0xFF))
    {
        for (i = 0; i < 5 && D_087355E0[D_020209D8.area][i][0] != 0; i++)
        {
            if (D_087355E0[D_020209D8.area][i][0] != 8 || func_08082F4C(0x8B))
            {
                func_080C8F78(D_0203198C, D_0801EC86);
                func_0807B830(D_087355E0[D_020209D8.area][i][0], 1, 0, D_020319CC);
                func_0807DB94(D_0203198C, D_020319CC);
                func_0807BEF4(0, D_0203198C, 1);
                list[n] = i | 0x80;
                n++;
            }
        }
    }
    func_08075DA8(3, func_08092698);
    func_0807A1A4();
    func_08079544(0xF, 0x10);
    result = 0;
    shown = 0;
    sel = 0;
    do
    {
        if (!(list[sel] & 0x80))
        {
            switch (list[sel])
            {
            default:
                row = D_08785D66[D_020209D8.area];
                elem = row[list[sel]];
                x = (elem[1] + 2) << 11;
                y = (elem[2] + 2) << 11;
                func_080928D8(x, y, shown == 0);
                break;
            case 0x7E:
                x = D_02020E4C.field_18;
                y = D_02020E4C.field_1C;
                func_080928D8(x, y, shown == 0);
                break;
            case 0x7F:
                x = D_02020E4C.field_10;
                y = D_02020E4C.field_14;
                func_080928D8(x, y, shown == 0);
                break;
            }
        }
        else
        {
            x = D_087355E0[D_020209D8.area][list[sel] & 0x7F][1] << 11;
            y = D_087355E0[D_020209D8.area][list[sel] & 0x7F][2] << 11;
            func_080928D8(x, y, shown == 0);
        }
        shown = 1;
        func_0807970C();
        if (mode == 0)
            func_0807C290(D_08003C8F);
        else
            func_0807C290(D_08003C93);
        sel = D_0200C4A0;
        if (D_0200C4A2 != 0)
        {
            if (D_0200C4A2 == 1)
            {
                D_0200C4E0[0] = D_020209D8.area;
                D_0200C4E0[1] = list[sel];
                func_0807C290(D_08003D0F);
                if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
                    result = 2;
            }
            else
            {
                result = 1;
            }
        }
    } while (result == 0);
    if (mode == 0 || result == 1)
    {
        func_08079544(0x10, 0x10);
    }
    else
    {
        func_08075F20(0xCE);
        func_08075FC0(0x20);
        func_08079544(6, 0x10);
    }
    while (!func_080796EC() || !func_08075F5C(0xCE))
        func_080C8FCC(1);
    func_08075E28(3);
    if (result == 1)
        return -1;
    return list[sel] - 1;
}
