#include "types.h"

struct Intro
{
    void *logo[4];
    void *field_10;
    void *stars[32];
};

struct Window
{
    u8 pad0[0x16];
    u8 field_16;
};

extern u8 D_0201F5F4;
extern u8 D_0201F5F5;
extern u8 D_0201F5F6;
extern u8 D_0201F5F7;
extern u8 D_0201F6DC;
extern u16 D_0300004C;
extern u16 D_0300004E;
extern u32 D_03000060[2];
extern u16 D_0300000E;
extern u16 D_020209D8;
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern struct Intro D_020309AC;
extern struct Window D_02009480;
extern u8 D_02020E4C[];
extern u8 D_020289A8[];
extern const u8 D_080ED260[];
extern const u8 D_080F0248[];
extern const u8 D_087B1090[];
extern const u8 D_080E7220[];
extern const u8 D_080ECAB0[];
extern const u8 D_080ECD00[];
extern const u8 D_080F04B0[];
extern const u8 D_080F06D4[];
extern const u8 D_080F0764[];
extern const u8 D_080F0778[];
extern const u8 D_08000975[];
extern const u8 D_08000980[];
extern const u8 D_08000984[];
extern const u8 D_0800098F[];
extern const u8 D_0800099A[];
extern const u8 D_080009A3[];
extern const u8 D_080009B8[];
extern const u8 D_080009C5[];
extern const u8 D_080009D4[];
extern const u8 D_080009DF[];
extern const u8 D_08000A9F[];
extern const u8 D_08000AA2[];
extern const u8 D_08000AC6[];

void func_0807E44C(void);
void func_080C7690(void);
void func_080C8B84(const void *, void *);
void func_080C8B7C(const void *, void *, u32);
void func_0807FF9C(const void *, u8, u16, u8);
void func_08076FA0(void);
void func_08079544(u8, u8);
void func_0807970C(void);
void func_08075DA8(u8, void (*)(void));
void func_0807DFE8(void);
void func_0807E1E4(void);
void func_0807E3C0(void);
void func_08087A54(void);
u8 func_08079724(void);
u8 func_080796EC(void);
void func_080C8FCC(u32);
void func_08075E28(u8);
void func_080771F4(void *);
void func_08075E6C(u8);
void func_08075E80(u8);
void *func_080771BC(const void *, const void *, u16, s16, s16, u16, u16, u32, u32);
void func_08075F20(u16);
void func_080836FC(void);
void func_08083BBC(u16);
void func_08091DB4(void);
void func_0807C290(const u8 *);
void func_0807BEF4(u8, const u8 *, u8);
void func_0807A1A4(void);
void func_080B8E90(u8);
void func_0807EB78(void);
void func_080BB4D4(void);
void func_080BC700(void);
void func_080BB188(void);
void func_080BA104(void);
void func_080C6684(void);
void func_080B92E4(u8);

