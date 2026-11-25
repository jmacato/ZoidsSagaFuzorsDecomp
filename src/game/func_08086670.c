#include "types.h"

struct Zoid
{
    u8 species;
    u8 level;
    u8 pilot;
    u8 pad_3;
    u16 flags;
    u8 pad_6[0x8E];
};

struct Pilot
{
    u8 id;
    u8 pad_1[2];
    u8 flags;
    u8 pad_4[0x2A];
    u8 zoid;
    u8 pad_2F[0x11];
};

struct Save
{
    u8 pad_0[0x3C];
    struct Zoid zoids[186];
    struct Pilot pilots[58];
    u8 pad_7A44[0x7A6A - 0x7A44];
    u8 team[6];
};

struct Script
{
    u8 field_0;
    u8 pad_1[0x2C9];
    u8 field_2CA;
    u8 pad_2CB[0x10F5 - 0x2CB];
    u8 field_10F5;
};

extern struct Script D_0201F6DC;
extern struct Save D_02020E4C;
extern u8 D_0200C4C0;
extern u8 D_0200C4BC;
extern u16 D_0200C4C8;
extern u8 D_0200C4D0;
extern u8 D_0200C4D4;
extern u8 D_0200C4D8;
extern u32 D_0200C4AC;
extern const u8 D_08014C9F[];
extern const u8 D_08014CDF[];
extern const u8 D_08014CC5[];
extern const u8 D_08014C7F[];
extern const u8 D_08014D05[];
extern const u8 D_08014DDF[];
extern const u8 D_08014D25[];
extern const u8 D_08014E07[];
extern const u8 D_08014D49[];
extern const u8 D_08014E33[];
extern const u8 D_08014D71[];
extern const u8 D_08014E63[];
extern const u8 D_08014D9B[];
extern const u8 D_08014E95[];
extern const u8 D_08014DC3[];
s32 func_08075F5C(u16);
void func_080C8FCC(u32);
void func_08083490(void);
void func_080834C8(void);
u32 func_0807EC90(u8, u8);
u32 func_0807ECD8(u8, u8, u8, u8);
u32 func_0807ED58(u8, u8, u8, u8);
u32 func_0807EE90(u8, u8);
void func_0807EE04(u8);
u8 func_0807EF5C(u8);
void func_08086624(struct Zoid *);
void func_08075EE0(u16);
void func_0807C290(const u8 *);
void func_080BDE24(u8, u8);
u32 func_0807F0C4(u8, u8);
u32 func_0807F128(u8, u8);
u32 func_0807F18C(u8);
u32 func_0807F1D0(u8, u8);
u32 func_0807F234(u8);
void func_0807F2D4(u32);
void func_08075F00(void);
void func_08083C5C(u8, s32, s32);

