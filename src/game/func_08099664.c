#include "types.h"

struct Zoid
{
    u8 type;
    u8 level;
    u8 pad_2[0x64];
    s16 field_66;
    u8 pad_68[0x2C];
};

struct Unit
{
    u8 id;
    u8 pad_1[0x107];
};

struct Cell
{
    u8 id;
    u8 pad_1[0x3F];
};

struct Entry
{
    u8 side;
    u8 slot;
    u8 field_2;
    u8 pad_3[5];
};

struct Team
{
    u8 field_0;
    u8 leader;
    u8 field_2;
    u8 field_3;
};

struct Game
{
    u8 turn;
    u8 field_1;
    u8 count;
    u8 index;
    struct Entry list[0x48];
    u8 side;
    u8 slot;
    u8 field_246;
    u8 pad_247;
    struct Unit *unit;
    struct Zoid *zoid;
    struct Cell *cell;
    u8 field_254;
    u8 pad_255[3];
    struct Unit units[2][7];
    struct Zoid zoids[2][11];
    struct Cell cells[2][7];
    u8 pad_2100[0x2D6F];
    u8 field_4E6F;
    u8 field_4E70;
    u8 pad_4E71[0x2D];
    s16 field_4E9E;
    u8 field_4EA0;
    u8 pad_4EA1[0xDA];
    u8 flags;
    u32 field_4F7C;
    u32 field_4F80;
    struct Team teams[2];
    u8 buf[2][36];
    u8 buf2[36];
};

struct Cfg
{
    u8 mode;
    u8 field_1;
    u8 stage;
    u8 wave;
    u8 pad_4[9];
    u8 field_D;
    u8 field_E;
};

struct Demo
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
};

struct Camera
{
    u8 pad_0[0x14];
    s32 field_14;
    s32 field_18;
    s32 field_1C;
    u8 pad_20[0x40];
    s32 field_60;
};

struct Win
{
    u32 flags;
    u8 pad_4[0x4CC];
};

struct Stage
{
    u8 id;
    u8 pad_1[0x123];
};

extern struct Game D_02031A0C;
extern struct Cfg D_02020E3C;
extern struct Demo D_02030AE8;
extern struct Camera D_030025A8;
extern struct Win D_02009480[];
extern u16 D_02030584;
extern u8 D_0200C4A2;
extern u8 D_0200C4A0;
extern const struct Stage D_0875A0C4[][15];
extern u32 (*D_03000010)(void);
extern const u8 D_080041AD[];
extern const u8 D_08004219[];
extern const u8 D_08003E6E[];
extern const u8 D_0800411B[];
extern const u8 D_08003F05[];
extern const u8 D_080040D6[];
extern const u8 D_080F4308[];
extern const u8 D_080F4318[];
extern const u8 D_080F4320[];
extern const u8 D_080F4324[];
extern const u8 D_080F4328[];
extern const u8 D_080F4334[];
extern const u8 D_080F4340[];

