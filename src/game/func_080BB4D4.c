#include "types.h"

struct Cfg
{
    u32 field_0;
    u32 field_4;
    u8 field_8;
    u8 field_9;
    u8 field_A;
};

struct Pair
{
    u16 a;
    u16 b;
};

struct Rules
{
    u8 field_0;
    u8 field_1;
    u8 pad2[2];
    u32 field_4;
    u32 field_8;
    u8 field_C;
    u8 field_D;
    u8 field_E;
};

struct Sprite
{
    u32 flags;
    s32 x;
};

struct Menu
{
    struct Sprite *sprites[6];
    struct Sprite *icons[6];
    struct Sprite *field_30;
    struct Sprite *cursor;
};

struct Link
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 field_5;
    u8 pad6[0xA];
    void *field_10;
    void *field_14;
    u8 pad18[0x6D];
    u8 field_85;
    u8 pad86[6];
    struct Sprite *field_8C;
    struct Sprite *field_90;
};

struct Save
{
    u8 pad0[0x16];
    u8 field_16;
    u8 pad17[0x1356 - 0x17];
    u8 field_1356;
};

struct Sync
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
};

struct Item
{
    u8 field_0;
    u8 pad1[0x93];
};

struct Unit
{
    u8 id;
    u8 list[4];
    u8 pad[0x103];
};

struct Group
{
    struct Unit units[7];
};

struct Cell
{
    u8 data[0x40];
};

struct Data
{
    u8 pad0[0x258];
    struct Group groups[2];
    struct Item items[2][11];
    struct Cell cells[2][7];
    u8 pad2100[0x5410 - 0x2100];
    u32 field_5410;
    u32 field_5414;
};

struct Obj
{
    u8 pad0[6];
    u16 field_6;
    u8 pad8[0x5A];
    u16 field_62;
};

struct Zoid
{
    u8 data[0x94];
};

struct Pilot
{
    u8 data[0x40];
};

struct Team
{
    u8 pad0[0x7A6A];
    u8 team[6];
};

extern struct Rules D_02020E3C;
extern struct Link D_0201F5F8;
extern struct Save D_02009480;
extern struct Sync D_02030AE0;
extern struct Menu D_02020E04;
extern struct Data D_02031A0C;
extern struct Team D_02020E4C;
extern struct Zoid D_02020E88[];
extern struct Pilot D_02027A10[];
extern u8 D_02030B6C[];
extern u8 D_02030C26[];
extern u16 D_020309A4[2];
extern u8 D_02030586[];
extern u8 D_0203198C[];
extern u8 D_02036A28[];
extern u8 D_02036A04[];
extern u16 D_0201F5CC;
extern u16 D_0201F5CE;
extern u16 D_0300000E;
extern u16 D_0300004C;
extern u8 D_030057F4;
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern u32 (*D_03000010)(void);
extern const u8 *D_0873F91C[];
extern const u8 *D_0873F988[];
extern u8 D_0873F9C4[];
extern u8 D_080F5BB0[];
extern u8 D_080F5BBC[];
extern u8 D_080F5BC8[];
extern u8 D_080F5BD8[];
extern u8 D_080F5BE4[];
extern u8 D_080F5BF0[];
extern u8 D_080F5BFC[];
extern u8 D_080F5C08[];
extern u8 D_080F5C14[];
extern const u8 D_080C93C8[];
extern const u8 D_080C93F0[];
extern const u8 D_080C9470[];
extern const u8 D_080C9498[];
extern const u8 D_08000B8F[];
extern const u8 D_08000BAE[];
extern const u8 D_0800360C[];
extern const u8 D_08003762[];
extern const u8 D_08024435[];
extern const u8 D_080244DB[];
extern const u8 D_0802450D[];
extern const u8 D_080245EF[];
extern const u8 D_08024654[];
extern const u8 D_080246D4[];
extern const u8 D_080246D8[];
extern const u8 D_080246DC[];
extern const u8 D_0802473F[];
extern const u8 D_08024743[];
extern const u8 D_08024746[];
extern const u8 D_08024784[];
extern const u8 D_080247F9[];
extern const u8 D_08024837[];
extern const u8 D_08024865[];
extern const u8 D_08024868[];
extern const u8 D_080248D2[];
extern const u8 D_08024917[];
extern const u8 D_08024980[];
extern const u8 D_08024984[];
extern const u8 D_08024987[];
extern const u8 D_08024992[];
extern const u8 D_08024996[];
extern const u8 D_08024A32[];
extern const u8 D_08024A8B[];
extern const u8 D_08024AC2[];
extern const u8 D_08024B13[];
extern const u8 D_08024B98[];
extern const u8 D_08024B9C[];
extern const u8 D_08024BA5[];
extern const u8 D_08024BE5[];
extern const u8 D_08024C12[];
extern const u8 D_08024C56[];
extern const u8 D_08024C59[];

