#include "types.h"

struct Zoid
{
    u8 pad_0[0x4];
    u16 flags;
    s16 hp;
    u8 pad_8[0x5A];
    s16 max_hp;
    u8 pad_64[0x30];
};

struct Ctx
{
    u8 field_0;
    u8 field_1;
};

void func_08091DB4(void);
void func_080B4D48(void);
void func_08079544(s32, s32);
void func_080B4DB4(void);
void func_0808A7F8(u8, u8, u8, u8);
void func_0807C290(const void *);
void func_0807970C(void);
void func_0808A86C(u8);
void func_0808A3F0(u8);
void func_080B4DE8(void);
void func_080B5468(u8);
void func_08075F20(u16);
void func_080B72E0(void);
void func_08089CE0(u8, u8);
void func_080B5B88(void);
void func_080B5E00(void);

extern struct Ctx D_0201F5F8;
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern u8 D_020310A2;
extern u8 D_02030C25;
extern struct Zoid D_02020E88[];
extern const u8 D_080062E7[];
extern const u8 D_080062DA[];
extern const u8 D_0800630F[];
extern const u8 D_08006349[];
extern const u8 D_08006383[];
extern const u8 D_080063AF[];
extern const u8 D_080063ED[];

void func_080B7708(void)
{
    s32 state;
    u8 done;
    u8 healed;
    u8 i;

    func_08091DB4();
    func_080B4D48();
    func_08079544(0xF, 0);
    D_0201F5F8.field_1 = 0;
    state = 0;
    done = 0;
    while (!done)
    {
        switch (state)
        {
        case 0:
            func_080B4DB4();
            state = 0x1000;
            break;
        case 0x1000:
            func_0808A7F8(0, 1, 0xD8, 0x98);
            func_0807C290(D_080062E7);
            func_0807970C();
            func_0807C290(D_080062DA);
            D_0201F5F8.field_1 = D_0200C4A0;
            if (D_0200C4A2 == 1)
            {
                switch (D_0200C4A0)
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
                case 4:
                    state = 0x1500;
                    break;
                }
                func_0808A86C(0);
            }
            else
            {
                state = 0x2000;
            }
            break;
        case 0x1100:
            func_0808A3F0(6);
            if (D_020310A2 != 0)
            {
                func_080B4DE8();
                func_080B5468(0);
                state = 0;
            }
            else
            {
                func_08075F20(0x114);
                func_0807C290(D_0800630F);
                state = 0x1000;
            }
            break;
        case 0x1200:
            func_0808A3F0(5);
            if (D_020310A2 != 0)
            {
                func_080B4DE8();
                func_080B5468(1);
                state = 0;
            }
            else
            {
                func_08075F20(0x114);
                func_0807C290(D_08006349);
                state = 0x1000;
            }
            break;
        case 0x1300:
            func_080B72E0();
            state = 0x1000;
            break;
        case 0x1400:
            func_08089CE0(2, 0);
            if (D_02030C25 != 0)
            {
                func_080B5B88();
            }
            else
            {
                func_08075F20(0x114);
                func_0807C290(D_08006383);
            }
            state = 0x1000;
            break;
        case 0x1500:
            func_080B4DE8();
            func_080B5E00();
            state = 0;
            break;
        case 0x2000:
            healed = 0;
            for (i = 1; i < 186; i++)
            {
                if (!((D_02020E88 + i)->flags & 2) && (D_02020E88 + i)->hp < (D_02020E88 + i)->max_hp)
                {
                    (D_02020E88 + i)->hp = (D_02020E88 + i)->max_hp;
                    healed = 1;
                }
            }
            if (healed)
                func_0807C290(D_080063AF);
            func_0807C290(D_080063ED);
            done = 1;
            break;
        }
    }
    func_08079544(0x10, 0);
    func_0807970C();
}