void func_0809961C(void);
void func_08079544(u8, u8);
void func_08075DA8(u8, void (*)(void));
void func_080BEB10(void);
void func_080BE628(void);
void func_08075E80(u8);
void func_080BE840(u8, u8);
void func_0807F810(void);
void func_0807F838(void);
void func_080A0244(u8);
void func_0809AA44(u8);
void func_0809F9DC(u8);
void func_0809FCD4(u32, u8, u8, u32);
void func_0809309C(void);
void func_080930C0(void);
void func_0809AA64(void);
void func_0809AD80(void);
void func_0809F7AC(u8);
void func_080932A4(void);
void func_0809AB0C(void);
s32 func_08093400(void);
void func_0807970C(void);
void func_080A0358(void);
void func_08091DB4(void);
void func_0809104C(void);
void func_0809181C(u8);
void func_0807C290(const u8 *);
void func_08075F20(u16);
void func_0807BD4C(u8);
void func_0807A1A4(void);
void func_080933A0(void);
void func_0809F7F4(u8);
void func_080A0108(void);
void func_08093544(void);
void func_080BE558(void);
void func_080C5B44(void);
s32 func_08093C80(void);
void func_08093698(u8, u8);
u32 func_0809D984(u8);
s32 func_08093EC0(void);
void func_08080390(void *, u16, const u8 *);
void func_080804DC(void *, u16, const u8 *);
u32 func_080803C4(void);
u32 func_08080510(void);
void func_080C8FCC(u32);
void func_080C3BB0(void);
void func_080C4104(u8);
s32 func_0809E0CC(void);
void func_080BF4F4(void);
void func_080C201C(void);
u8 func_080BFFF4(void);
void func_0809C650(void);
void func_0809D79C(void);
void func_080BEB6C(u8, u8);
void func_080BDF60(struct Zoid *);
const u8 *func_080BF554(u8, u8, u8);
void func_0807B77C(const u8 *, u32, u32);
u8 func_0807C100(const u8 *);
const u8 *func_08082EAC(u8, u8);
s32 func_0809B240(void);
s32 func_08094058(u8, u8);
s32 func_080A00FC(void);
void func_08093228(u8);
void func_080A290C(u8, u8);
s32 func_08095A58(void);
void func_080A1204(void);
void func_0809325C(void);
s32 func_08096304(void);
s32 func_080965A8(void);
s32 func_080967F8(s32);
void func_080C1768(void);
void func_080C112C(void);
void func_080C1220(void);
void func_0809C9B4(void);
void func_0809CC2C(void);
void func_080994B4(void);
void func_08097004(void);
void func_0809D624(void);
void func_0809D5A4(void);
void func_080C2508(void);
void func_08098AC0(s32);
void func_0809F7CC(u8, u8);
void func_0809F764(u8);
void func_080B3A38(u8, u8);
void func_080B3B94(u8, u8, u8, s16);
void func_080B3C84(void);
void func_080BF4C4(u8, u8);
void func_0809F910(u8, u8);
void func_0809F784(u8, u8);
void func_0809D7BC(u8, u8, u8);
void func_08097344(void);
void func_0809743C(u8);
void func_08097FCC(void);
void func_080985A4(void);
void func_08098828(u8);
void func_0809B8B4(void);
void func_0809B9BC(void);
void func_08075E28(u8);
void func_08080370(void);
u32 func_0809EC70(u8);
void func_0809D93C(void);
void func_08075EC4(void);
void func_08075F00(void);
void func_08075F34(void);