void func_0807E550(void)
{
    s32 state;
    s32 quit;
    u32 i;
    u32 n;

    func_0807E44C();
    if (!D_0201F5F6)
        state = 0;
    else
        state = 0x2000;
    quit = 0;
    do
    {
        switch (state)
        {
        case 0:
            func_080C7690();
            D_0300004C = 0x1040;
            *(vu16 *)0x05000000 = 0;
            func_080C8B84(D_080ED260, (void *)0x06010000);
            func_080C8B84(D_080F0248, (void *)0x05000200);
            func_0807FF9C(D_087B1090, 9, 0x3A4, 15);
            func_08076FA0();
            for (i = 0; i < 4; i++)
                D_020309AC.logo[i] = 0;
            D_020309AC.field_10 = 0;
            for (i = 0; i < 32; i++)
                D_020309AC.stars[i] = 0;
            func_08079544(1, 1);
            func_0807970C();
            func_08075DA8(3, func_0807DFE8);
            while (!func_08079724() || !func_080796EC())
            {
                if (!func_08079724() && (D_0300000E & 8))
                    func_08079544(4, 30);
                func_080C8FCC(1);
            }
            func_08075E28(3);
            for (i = 0; i < 4; i++)
            {
                if (D_020309AC.logo[i])
                    func_080771F4(D_020309AC.logo[i]);
            }
            for (i = 0; i < 32; i++)
            {
                if (D_020309AC.stars[i])
                    func_080771F4(D_020309AC.stars[i]);
            }
            func_08079544(3, 30);
            state = 0x10;
            break;
        case 0x10:
            func_08075E6C(1);
            D_0300004C |= 0x100;
            D_0300004E = 0x84;
            D_03000060[0] = D_03000060[1] = 0;
            func_080C8B84(D_080E7220, (void *)0x06004000);
            func_080C8B84(D_080ECAB0, (void *)0x05000000);
            func_080C8B84(D_080ECD00, (void *)0x06000000);
            func_080C8B84(D_080F04B0, (void *)0x06017000);
            func_080C8B84(D_080F06D4, (void *)0x050003C0);
            D_020309AC.field_10 = func_080771BC(D_080F0764, D_080F0778, 0, 120, 96, 0x380, 14, 32, 0);
            func_0807970C();
            func_08075DA8(3, func_0807E1E4);
            state = 0x1000;
            for (n = 0; n <= 0x32E; n++)
            {
                if (D_0300000E & 8)
                {
                    func_08075F20(0xC9);
                    state = 0x2000;
                    if (D_0201F5F4 == 0)
                        D_0201F5F7 = 0;
                    else
                        D_0201F5F7 = 1;
                    break;
                }
                func_080C8FCC(1);
            }
            func_08079544(2, 16);
            func_0807970C();
            func_08075E28(3);
            break;
        case 0x1000:
            func_080836FC();
            func_08083BBC(0xAC);
            D_020209D8 = 0xAC;
            func_08075DA8(2, func_0807E3C0);
            func_08075DA8(5, func_08087A54);
            do
                func_080C8FCC(1);
            while (D_0201F6DC);
            state = 0;
            break;
        case 0x2000:
            func_08075E80(2);
            func_08091DB4();
            func_0807C290(D_08000975);
            func_0807BEF4(0, D_08000984, 0);
            func_0807BEF4(0, D_0800098F, D_0201F5F4 ? 0 : 4);
            func_0807BEF4(0, D_0800099A, D_0201F5F4 ? 0 : 4);
            func_0807BEF4(0, D_080009A3, D_0201F5F4 ? 0 : 4);
            func_0807BEF4(0, D_080009B8, 0);
            func_0807BEF4(0, D_080009C5, 0);
            func_0807BEF4(0, D_080009D4, 0);
            D_02009480.field_16 = D_0201F5F7;
            func_0807A1A4();
            func_08079544(15, 0);
            func_0807970C();
            state = 0x2010;
            break;
        case 0x2010:
            func_0807C290(D_08000980);
            if (D_0200C4A2 == 1)
            {
                D_0201F5F7 = D_0200C4A0;
                switch (D_0201F5F7)
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
                case 3:
                    state = 0x2400;
                    break;
                case 4:
                    state = 0x2500;
                    break;
                case 5:
                    state = 0x2600;
                    break;
                case 6:
                    state = 0x2700;
                    break;
                }
            }
            else
            {
                func_08079544(16, 0);
                func_0807970C();
                func_08079544(1, 30);
                state = 0x10;
            }
            break;
        case 0x2100:
            if (D_0201F5F4)
            {
                func_0807C290(D_080009DF);
                if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
                {
                    func_08079544(16, 0);
                    func_0807970C();
                    func_08091DB4();
                    func_08079544(15, 0);
                    func_080B8E90(1);
                    func_08079544(16, 0);
                    func_0807970C();
                    func_0807EB78();
                    D_0201F5F5 = 0;
                    quit = 1;
                }
                else
                {
                    func_0807C290(D_08000A9F);
                    state = 0x2010;
                }
            }
            else
            {
                func_08079544(16, 0);
                func_0807970C();
                func_08091DB4();
                func_08079544(15, 0);
                func_080B8E90(1);
                func_08079544(16, 0);
                func_0807970C();
                D_0201F5F5 = 0;
                quit = 1;
            }
            break;
        case 0x2200:
            if (D_0201F5F4)
            {
                func_08079544(16, 0);
                func_0807970C();
                D_0201F5F5 = 1;
                quit = 1;
            }
            else
            {
                func_08075F20(0x114);
                state = 0x2010;
            }
            break;
        case 0x2300:
            if (D_0201F5F4)
            {
                func_0807C290(D_08000AA2);
                if (D_0200C4A2 == 1)
                {
                    func_08079544(16, 0);
                    func_0807970C();
                    if (D_0200C4A0 == 0)
                    {
                        func_080C8B7C(D_02020E4C, D_020289A8, 0x04001ED7);
                        func_080BB4D4();
                        func_080C8B7C(D_020289A8, D_02020E4C, 0x04001ED7);
                    }
                    else
                    {
                        func_080BC700();
                    }
                    state = 0x2000;
                }
                else
                {
                    func_0807C290(D_08000AC6);
                    state = 0x2010;
                }
            }
            else
            {
                func_08075F20(0x114);
                state = 0x2010;
            }
            break;
        case 0x2400:
            if (D_0201F5F4)
            {
                func_08079544(16, 0);
                func_0807970C();
                func_080BB188();
                state = 0x2000;
            }
            else
            {
                func_08075F20(0x114);
                state = 0x2010;
            }
            break;
        case 0x2500:
            func_08079544(16, 0);
            func_0807970C();
            func_080BA104();
            state = 0x2000;
            break;
        case 0x2600:
            func_08079544(16, 0);
            func_0807970C();
            func_080C6684();
            state = 0x2000;
            break;
        case 0x2700:
            func_08079544(16, 0);
            func_0807970C();
            func_080B92E4(1);
            state = 0x2000;
            break;
        }
    } while (!quit);
}
