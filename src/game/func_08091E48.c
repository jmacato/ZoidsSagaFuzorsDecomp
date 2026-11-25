#include "types.h"

struct Zoid
{
    u8 data[0x94];
};

struct Pilot
{
    u8 data[0x40];
};

struct State
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 pad_8[8];
    struct Zoid *zoid;
    struct Pilot *pilot;
};

struct Menu
{
    u8 pad_0[0x1356];
    u8 sel;
};

struct Save
{
    u8 pad_0[0x7A6A];
    u8 team[6];
};

struct Sprites
{
    void *a[6];
    void *b[6];
    void *field_30;
    void *field_34;
};

extern struct State D_0201F5F8;
extern struct Menu D_02009480;
extern struct Save D_02020E4C;
extern struct Zoid D_02020E88[];
extern struct Pilot D_02027A10[];
extern struct Sprites D_02020E04;
extern struct Zoid D_02031254;
extern u8 D_02030B6C[];
extern u8 D_02030C26[];
extern u8 D_02030F92[][2];
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern u16 D_0300004C;
extern const u8 D_08000B8F[];
extern const u8 D_08000BAE[];
extern const u8 D_08000BB4[];
extern const u8 D_08000BCF[];
extern const u8 D_08000BD3[];
extern const u8 D_08000BD6[];
extern const u8 D_08000BFD[];
extern const u8 D_08000C01[];
extern const u8 D_08000C04[];
extern const u8 D_08000C38[];
extern const u8 D_0800360C[];
extern const u8 D_08003762[];
void func_08091DB4(void);
void func_08079544(u8, u8);
void func_0808AB28(void);
void func_0807970C(void);
s32 func_0808AB98(void);
void func_0807C290(const u8 *);
void func_0808A890(u32);
void func_0808A8B4(u32);
void func_0808A86C(u32);
void func_0808A7F8(u32, u32, u32, u32);
void func_0808AC08(void);
void func_08089CE0(void *, s32);
s32 func_0808B6E8(void);
void func_0808D7C0(u8);
s32 func_0808DD80(void);
void func_0808EE20(void);
s32 func_0808F094(void);
s32 func_0808F89C(void);
void func_0808A3F0(s32);
s32 func_0808FF4C(void);
void func_080BD488(u8, u8, struct Zoid *);
u32 func_080900B0(void);
void func_08090168(void);
void func_0809104C(void);
void func_080771F4(void *);
void func_0809181C(u8);
void func_08091AFC(void);
void func_080BA104(void);
void func_080C6684(void);
void func_08088DB0(void);
void func_080B92E4(u32);
void func_08091C04(void);