u8 func_08099664(void)
{
    s32 state = 0;
    u8 result = 0;
    s32 r;
    u8 a, b;
    u8 i;
    u32 n;
    u8 other;
    u8 k;

    while (result == 0)
    {
        switch (state)
        {
        case 0:
            func_08079544(1, 16);
            func_08075DA8(5, func_0809961C);
            func_080BEB10();
            if (D_02020E3C.mode == 0)
            {
                func_080BE628();
                if (D_02030AE8.field_0 == 0)
                {
                    func_08075E80(D_0875A0C4[D_02020E3C.stage][D_02020E3C.wave].id);
                    func_080BE840(D_02020E3C.stage, D_02020E3C.wave);
                }
                D_02031A0C.flags = 0;
            }
            else
                D_02031A0C.flags = 2;
            if (D_02020E3C.mode != 1)
            {
                func_0807F810();
                func_0807F838();
            }
            D_02031A0C.turn = 1;
            if (D_02020E3C.field_D == 3)
                D_02020E3C.field_E = 4;
            D_02031A0C.field_4F7C = D_02031A0C.field_4F80 = 0;
            func_080A0244(D_02020E3C.field_1);
            func_0809AA44(0);
            func_0809AA44(1);
            func_0809F9DC(0);
            func_0809F9DC(1);
            D_030025A8.field_14 = 120;
            D_030025A8.field_18 = 120;
            D_030025A8.field_1C = 128;
            D_030025A8.field_60 = 0x20000;
            func_0809FCD4(1, 0, 0, 1);
            func_0809309C();
            func_080930C0();
            if (D_02030AE8.field_0 != 0 && D_02030AE8.field_2 != 0)
            {
                D_02031A0C.field_4E70 = 0;
                D_02031A0C.field_4E6F = 0;
                func_0809AA64();
                func_0809AD80();
                func_0809F7AC(0);
                func_0809F7AC(1);
                func_0809FCD4(5, D_02031A0C.list[0].side, D_02031A0C.list[0].slot, 1);
                state = 0x4000;
            }
            else
            {
                func_080932A4();
                D_02031A0C.field_4EA0 = 0;
                state = 0x1000;
            }
            break;
        case 0x1000:
            func_0809AB0C();
            state = 0x1010;
            break;
        case 0x1010:
            func_0809FCD4(3, 0, 0, 0);
            switch (func_08093400())
            {
            case 0:
                state = 0x1100;
                break;
            case 1:
                state = 0x1200;
                break;
            case 2:
                state = 0x1300;
                break;
            case 3:
                state = 0x1400;
                break;
            }
            break;
        case 0x1100:
            state = 0x2000;
            break;
        case 0x1200:
            func_08079544(2, 16);
            func_0807970C();
            func_080A0358();
            D_02031A0C.flags |= 1;
            func_08091DB4();
            func_08079544(15, 16);
            func_0809104C();
            func_08079544(16, 16);
            func_0807970C();
            func_080BE628();
            func_080A0244(D_02020E3C.field_1);
            func_0809AA44(0);
            func_0809AA44(1);
            func_0809F9DC(0);
            func_0809F9DC(1);
            func_0809309C();
            func_080930C0();
            D_02031A0C.flags &= ~1;
            func_08079544(1, 16);
            state = 0x1000;
            break;
        case 0x1300:
            func_0809181C(1);
            func_0807F810();
            state = 0x1010;
            break;
        case 0x1400:
            func_0807C290(D_080041AD);
            if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
            {
                if (D_02031A0C.field_4E9E > (s32)(D_03000010() * 100 >> 15))
                {
                    result = 4;
                    break;
                }
                func_08075F20(233);
                func_0807C290(D_08004219);
                D_02031A0C.field_4EA0 = 1;
            }
            state = 0x1010;
            break;
        case 0x2000:
            func_0807BD4C(0);
            func_0807A1A4();
            func_080933A0();
            func_0809F7F4(0);
            func_0809F7F4(1);
            func_0809FCD4(10, 0, 0, 0);
            func_080A0108();
            func_08093544();
            D_02031A0C.field_4E70 = 0;
            D_02031A0C.field_4E6F = 0;
            func_080BE558();
            func_0809AA64();
            func_0809F9DC(0);
            func_0809F9DC(1);
            func_0809F7AC(0);
            func_0809F7AC(1);
            func_080C5B44();
            state = 0x2010;
            break;
        case 0x2010:
            func_0809FCD4(3, 1, 0, 0);
            switch (r = func_08093C80())
            {
            case 0:
                state = 0x2100;
                break;
            case 1:
                state = 0x2200;
                break;
            case 2:
                state = 0x2300;
                break;
            case -1:
                func_0809FCD4(3, 0, 0, 0);
                func_0809F7F4(0);
                func_0809F7F4(1);
                state = 0x1010;
                break;
            case -2:
                func_08093698(1, 0);
                func_0809FCD4(3, 1, 0, 1);
                break;
            case -3:
                func_08093698(0, 2);
                func_0809FCD4(3, 1, 0, 1);
                break;
            }
            D_02031A0C.teams[0].field_0 = r;
            break;
        case 0x2100:
            func_0807C290(D_08003E6E);
            if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
                state = 0x2400;
            else
                state = 0x2010;
            break;
        case 0x2200:
            if (func_0809D984(18))
            {
                func_08075F20(0x114);
                func_0807C290(D_0800411B);
                state = 0x2010;
            }
            else if (func_08093EC0() == 0)
                state = 0x2400;
            else
                state = 0x2010;
            break;
        case 0x2300:
            func_0807C290(D_080041AD);
            if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
                state = 0x2400;
            else
                state = 0x2010;
            break;
        case 0x2400:
            if (D_02020E3C.mode != 2)
                D_02031A0C.teams[1].field_0 = 0;
            state = 0x3000;
            break;
        case 0x3000:
            if (D_02020E3C.mode == 2)
            {
                func_0807BD4C(0);
                func_0807A1A4();
                func_08080390(&D_02031A0C.teams[0], 4, D_080F4308);
                func_080804DC(&D_02031A0C.teams[1], 4, D_080F4308);
                do
                {
                    a = func_080803C4();
                    b = func_08080510();
                    func_080C8FCC(1);
                } while (a == 0 || b == 0);
                func_08080390(D_02031A0C.buf[0], 36, D_080F4318);
                func_080804DC(D_02031A0C.buf[1], 36, D_080F4318);
                do
                {
                    a = func_080803C4();
                    b = func_08080510();
                    func_080C8FCC(1);
                } while (a == 0 || b == 0);
            }
            state = 0x3010;
            break;
        case 0x3010:
            func_080C3BB0();
            i = 0;
            if (D_02031A0C.field_1 == 0)
                i = 1;
            if (D_02031A0C.teams[i].field_0 != 1 || D_02031A0C.teams[i].leader != 0x42)
                D_02031A0C.side = D_02031A0C.field_1;
            else
                D_02031A0C.side = i;
            state = 0x3020;
            break;
        case 0x3020:
            switch (D_02031A0C.teams[D_02031A0C.side].field_0)
            {
            case 1:
                state = 0x3100;
                break;
            case 2:
                state = 0x3200;
                break;
            case 0:
                state = 0x3300;
                break;
            }
            break;
        case 0x3100:
            func_080C4104(D_02031A0C.side);
            state = 0x3300;
            break;
        case 0x3200:
            if (D_02031A0C.field_4E9E > (s32)(D_03000010() * 100 >> 15))
            {
                result = 4;
                break;
            }
            func_08075F20(233);
            func_0807C290(D_08004219);
            D_02031A0C.field_4EA0 = 1;
            state = 0x3300;
            break;
        case 0x3300:
            result = func_0809E0CC();
            if (result != 0)
                break;
            if (D_02031A0C.side != D_02031A0C.field_1
                || (D_02031A0C.teams[D_02031A0C.side].field_0 == 1 && D_02031A0C.teams[D_02031A0C.side].leader == 0x42))
                state = 0x3F00;
            else
                state = 0x3020;
            D_02031A0C.side = D_02031A0C.side == 0;
            break;
        case 0x3F00:
            func_080BF4F4();
            func_0809AD80();
            func_0809F9DC(0);
            func_0809F9DC(1);
            state = 0x4000;
            break;
        case 0x4000:
            func_080C201C();
            if (D_02031A0C.index >= D_02031A0C.count)
            {
                state = 0x7000;
                break;
            }
            D_02031A0C.side = D_02031A0C.list[D_02031A0C.index].side;
            D_02031A0C.slot = D_02031A0C.list[D_02031A0C.index].slot;
            D_02031A0C.field_246 = D_02031A0C.list[D_02031A0C.index].field_2;
            D_02031A0C.unit = &D_02031A0C.units[D_02031A0C.side][D_02031A0C.slot];
            D_02031A0C.zoid = &D_02031A0C.zoids[D_02031A0C.side][D_02031A0C.unit->id];
            D_02031A0C.cell = &D_02031A0C.cells[D_02031A0C.side][k = D_02031A0C.field_246];
            D_02031A0C.field_254 = func_080BFFF4();
            func_0809C650();
            func_0809D79C();
            func_080BEB6C(D_02031A0C.side, D_02031A0C.slot);
            func_080BDF60(D_02031A0C.zoid);
            func_080C5B44();
            state = 0x4010;
            break;
        case 0x4010:
            func_0807BD4C(0);
            func_0807B77C(func_080BF554(D_02031A0C.side, D_02031A0C.zoid->type, D_02031A0C.zoid->level), 0, 0);
            for (n = func_0807C100(func_080BF554(D_02031A0C.side, D_02031A0C.zoid->type, D_02031A0C.zoid->level)); n < 13; n++)
                func_0807B77C(D_080F4320, 0, 0);
            func_0807B77C(D_080F4324, 0, 0);
            func_0807B77C(func_08082EAC(D_02031A0C.cell->id, D_02031A0C.side), 0, 0);
            func_0807A1A4();
            func_0809FCD4(5, D_02031A0C.side, D_02031A0C.slot, 0);
            D_02031A0C.flags &= ~1;
            state = 0x4020;
            break;
        case 0x4020:
            if (func_0809B240() == 0)
            {
                switch (r = func_08094058(D_02031A0C.slot, k = D_02031A0C.field_246))
                {
                case 0:
                    D_02031A0C.flags |= 1;
                    state = 0x4100;
                    break;
                case 1:
                    state = 0x4200;
                    break;
                case 2:
                    D_02031A0C.flags |= 1;
                    state = 0x4300;
                    break;
                case 3:
                    D_02031A0C.flags |= 1;
                    state = 0x4400;
                    break;
                case 4:
                    D_02031A0C.flags |= 1;
                    state = 0x4500;
                    break;
                case 5:
                case 6:
                case 7:
                case 8:
                    D_02031A0C.flags |= 1;
                    state = 0x4600;
                    break;
                case -2:
                    func_08093698(1, 0);
                    func_0809FCD4(5, D_02031A0C.side, D_02031A0C.slot, 1);
                    break;
                case -3:
                    func_08093698(0, D_02031A0C.slot);
                    func_0809FCD4(5, D_02031A0C.side, D_02031A0C.slot, 1);
                    break;
                case -1:
                case -4:
                    break;
                }
                D_02031A0C.teams[0].field_0 = r;
            }
            else if (func_080A00FC() == 0)
                func_080C8FCC(1);
            else
                state = 0x4700;
            break;
        case 0x4100:
            func_08079544(2, 16);
            func_0807970C();
            func_08093228(2);
            func_080A290C(D_02031A0C.side, D_02031A0C.slot);
            func_08079544(9, 0);
            if (func_08095A58() != -1)
            {
                state = 0x4F00;
                break;
            }
            func_08079544(11, 0);
            func_0807970C();
            func_080A1204();
            func_0809325C();
            func_08079544(1, 16);
            state = 0x4010;
            break;
        case 0x4200:
            func_0807C290(D_08003F05);
            if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
            {
                func_0807BD4C(0);
                func_0807A1A4();
                state = 0x4F00;
            }
            else
                state = 0x4020;
            break;
        case 0x4300:
            if (func_0809D984(17))
            {
                func_08075F20(0x114);
                func_0807C290(D_0800411B);
                state = 0x4010;
                break;
            }
            r = func_08096304();
            if (r != -1)
            {
                func_0807BD4C(0);
                func_0807A1A4();
                state = 0x4F00;
            }
            else
                state = 0x4010;
            break;
        case 0x4400:
            if (func_0809D984(19))
            {
                func_08075F20(0x114);
                func_0807C290(D_0800411B);
                state = 0x4010;
                break;
            }
            func_0807C290(D_080040D6);
            if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
            {
                func_0807BD4C(0);
                func_0807A1A4();
                state = 0x4F00;
            }
            else
                state = 0x4010;
            break;
        case 0x4500:
            r = func_080965A8();
            if (r == -1)
            {
                state = 0x4010;
                break;
            }
            D_02031A0C.teams[0].leader = r;
            func_0807BD4C(0);
            func_0807A1A4();
            state = 0x4F00;
            break;
        case 0x4600:
            r = func_080967F8(r - 4);
            if (r == -1)
            {
                state = 0x4010;
                break;
            }
            D_02031A0C.teams[0].leader = r;
            func_0807BD4C(0);
            func_0807A1A4();
            state = 0x4F00;
            break;
        case 0x4700:
            if (D_02020E3C.mode != 2 || D_02031A0C.side == 0)
            {
                if (D_02031A0C.side == 0)
                    func_080C1768();
                else if (D_02020E3C.field_D != 5)
                    func_080C112C();
                else
                    func_080C1220();
            }
            state = 0x4F00;
            break;
        case 0x4F00:
            func_0809C9B4();
            if (D_02020E3C.mode == 2)
            {
                if (D_02031A0C.side == 0)
                {
                    func_08080390(&D_02031A0C.teams[0], 4, D_080F4328);
                    do
                    {
                        a = func_080803C4();
                        func_080C8FCC(1);
                    } while (a == 0);
                    func_08080390(D_02031A0C.buf2, 36, D_080F4334);
                    do
                    {
                        a = func_080803C4();
                        func_080C8FCC(1);
                    } while (a == 0);
                }
                else
                {
                    func_080804DC(&D_02031A0C.teams[1], 4, D_080F4328);
                    do
                    {
                        b = func_08080510();
                        func_080C8FCC(1);
                    } while (b == 0);
                    func_080804DC(D_02031A0C.buf2, 36, D_080F4334);
                    do
                    {
                        b = func_08080510();
                        func_080C8FCC(1);
                    } while (b == 0);
                    func_0809CC2C();
                }
            }
            D_02031A0C.flags &= ~1;
            state = 0x5000;
            break;
        case 0x5000:
            if (D_02031A0C.teams[D_02031A0C.side].field_0 == 0)
            {
                state = 0x5100;
                break;
            }
            func_080994B4();
            switch (D_02031A0C.teams[D_02031A0C.side].field_0)
            {
            case 1:
                state = 0x5200;
                break;
            case 2:
                state = 0x5300;
                break;
            case 3:
                state = 0x5400;
                break;
            case 4:
                state = 0x5500;
                break;
            case 5:
                state = 0x5600;
                break;
            case 6:
                state = 0x5700;
                break;
            case 7:
                state = 0x5800;
                break;
            case 8:
                state = 0x5900;
                break;
            }
            break;
        case 0x5100:
            if (!(D_02030584 & 2))
            {
                if (func_0809B240() != 0)
                {
                    func_08079544(2, 16);
                    func_0807970C();
                    func_08093228(2);
                    func_080A290C(D_02031A0C.side, D_02031A0C.slot);
                    if (D_02031A0C.side == 0)
                        func_08079544(9, 0);
                    else
                        func_08079544(10, 0);
                    func_0807970C();
                }
                else
                    D_02009480[1].flags |= 0x10;
                func_08097004();
                func_0809325C();
                func_08079544(1, 16);
            }
            else
            {
                if (func_0809B240() == 0)
                {
                    if (D_02031A0C.side == 0)
                        func_08079544(11, 0);
                    else
                        func_08079544(12, 0);
                    func_0807970C();
                    func_080A1204();
                    func_0809325C();
                    func_08079544(1, 16);
                }
                else
                    func_080994B4();
                func_0809D624();
            }
            func_0809D5A4();
            func_080C2508();
            func_0809F9DC(D_02031A0C.side);
            func_0807970C();
            func_08098AC0(0);
            state = 0x6000;
            break;
        case 0x5200:
            func_080A0108();
            func_0809F7CC(D_02031A0C.side, D_02031A0C.slot);
            func_0809F764(D_02031A0C.side == 0);
            func_080B3A38(D_02031A0C.side, 2);
            func_080B3B94(3, D_02031A0C.side, D_02031A0C.slot, 0);
            func_080B3C84();
            func_080B3B94(8, D_02031A0C.side, D_02031A0C.slot, D_02031A0C.zoid->field_66);
            func_080B3C84();
            func_080BF4C4(D_02031A0C.side, D_02031A0C.slot);
            func_0809F910(D_02031A0C.side, D_02031A0C.slot);
            func_0809F784(D_02031A0C.side, D_02031A0C.slot);
            other = 0;
            if (D_02031A0C.side == 0)
                other = 1;
            func_0809AA44(other);
            func_0809F9DC(other);
            func_0809F7AC(other);
            state = 0x6000;
            break;
        case 0x5300:
            func_0809D7BC(D_02031A0C.side, D_02031A0C.teams[D_02031A0C.side].field_2, D_02031A0C.teams[D_02031A0C.side].leader);
            state = 0x6000;
            break;
        case 0x5400:
            func_08097344();
            state = 0x6000;
            break;
        case 0x5500:
            func_0809743C(0);
            state = 0x6000;
            break;
        case 0x5600:
            func_08097FCC();
            state = 0x6000;
            break;
        case 0x5700:
            func_080985A4();
            state = 0x6000;
            break;
        case 0x5800:
            func_08098828(0);
            state = 0x6000;
            break;
        case 0x5900:
            func_08098828(1);
            state = 0x6000;
            break;
        case 0x6000:
            result = func_0809E0CC();
            if (result != 0)
                break;
            D_02031A0C.index++;
            state = 0x4000;
            break;
        case 0x7000:
            func_0809D79C();
            func_0809B8B4();
            func_0809B9BC();
            func_08098AC0(0);
            if (D_02031A0C.turn < 99)
            {
                if (D_02031A0C.turn == D_02020E3C.field_E)
                {
                    if (D_02020E3C.mode == 2)
                        result = 5;
                    else
                        result = 1;
                }
                D_02031A0C.turn++;
            }
            func_0809AB0C();
            D_02031A0C.field_4EA0 = 0;
            state = 0x2000;
            break;
        }
    }

    func_08075E28(5);
    func_080C5B44();
    if (D_02020E3C.mode == 2)
    {
        func_08080390(0, 0, D_080F4340);
        func_080804DC(0, 0, D_080F4340);
        do
        {
            a = func_080803C4();
            b = func_08080510();
            func_080C8FCC(1);
        } while (a == 0 || b == 0);
        func_08080370();
    }
    result = func_0809EC70(result);
    if (result == 1 || result == 4 || result == 3)
        func_08079544(2, 16);
    else
        func_08079544(2, 60);
    func_0807970C();
    func_080A0358();
    func_0809D93C();
    func_08075EC4();
    func_08075F00();
    func_08075F34();
    return result;
}
