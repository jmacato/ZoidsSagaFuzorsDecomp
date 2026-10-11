#include "types.h"

struct State
{
    u8 id;
    u8 field_1;
    u8 field_2;
};

struct Reward
{
    u8 pad0[0x104];
    u8 entries[5][3];
    u8 pad113;
};

struct Cursor
{
    u16 x;
    u16 y;
};

extern struct State D_02030ACC;
extern struct Reward D_087A0DF8[][5];
struct Big
{
    u8 pad0[0xE7C];
    struct Cursor cursor;
};

extern struct Big D_02009480;
extern u8 D_0200C4D8;
extern u8 D_0200C4D4;
extern u8 D_0200C4BC;
extern u8 D_0200C4C0;
extern const u8 D_08014A68[];
extern const u8 D_08014A8A[];
extern const u8 D_08014AAC[];
extern const u8 D_08014ACC[];
extern const u8 D_08014AEC[];
extern const u8 D_08014B0A[];
extern vu16 D_0300000E;

u32 func_0807F234(u8);
u32 func_0807F1D0(u8, u8);
u32 func_0807F18C(u8);
u32 func_0807EE90(u8, u8);
void func_08075EE0(u32);
void func_0807BAD4(u8, u8, u8, u8, u8, u8);
void func_0807C290(const u8 *);
void func_0807A1A4(void);
void func_0807970C(void);
void func_080C8FCC(u32);
void func_08075F00(void);
void func_08075F20(u32);
void func_0807BD8C(u8);
void func_0807560C(void);
u8 func_0807DA64(void);
u8 func_0807DAB0(void);
void func_080755F4(void);

void func_080BAF2C(void)
{
    struct Reward *r = &D_087A0DF8[D_02030ACC.id][D_02030ACC.field_2];
    u8 got[5];
    u8 n = 0;
    u8 i;

    for (i = 0; i < 5; i++)
    {
        got[i] = 0;
        if (r->entries[i][0] != 0)
        {
            switch (r->entries[i][0])
            {
            case 1:
                if (func_0807F234(r->entries[i][1]))
                    got[i] = 1;
                break;
            case 2:
                if (func_0807F1D0(r->entries[i][1], 1))
                    got[i] = 1;
                break;
            case 3:
                if (func_0807F18C(r->entries[i][1]))
                    got[i] = 1;
                break;
            case 4:
                if (func_0807EE90(r->entries[i][1], r->entries[i][2]))
                    got[i] = 1;
                break;
            }
            if (got[i])
                n++;
        }
    }
    if (n == 0)
        return;
    func_08075EE0(0x67);
    n = n * 2 + 2;
    func_0807BAD4(3, 0, (16 - n) / 2, 30, n, 0);
    for (i = 0; i < 5; i++)
    {
        if (got[i])
        {
            switch (r->entries[i][0])
            {
            case 1:
                D_0200C4D8 = r->entries[i][1];
                func_0807C290(D_08014A68);
                {
                    u16 col = 0;
                    D_02009480.cursor.x = col;
                    D_02009480.cursor.y += 2;
                }
                break;
            case 2:
                D_0200C4D4 = r->entries[i][1];
                func_0807C290(D_08014A8A);
                {
                    u16 col = 0;
                    D_02009480.cursor.x = col;
                    D_02009480.cursor.y += 2;
                }
                break;
            case 3:
                D_0200C4BC = r->entries[i][1];
                func_0807C290(D_08014AAC);
                {
                    u16 col = 0;
                    D_02009480.cursor.x = col;
                    D_02009480.cursor.y += 2;
                }
                break;
            case 4:
                D_0200C4C0 = r->entries[i][1];
                func_0807C290(D_08014ACC);
                {
                    u16 col = 0;
                    D_02009480.cursor.x = col;
                    D_02009480.cursor.y += 2;
                }
                break;
            }
        }
    }
    func_0807C290(D_08014AEC);
    func_0807A1A4();
    func_0807970C();
    do
        func_080C8FCC(1);
    while (!(D_0300000E & 3));
    func_08075F00();
    func_08075F20(0xCD);
    func_0807BD8C(3);
    func_0807560C();
    if (!func_0807DA64() || !func_0807DAB0())
    {
        func_080755F4();
        func_08075F20(0x114);
        func_0807C290(D_08014B0A);
    }
    else
        func_080755F4();
}