s32 func_08091E48(void)
{
    s32 state;
    u8 sel;
    u8 i;

    func_08091DB4();
    D_0201F5F8.field_1 = 0;
    func_08079544(0xF, 0x10);
    state = 0;
    while (1)
    {
        switch (state)
        {
        case 0:
            func_0808AB28();
            func_0807970C();
            state = 0x10;
            break;
        case 0x10:
            switch (func_0808AB98())
            {
            case -1:
                func_08079544(0x10, 0);
                func_0807970C();
                return 0;
            case 0:
                sel = 0;
                state = 0x1000;
                break;
            case 1:
                sel = 0;
                state = 0x2000;
                break;
            case 2:
                state = 0x4000;
                break;
            case 3:
                state = 0x5000;
                break;
            case 4:
                state = 0x6000;
                break;
            case 5:
                sel = 0;
                state = 0x3000;
                break;
            case 6:
                state = 0x7000;
                break;
            case 7:
                sel = 0;
                state = 0x8000;
                break;
            case 8:
                state = 0x9000;
                break;
            }
            break;
        case 0x1000:
            D_0201F5F8.field_2 = D_0201F5F8.field_3 = D_0201F5F8.field_4 = D_0201F5F8.field_5 = 0;
            func_0807C290(D_08000B8F);
            D_02009480.sel = sel;
            state = 0x1010;
            break;
        case 0x1010:
            func_0808A890(1);
            func_0808A7F8(2, 3, 0x20, 0x38);
            func_0807C290(D_08000BAE);
            func_0808A86C(2);
            if (D_0200C4A2 == 1)
            {
                sel = D_0200C4A0;
                func_0808AC08();
                if (D_0200C4A0 == 0)
                    state = 0x1100;
                else
                    state = 0x1200;
            }
            else
            {
                func_0808A8B4(1);
                state = 0x10;
            }
            break;
        case 0x1100:
            func_08089CE0(0, 0);
            state = 0x1110;
            break;
        case 0x1110:
            switch (func_0808B6E8())
            {
            case -1:
                func_0808AB28();
                state = 0x1000;
                break;
            case 1:
                state = 0x1120;
                break;
            }
            break;
        case 0x1120:
            D_0201F5F8.zoid = &D_02020E88[D_02030B6C[D_0201F5F8.field_2]];
            func_0808D7C0(0);
            state = 0x1110;
            break;
        case 0x1200:
            switch (func_0808DD80())
            {
            case -1:
                func_0808AB28();
                state = 0x1000;
                break;
            case 1:
                state = 0x1210;
                break;
            }
            break;
        case 0x1210:
            D_0201F5F8.pilot = &D_02027A10[D_02030C26[D_0201F5F8.field_4]];
            func_0808EE20();
            state = 0x1200;
            break;
        case 0x2000:
            func_0807C290(D_08000BB4);
            state = 0x2010;
            break;
        case 0x2010:
            D_02009480.sel = sel;
            func_0808A890(1);
            func_0808A7F8(2, 3, 0x18, 0x48);
            func_0807C290(D_08000BCF);
            func_0808A86C(2);
            if (D_0200C4A2 == 1)
            {
                sel = D_0200C4A0;
                if (sel == 0)
                    state = 0x2100;
                else
                    state = 0x2200;
            }
            else
            {
                func_0807C290(D_08000BD3);
                state = 0x10;
            }
            func_0808A8B4(1);
            break;
        case 0x2100:
            if (func_0808F094() == 0)
                state = 0x2010;
            else
                return 1;
            break;
        case 0x2200:
            if (func_0808F89C() != 0)
                state = 0x2000;
            else
                state = 0x2010;
            break;
        case 0x3000:
            D_0201F5F8.field_6 = 0;
            D_0201F5F8.field_7 = 0;
            func_0807C290(D_08000BD6);
            D_02009480.sel = sel;
            state = 0x3010;
            break;
        case 0x3010:
            func_0808A890(1);
            func_0808A7F8(2, 3, 0x30, 0x88);
            func_0807C290(D_08000BFD);
            func_0808A86C(2);
            if (D_0200C4A2 == 1)
            {
                sel = D_0200C4A0;
                if (sel == 0)
                {
                    func_0808AC08();
                    func_0807C290(D_08000C01);
                    state = 0x3100;
                }
                else
                {
                    state = 0x3200;
                }
            }
            else
            {
                func_0807C290(D_08000C01);
                func_0808A8B4(1);
                state = 0x10;
            }
            break;
        case 0x3100:
            func_0808A3F0(0);
            state = 0x3110;
            break;
        case 0x3110:
            switch (func_0808FF4C())
            {
            case -1:
                func_0808AB28();
                state = 0x3000;
                break;
            case 1:
                state = 0x3120;
                break;
            }
            break;
        case 0x3120:
            func_080BD488(D_02030F92[D_0201F5F8.field_6][0], 0, &D_02031254);
            D_0201F5F8.zoid = &D_02031254;
            func_0808D7C0(1);
            state = 0x3110;
            break;
        case 0x3200:
            if (func_080900B0() != 0)
                state = 0x3000;
            else
                state = 0x3010;
            break;
        case 0x4000:
            func_0808AC08();
            func_08090168();
            for (i = 0; i < 6; i++)
                if (D_02020E4C.team[i] != 0)
                    break;
            if (i < 6)
            {
                state = 0;
                break;
            }
            func_0807C290(D_0800360C);
            state = 0x5000;
            break;
        case 0x5000:
            func_0808AC08();
            func_0809104C();
            func_0807C290(D_08003762);
            for (i = 0; i < 6; i++)
            {
                if (D_02020E04.a[i] != 0)
                    func_080771F4(D_02020E04.a[i]);
                if (D_02020E04.b[i] != 0)
                    func_080771F4(D_02020E04.b[i]);
            }
            func_080771F4(D_02020E04.field_34);
            if (D_02020E04.field_30 != 0)
                func_080771F4(D_02020E04.field_30);
            func_0808A86C(0);
            D_0300004C &= 0xFDFF;
            state = 0;
            break;
        case 0x6000:
            func_0808AC08();
            func_0809181C(0);
            state = 0;
            break;
        case 0x7000:
            func_0808A890(1);
            func_08091AFC();
            func_0808A8B4(1);
            state = 0x10;
            break;
        case 0x8000:
            func_0807C290(D_08000C04);
            state = 0x8010;
            break;
        case 0x8010:
            D_02009480.sel = sel;
            func_0808A890(1);
            func_0808A7F8(2, 3, 0x30, 0x90);
            func_0807970C();
            func_0807C290(D_08000C38);
            if (D_0200C4A2 == 1)
            {
                switch (sel = D_0200C4A0)
                {
                case 0:
                    state = 0x8100;
                    break;
                case 1:
                    state = 0x8200;
                    break;
                case 2:
                    state = 0x8300;
                    break;
                }
            }
            else
            {
                func_0808A8B4(1);
                func_0808A86C(2);
                state = 0x10;
            }
            break;
        case 0x8100:
            func_08079544(0x10, 0);
            func_0807970C();
            func_080BA104();
            func_08091DB4();
            func_0808AB28();
            func_0807C290(D_08000C04);
            func_08079544(0xF, 0);
            state = 0x8010;
            break;
        case 0x8200:
            func_08079544(0x10, 0);
            func_0807970C();
            func_080C6684();
            func_08088DB0();
            func_08091DB4();
            D_0201F5F8.field_1 = 7;
            func_0808AB28();
            func_0807C290(D_08000C04);
            func_08079544(0xF, 0);
            state = 0x8010;
            break;
        case 0x8300:
            func_08079544(0x10, 0);
            func_0807970C();
            func_080B92E4(0);
            func_08091DB4();
            func_0808AB28();
            func_0807C290(D_08000C04);
            func_08079544(0xF, 0);
            state = 0x8010;
            break;
        case 0x9000:
            func_0808A890(1);
            func_08091C04();
            func_0808A8B4(1);
            state = 0x10;
            break;
        }
    }
}