void func_08091DB4(void);
void func_0807C290(const u8 *);
const u8 *func_08082E70(u8);
void func_0807B77C(const u8 *, u32, u8);
void func_0807BA24(u32, u8, u8, u8, u8, u16, u16);
u32 func_0807F558(void);
void func_0807A1A4(void);
void func_08079544(u8, u8);
void func_0807970C(void);
void func_080801D0(void);
u8 func_08080308(void);
void func_080C8FCC(u32);
void func_08080390(void *, u16, u8 *);
void func_080804DC(void *, u16, u8 *);
u8 func_080803C4(void);
u8 func_08080510(void);
void func_08075F20(u32);
void func_08080370(void);
void func_080BB378(u8, u8);
void func_0807BE64(u8);
u32 func_0809D984(u8);
void func_0807BEF4(u32, const u8 *, u8);
void func_0809D96C(u8);
void func_0809D948(u8, u32);
void func_080B4390(s8, s32);
struct Sprite *func_080771BC(const u8 *, const u8 *, u32, u32, u32, u32, u32, u32, u32);
u32 func_080B43AC(void *);
void func_080771F4(struct Sprite *);
void func_08075DA8(u8, void (*)(void));
void func_080BB2B4(void);
u32 func_0809E09C(void);
void func_0808A7F8(u32, u32, u32, u32);
void func_0808A86C(u8);
void func_08089CE0(u8, u8);
s32 func_0808B6E8(void);
void func_0808D7C0(u8);
s32 func_0808DD80(void);
void func_0808EE20(void);
void func_08090168(void);
void func_0809104C(void);
void func_08075E28(u8);
void func_080BE628(void);
u32 func_0809A99C(u8, u8);
struct Obj *func_0809A908(u8, u8);
void func_0809B720(u8, u8);
void func_080BD488(u8, u8, struct Item *);
void func_08075E80(u8);
void func_08099664(void);