s32 func_08086670(u8 id, u8 **pc)
{
    u32 i;
    u8 z;
    u8 r;
    u8 p;
    u32 v;

    D_0201F6DC.field_0 = 1;
    if (!func_08075F5C(0xD0))
    {
        for (i = 0; i < 30; i++)
            func_080C8FCC(1);
    }
    func_08083490();
    func_080834C8();
    switch ((*pc)[0])
    {
    case 0x61:
        if (!func_0807EC90((*pc)[1], (*pc)[2]))
            break;
        func_08075EE0(0x67);
        D_0200C4BC = (*pc)[1];
        func_0807C290(D_08014C7F);
        break;
    case 0x62:
        for (i = 1; i <= 0xB9; i++)
        {
            if (D_02020E4C.zoids[i].species == (*pc)[1] && D_02020E4C.zoids[i].pilot == 0xFF)
                goto found62;
        }
        break;
    case 0x63:
        z = func_0807EC90((*pc)[1], (*pc)[2]);
        if (!z)
            break;
        D_02020E4C.zoids[z].flags |= 8;
        func_08075EE0(0x67);
        D_0200C4BC = (*pc)[1];
        func_0807C290(D_08014C7F);
        break;
    case 0x64:
        z = func_0807ECD8((*pc)[1], (*pc)[2], (*pc)[3], (*pc)[4]);
        if (!z)
            break;
        D_02020E4C.zoids[z].flags |= 0x20;
        if ((*pc)[3] != 0xFF)
        {
            D_02020E4C.pilots[D_02020E4C.zoids[z].pilot].flags |= 4;
            func_08075EE0(0x65);
            D_0200C4C0 = (*pc)[3];
            func_0807C290(D_08014C9F);
        }
        func_08075EE0(0x67);
        D_0200C4BC = (*pc)[1];
        func_0807C290(D_08014C7F);
        break;
    case 0x65:
        z = func_0807ECD8((*pc)[1], (*pc)[2], (*pc)[3], (*pc)[4]);
        if (!z)
            break;
        D_02020E4C.zoids[z].flags |= 0x28;
        if ((*pc)[3] != 0xFF)
        {
            D_02020E4C.pilots[D_02020E4C.zoids[z].pilot].flags |= 4;
            func_08075EE0(0x65);
            D_0200C4C0 = (*pc)[3];
            func_0807C290(D_08014C9F);
        }
        func_08075EE0(0x67);
        D_0200C4BC = (*pc)[1];
        func_0807C290(D_08014C7F);
        break;
    case 0x66:
        p = func_0807EE90((*pc)[1], (*pc)[2]);
        if (!p)
            break;
        D_02020E4C.pilots[p].flags |= 4;
        func_08075EE0(0x65);
        D_0200C4C0 = (*pc)[1];
        func_0807C290(D_08014C9F);
        break;
    case 0x67:
        for (i = 1; i <= 0x34; i++)
        {
            if (D_02020E4C.pilots[i].id == (*pc)[1])
            {
                r = func_0807EF5C(i);
                D_0200C4C0 = (*pc)[1];
                func_0807C290(D_08014CDF);
                if (r)
                {
                    D_0200C4BC = r;
                    func_0807C290(D_08014CC5);
                    func_08086624(&D_02020E4C.zoids[D_02020E4C.pilots[i].zoid]);
                }
                break;
            }
        }
        break;
    case 0x68:
        z = func_0807ED58((*pc)[1], (*pc)[2], (*pc)[3], (*pc)[4]);
        if (!z)
            break;
        D_02020E4C.zoids[z].flags |= 0x20;
        if ((*pc)[3] != 0xFF)
        {
            D_02020E4C.pilots[D_02020E4C.zoids[z].pilot].flags |= 4;
            D_0200C4C0 = (*pc)[3];
            func_08075EE0(0x65);
            func_0807C290(D_08014C9F);
        }
        func_08075EE0(0x67);
        D_0200C4BC = (*pc)[1];
        func_0807C290(D_08014C7F);
        break;
    case 0x69:
        z = func_0807ED58((*pc)[1], (*pc)[2], (*pc)[3], (*pc)[4]);
        if (!z)
            break;
        D_02020E4C.zoids[z].flags |= 0x20;
        for (i = 0; i < 6; i++)
        {
            if (D_02020E4C.team[i] == 0)
            {
                func_080BDE24(z, i);
                break;
            }
        }
        if ((*pc)[3] != 0xFF)
        {
        D_02020E4C.pilots[D_02020E4C.zoids[z].pilot].flags |= 4;
        func_08075EE0(0x65);
        D_0200C4C0 = (*pc)[3];
        func_0807C290(D_08014C9F);
        }
        func_08075EE0(0x67);
        D_0200C4BC = (*pc)[1];
        func_0807C290(D_08014C7F);
        break;
    case 0x6A:
        func_08075EE0(0x67);
        D_0200C4C8 = (*pc)[1];
        func_0807C290(D_08014D05);
        if (!func_0807F0C4((*pc)[1], 1))
            func_0807C290(D_08014DDF);
        break;
    case 0x6B:
        func_08075EE0(0x67);
        D_0200C4D0 = (*pc)[1];
        func_0807C290(D_08014D25);
        if (!func_0807F128((*pc)[1], 1))
            func_0807C290(D_08014E07);
        break;
    case 0x6C:
        func_08075EE0(0x67);
        D_0200C4BC = (*pc)[1];
        func_0807C290(D_08014D49);
        if (!func_0807F18C((*pc)[1]))
            func_0807C290(D_08014E33);
        break;
    case 0x6D:
        func_08075EE0(0x67);
        D_0200C4D4 = (*pc)[1];
        func_0807C290(D_08014D71);
        if (!func_0807F1D0((*pc)[1], 1))
            func_0807C290(D_08014E63);
        break;
    case 0x6E:
        func_08075EE0(0x67);
        D_0200C4D8 = (*pc)[1];
        func_0807C290(D_08014D9B);
        if (!func_0807F234((*pc)[1]))
            func_0807C290(D_08014E95);
        break;
    found62:
        func_0807EE04(i);
        D_0200C4BC = (*pc)[1];
        func_0807C290(D_08014CC5);
        func_08086624(&D_02020E4C.zoids[i]);
        break;
    case 0x6F:
        v = (*pc)[1] | ((*pc)[2] << 8) | ((*pc)[3] << 16) | ((*pc)[4] << 24);
        func_0807F2D4(v);
        func_08075EE0(0x67);
        D_0200C4AC = v;
        func_0807C290(D_08014DC3);
        break;
    }
    D_0201F6DC.field_10F5 = 0;
    D_0201F6DC.field_2CA = 1;
    func_08075F00();
    func_08083C5C(id, -1, 0);
    return 0;
}