void func_080BB4D4(void)
{
    struct Cfg cfg;
    struct Pair opp;
    s32 vals[2];
    s32 amount;
    s32 state;
    u32 i;
    u8 ack, ok, flag;
    s32 done;
    u8 sel;

    func_08091DB4();
    func_0807C290(D_08024435);
    func_0807B77C(func_08082E70(1), 0, 2);
    func_0807BA24(D_020309A4[0], 3, 0, 2, 3, 1, 0);
    func_0807BA24(D_020309A4[1], 3, 0, 2, 3, 8, 0);
    vals[0] = func_0807F558();
    func_0807BA24(vals[0], 9, 0, 0x12, 6, 4, 0);
    func_0807A1A4();
    func_08079544(0xF, 0);
    func_0807970C();
    func_080801D0();
    while (!func_08080308())
    {
        if (D_0300000E & 2)
        {
            func_08075F20(0xCB);
            func_08080370();
            func_0807C290(D_080244DB);
            func_08079544(0x10, 0);
            func_0807970C();
            return;
        }
        func_080C8FCC(1);
    }
    func_08080390(0, 0, D_080F5BB0);
    func_080804DC(0, 0, D_080F5BB0);
    do
    {
        ack = func_080803C4();
        ok = func_08080510();
        func_080C8FCC(1);
    } while (ack == 0 || ok == 0);
    func_08080390(D_02030586, 0x12, D_080F5BBC);
    func_080804DC(D_0203198C, 0x12, D_080F5BBC);
    do
    {
        ack = func_080803C4();
        ok = func_08080510();
        func_080C8FCC(1);
    } while (ack == 0 || ok == 0);
    func_08080390(D_020309A4, 4, D_080F5BC8);
    func_080804DC(&opp, 4, D_080F5BC8);
    do
    {
        ack = func_080803C4();
        ok = func_08080510();
        func_080C8FCC(1);
    } while (ack == 0 || ok == 0);
    func_08080390(&vals[0], 4, D_080F5BC8);
    func_080804DC(&vals[1], 4, D_080F5BC8);
    do
    {
        ack = func_080803C4();
        ok = func_08080510();
        func_080C8FCC(1);
    } while (ack == 0 || ok == 0);
    func_0807C290(D_0802450D);
    func_0807B77C(D_0203198C, 0, 4);
    func_0807BA24(opp.a, 3, 0, 2, 5, 1, 0);
    func_0807BA24(opp.b, 3, 0, 2, 5, 8, 0);
    func_0807BA24(vals[1], 9, 0, 0x12, 7, 4, 0);
    func_0807A1A4();
    for (i = 0; i <= 299; i++)
        func_080C8FCC(1);
    func_08079544(0x10, 0);
    func_0807970C();
    func_08091DB4();
    if (D_030057F4)
        state = 0;
    else
        state = 0x1000;
    done = 0;
    while (!done)
    {
        switch (state)
        {
        case 0:
            D_02020E3C.field_4 = 0;
            D_02020E3C.field_8 = 0;
            D_02020E3C.field_E = 0;
            cfg.field_8 = 0;
            cfg.field_9 = (D_03000010() * 14 >> 15) + 1;
            func_0807C290(D_08024654);
            func_080BB378(0, cfg.field_8);
            func_08079544(0xF, 0);
            func_0807970C();
            state = 0x10;
            break;
        case 0x10:
            func_0807C290(D_080246D4);
            switch (D_0200C4A0)
            {
            case 0:
                state = 0x100;
                break;
            case 1:
                state = 0x200;
                break;
            case 2:
                state = 0x300;
                break;
            }
            break;
        case 0x100:
            func_0807C290(D_080246DC);
            state = 0x110;
            break;
        case 0x110:
            func_0807C290(D_0802473F);
            if (D_0200C4A2 == 1)
            {
                switch (D_0200C4A0)
                {
                case 0:
                    state = 0x111;
                    break;
                case 1:
                    state = 0x112;
                    break;
                case 2:
                    state = 0x113;
                    break;
                case 3:
                    state = 0x115;
                    break;
                case 4:
                    state = 0x116;
                    break;
                case 5:
                    state = 0x114;
                    break;
                }
                break;
            }
            func_0807C290(D_08024743);
            state = 0x10;
            break;
        case 0x111:
            func_0807C290(D_08024746);
            while (1)
            {
                func_0807BE64(4);
                flag = (func_0809D984(1) || func_0809D984(2) || func_0809D984(3) || func_0809D984(4)) ? 0 : 2;
                func_0807BEF4(4, D_0873F91C[0], flag);
                for (i = 1; i <= 4; i++)
                {
                    flag = func_0809D984(i) ? 2 : 0;
                    func_0807BEF4(4, D_0873F91C[i], flag);
                }
                func_0807C290(D_08024980);
                if (D_0200C4A2 != 1)
                    break;
                func_0809D96C(1);
                func_0809D96C(2);
                func_0809D96C(3);
                func_0809D96C(4);
                if (D_0200C4A0)
                    func_0809D948(D_0200C4A0, 0);
                func_080BB378(0, cfg.field_8);
            }
            func_0807C290(D_08024984);
            state = 0x110;
            break;
        case 0x112:
            func_0807C290(D_08024784);
            while (1)
            {
                func_0807BE64(4);
                flag = (func_0809D984(5) || func_0809D984(6) || func_0809D984(7) || func_0809D984(8) || func_0809D984(9) || func_0809D984(10)) ? 0 : 2;
                func_0807BEF4(4, D_0873F91C[0], flag);
                for (i = 5; i <= 10; i++)
                {
                    flag = func_0809D984(i) ? 2 : 0;
                    func_0807BEF4(4, D_0873F91C[i], flag);
                }
                func_0807C290(D_08024980);
                if (D_0200C4A2 != 1)
                    break;
                func_0809D96C(5);
                func_0809D96C(6);
                func_0809D96C(7);
                func_0809D96C(8);
                func_0809D96C(9);
                func_0809D96C(10);
                if (D_0200C4A0)
                    func_0809D948(D_0200C4A0 + 4, 0);
                func_080BB378(0, cfg.field_8);
            }
            func_0807C290(D_08024984);
            state = 0x110;
            break;
        case 0x113:
            func_0807C290(D_08024868);
            while (1)
            {
                func_0807BE64(4);
                flag = (func_0809D984(11) || func_0809D984(12) || func_0809D984(13) || func_0809D984(14) || func_0809D984(15)) ? 0 : 2;
                func_0807BEF4(4, D_0873F91C[0], flag);
                for (i = 11; i <= 15; i++)
                {
                    flag = func_0809D984(i) ? 2 : 0;
                    func_0807BEF4(4, D_0873F91C[i], flag);
                }
                func_0807C290(D_08024980);
                if (D_0200C4A2 != 1)
                    break;
                func_0809D96C(11);
                func_0809D96C(12);
                func_0809D96C(13);
                func_0809D96C(14);
                func_0809D96C(15);
                if (D_0200C4A0)
                    func_0809D948(D_0200C4A0 + 10, 0);
                func_080BB378(0, cfg.field_8);
            }
            func_0807C290(D_08024984);
            state = 0x110;
            break;
        case 0x114:
            func_0807C290(D_08024917);
            while (1)
            {
                func_0807BE64(4);
                for (i = 16; i <= 19; i++)
                {
                    flag = func_0809D984(i) ? 2 : 0;
                    func_0807BEF4(4, D_0873F91C[i], flag);
                }
                func_0807C290(D_08024980);
                if (D_0200C4A2 != 1)
                    break;
                if (func_0809D984(D_0200C4A0 + 16))
                    func_0809D96C(D_0200C4A0 + 16);
                else
                    func_0809D948(D_0200C4A0 + 16, 0);
                func_080BB378(0, cfg.field_8);
            }
            func_0807C290(D_08024984);
            state = 0x110;
            break;
        case 0x115:
            func_0807C290(D_080247F9);
            while (1)
            {
                func_0807BE64(4);
                if (!func_0809D984(20))
                {
                    func_0807BEF4(4, D_0873F91C[20], 2);
                    func_0807BEF4(4, D_0873F91C[21], 0);
                }
                else
                {
                    func_0807BEF4(4, D_0873F91C[20], 0);
                    func_0807BEF4(4, D_0873F91C[21], 2);
                }
                func_0807C290(D_08024980);
                if (D_0200C4A2 != 1)
                    break;
                if (D_0200C4A0 == 0)
                {
                    func_0809D96C(20);
                }
                else
                {
                    func_0807C290(D_08024837);
                    amount = 1;
                    func_080B4390(5, 99999);
                    D_0201F5F8.field_8C = func_080771BC(D_080C93C8, D_080C93F0, 0, 0, 0x40, D_0201F5CC, D_0201F5CE, 0x30, 0);
                    D_0201F5F8.field_90 = func_080771BC(D_080C9470, D_080C9498, 0, 0, 0x58, (u16)(D_0201F5CC + 2), D_0201F5CE, 0x30, 0);
                    do
                    {
                        D_0201F5F8.field_8C->x = D_0201F5F8.field_90->x = (16 - D_0201F5F8.field_85) << 11;
                        func_0807BA24(amount, 5, 2, 2, 5, 4, 0);
                        func_0807A1A4();
                    } while (func_080B43AC(&amount) != 1);
                    func_0807C290(D_08024865);
                    func_080771F4(D_0201F5F8.field_8C);
                    func_080771F4(D_0201F5F8.field_90);
                    if (amount == 0)
                        continue;
                    func_0809D948(20, amount * 1000);
                }
                func_080BB378(0, cfg.field_8);
            }
            func_0807C290(D_08024984);
            state = 0x110;
            break;
        case 0x116:
            func_0807C290(D_080248D2);
            while (1)
            {
                func_0807BE64(4);
                func_0807BEF4(4, D_0873F91C[23], D_02020E3C.field_E == 0 ? 2 : 0);
                func_0807BEF4(4, D_0873F91C[24], D_02020E3C.field_E == 5 ? 2 : 0);
                func_0807BEF4(4, D_0873F91C[25], D_02020E3C.field_E == 10 ? 2 : 0);
                func_0807BEF4(4, D_0873F91C[26], D_02020E3C.field_E == 20 ? 2 : 0);
                func_0807C290(D_08024980);
                if (D_0200C4A2 != 1)
                    break;
                switch (D_0200C4A0)
                {
                case 0:
                    D_02020E3C.field_E = 0;
                    break;
                case 1:
                    D_02020E3C.field_E = 5;
                    break;
                case 2:
                    D_02020E3C.field_E = 10;
                    break;
                case 3:
                    D_02020E3C.field_E = 20;
                    break;
                }
                func_080BB378(0, cfg.field_8);
            }
            func_0807C290(D_08024984);
            state = 0x110;
            break;
        case 0x200:
            func_0807C290(D_08024987);
            while (1)
            {
                func_0807BE64(3);
                for (i = 0; i <= 14; i++)
                {
                    flag = i == cfg.field_8 ? 2 : 0;
                    func_0807BEF4(3, D_0873F988[i], flag);
                }
                func_0807C290(D_08024992);
                if (D_0200C4A2 != 1)
                    break;
                cfg.field_8 = D_0200C4A0;
                func_080BB378(0, cfg.field_8);
            }
            func_0807C290(D_08024996);
            state = 0x10;
            break;
        case 0x300:
            cfg.field_0 = D_02020E3C.field_4;
            cfg.field_4 = D_02020E3C.field_8;
            cfg.field_A = D_02020E3C.field_E;
            func_08080390(&cfg, 12, D_080F5BD8);
            do
            {
                ack = func_080803C4();
                func_080C8FCC(1);
            } while (ack == 0);
            func_0807C290(D_080246D8);
            state = 0x2000;
            break;
        case 0x1000:
            func_0807C290(D_08024A32);
            func_08079544(0xF, 0);
            func_0807970C();
            func_080804DC(&cfg, 12, D_080F5BD8);
            do
            {
                ok = func_08080510();
                func_080C8FCC(1);
            } while (ok == 0);
            D_02020E3C.field_4 = cfg.field_0;
            D_02020E3C.field_8 = cfg.field_4;
            D_02020E3C.field_E = cfg.field_A;
            func_0807C290(D_08024A8B);
            state = 0x2000;
            break;
        case 0x2000:
            D_0201F5F8.field_1 = 0;
            func_0807C290(D_08024AC2);
            func_080BB378(1, cfg.field_8);
            func_08075DA8(4, func_080BB2B4);
            state = 0x2010;
            break;
        case 0x2010:
            func_0807BA24(func_0807F558(), 9, 0, 0x12, 3, 4, 0);
            D_02009480.field_16 = D_0201F5F8.field_1;
            func_0807C290(D_08024B98);
            D_0201F5F8.field_1 = D_0200C4A0;
            switch (D_0200C4A0)
            {
            case 0:
                sel = 0;
                state = 0x2100;
                break;
            case 1:
                state = 0x2200;
                break;
            case 2:
                state = 0x2300;
                break;
            case 3:
                if (func_0809E09C())
                {
                    state = 0x2400;
                    break;
                }
                func_08075F20(0x114);
                func_0807C290(D_08024BA5);
                break;
            case 4:
                state = 0x2500;
                break;
            }
            break;
        case 0x2100:
            D_0201F5F8.field_2 = D_0201F5F8.field_3 = D_0201F5F8.field_4 = D_0201F5F8.field_5 = 0;
            func_0807C290(D_08000B8F);
            D_02009480.field_1356 = sel;
            state = 0x2101;
            break;
        case 0x2101:
            func_0808A7F8(2, 3, 0x20, 0x38);
            func_0807C290(D_08000BAE);
            func_0808A86C(2);
            if (D_0200C4A2 != 1)
            {
                state = 0x2010;
                break;
            }
            sel = D_0200C4A0;
            func_0807C290(D_08024B9C);
            state = D_0200C4A0 == 0 ? 0x2110 : 0x2120;
            break;
        case 0x2110:
            func_08089CE0(0, 0);
            state = 0x2111;
            break;
        case 0x2111:
            switch (func_0808B6E8())
            {
            case -1:
                func_0807C290(D_08024B13);
                func_080BB378(1, cfg.field_8);
                func_0807BA24(func_0807F558(), 9, 0, 0x12, 3, 4, 0);
                state = 0x2100;
                break;
            case 1:
                state = 0x2112;
                break;
            }
            break;
        case 0x2112:
            D_0201F5F8.field_10 = &D_02020E88[D_02030B6C[D_0201F5F8.field_2]];
            func_0808D7C0(0);
            state = 0x2111;
            break;
        case 0x2120:
            switch (func_0808DD80())
            {
            case -1:
                func_0807C290(D_08024B13);
                func_080BB378(1, cfg.field_8);
                state = 0x2100;
                break;
            case 1:
                state = 0x2121;
                break;
            }
            break;
        case 0x2121:
            D_0201F5F8.field_14 = &D_02027A10[D_02030C26[D_0201F5F8.field_4]];
            func_0808EE20();
            state = 0x2120;
            break;
        case 0x2200:
            func_0807C290(D_08024B9C);
            func_08090168();
            for (i = 0; i <= 5 && D_02020E4C.team[i] == 0; i++)
                ;
            if (i > 5)
            {
                func_0807C290(D_0800360C);
                state = 0x2300;
                break;
            }
            func_0807C290(D_08024B13);
            func_080BB378(1, cfg.field_8);
            state = 0x2010;
            break;
        case 0x2300:
            func_0807C290(D_08024B9C);
            func_0809104C();
            func_0807C290(D_08003762);
            for (i = 0; i <= 5; i++)
            {
                if (D_02020E04.sprites[i])
                    func_080771F4(D_02020E04.sprites[i]);
                if (D_02020E04.icons[i])
                    func_080771F4(D_02020E04.icons[i]);
            }
            func_080771F4(D_02020E04.cursor);
            if (D_02020E04.field_30)
                func_080771F4(D_02020E04.field_30);
            func_0808A86C(0);
            D_0300004C &= 0xFDFF;
            func_0807C290(D_08024B13);
            func_080BB378(1, cfg.field_8);
            state = 0x2010;
            break;
        case 0x2400:
            func_0807C290(D_08024BE5);
            if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
            {
                D_02030AE0.field_3 = 0;
                func_0807C290(D_08024C12);
                state = 0x3000;
                break;
            }
            state = 0x2010;
            break;
        case 0x2500:
            func_0807C290(D_08024C59);
            if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
            {
                D_02030AE0.field_3 = 1;
                state = 0x3000;
                break;
            }
            state = 0x2010;
            break;
        case 0x3000:
            D_02030AE0.field_0 = 1;
            while (D_02030AE0.field_1 == 0 || D_02030AE0.field_2 == 0)
                func_080C8FCC(1);
            func_0807C290(D_08024C56);
            func_08075E28(4);
            done = 1;
            break;
        }
    }
    func_0807C290(D_080245EF);
    func_080BE628();
    for (i = 0; i <= 5; i++)
    {
        if (func_0809A99C(0, i))
            func_0809A908(0, i)->field_6 = func_0809A908(0, i)->field_62;
    }
    for (i = 0; i < 10; i++)
    {
        func_08080390(&D_02031A0C.items[0][i], 0x94, D_080F5BE4);
        func_080804DC(&D_02031A0C.items[1][i], 0x94, D_080F5BE4);
        do
        {
            ack = func_080803C4();
            ok = func_08080510();
            func_080C8FCC(1);
        } while (ack == 0 || ok == 0);
        func_0807BA24((i + 1) * 100 / 18, 3, 0, 2, 8, 10, 0);
        func_0807A1A4();
    }
    for (i = 0; i < 7; i++)
    {
        func_08080390(&D_02031A0C.cells[0][i], 0x40, D_080F5BF0);
        func_080804DC(&D_02031A0C.cells[1][i], 0x40, D_080F5BF0);
        do
        {
            ack = func_080803C4();
            ok = func_08080510();
            func_080C8FCC(1);
        } while (ack == 0 || ok == 0);
        func_0807BA24((i + 11) * 100 / 18, 3, 0, 2, 8, 10, 0);
        func_0807A1A4();
    }
    func_08080390(D_02036A28, 0x1FA, D_080F5BFC);
    func_080804DC(D_02036A28 + 0x1FA, 0x1FA, D_080F5BFC);
    do
    {
        ack = func_080803C4();
        ok = func_08080510();
        func_080C8FCC(1);
    } while (ack == 0 || ok == 0);
    func_0807BA24(100, 3, 0, 2, 8, 10, 0);
    func_0807A1A4();
    func_08080390(D_02036A04, 0x12, D_080F5C08);
    func_080804DC(D_02036A04 + 0x12, 0x12, D_080F5C08);
    do
    {
        ack = func_080803C4();
        ok = func_08080510();
        func_080C8FCC(1);
    } while (ack == 0 || ok == 0);
    D_02031A0C.field_5410 = func_0807F558();
    func_08080390(&D_02031A0C.field_5410, 4, D_080F5C14);
    func_080804DC(&D_02031A0C.field_5414, 4, D_080F5C14);
    do
    {
        ack = func_080803C4();
        ok = func_08080510();
        func_080C8FCC(1);
    } while (ack == 0 || ok == 0);
    for (i = 0; i <= 5; i++)
    {
        if (D_02031A0C.items[1][i].field_0)
        {
            D_02031A0C.groups[1].units[i].id = i;
            D_02031A0C.groups[1].units[i].list[0] = i;
            D_02031A0C.groups[1].units[i].list[3] |= 0xFF;
            D_02031A0C.groups[1].units[i].list[2] |= 0xFF;
            D_02031A0C.groups[1].units[i].list[1] |= 0xFF;
        }
        else
        {
            D_02031A0C.groups[1].units[i].id |= 0xFF;
        }
        func_0809B720(1, i);
    }
    func_080BD488(150, 0, &D_02031A0C.items[1][10]);
    D_02020E3C.field_0 = 2;
    if (cfg.field_8)
        D_02020E3C.field_1 = D_0873F9C4[cfg.field_8];
    else
        D_02020E3C.field_1 = D_0873F9C4[cfg.field_9];
    D_02020E3C.field_C = 0;
    D_02020E3C.field_D = 0;
    func_08079544(0x10, 0);
    func_0807970C();
    func_08075E80(0x21);
    func_08099664();
}
