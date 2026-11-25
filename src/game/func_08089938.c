#include "types.h"

struct Actor
{
    u8 flags;
    u8 kind;
    u8 pad_2[2];
    s32 x;
    s32 y;
    u8 pad_C[0xA];
    u8 dir;
    u8 pad_17[2];
    u8 warp;
    u8 field_1A;
};

struct Map
{
    u16 id;
    u8 pad_2[2];
    s32 x;
    s32 y;
    u8 pad_C[0xC];
    u8 mode;
    u8 pad_19[0x51];
    u8 field_6A;
    u8 pad_6B[0x3B9];
    struct Actor *current;
};

struct Cam
{
    s32 x;
    s32 y;
};

struct Save
{
    u8 pad_0[0x18];
    s32 x;
    s32 y;
};

struct Battle
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[2];
    u32 field_4;
    u8 pad_8[4];
    u8 field_C;
    u8 field_D;
    u8 field_E;
};

extern struct Map D_020209D8;
extern u16 D_0877F8A4[][25][3];
extern s16 D_03005718;
extern s16 D_0300571A;
extern struct Cam D_03000060;
extern struct Save D_02020E4C;
extern struct Battle D_02020E3C;
extern u8 D_02030584;
extern u8 D_0201F5F8;
extern u16 D_0300000E;
extern const u8 D_08014B64[];
extern const u8 D_080150F5[];
extern const u8 D_08014B74[];
void func_08088D98(u16, s32, s32, s32);
void func_0807970C(void);
void func_08079544(s32, s32);
void func_08075F20(u16);
u8 func_080886B0(void);
void func_08075EC4(void);
u8 func_080796EC(void);
s32 func_08075F5C(u16);
void func_080C8FCC(u32);
void func_08089C5C(void);
u8 func_08099664(void);
void func_08082F84(void);
void func_0808889C(u16, s32, s32);
void func_08080C20(void);
void func_08088DB0(void);
void func_08088630(void);
void func_08088DD4(void);
s32 func_08091E48(void);
void func_08092B60(s32);
void func_0807C290(const u8 *);
void func_0807A1A4(void);

s32 func_08089938(void)
{
    u16 *w;
    u8 found;

    if (D_020209D8.current->kind != 0x8A && (D_020209D8.current->warp & 0x40))
    {
        w = D_0877F8A4[D_020209D8.id][D_020209D8.current->warp & 0x3F];
        if (w[0] == 0 && w[1] == 0 && w[2] == 0)
            return 0;
        func_08088D98(w[0], w[1] << 11, w[2] << 11, D_020209D8.current->dir);
        D_03005718 = (D_020209D8.current->x - D_03000060.x) / 256;
        D_0300571A = (D_020209D8.current->y - D_03000060.y) / 256;
        D_020209D8.current->flags |= 2;
        func_0807970C();
        func_08079544(14, 0);
        func_08075F20(0xCF);
        func_0807970C();
        return 1;
    }
    found = func_080886B0();
    if (found)
    {
        D_020209D8.current->flags |= 2;
        func_08075EC4();
        func_08075F20(0xE4);
        func_08079544(8, 0);
        while (!func_080796EC() || !func_08075F5C(0xE4))
            func_080C8FCC(1);
        func_08089C5C();
        D_02020E3C.field_0 = 0;
        D_02020E3C.field_1 = D_020209D8.current->field_1A & 0x1F;
        D_02020E3C.field_D = 0;
        D_02020E3C.field_C = D_02030584 & 1;
        D_02020E3C.field_4 = 0;
        D_02020E3C.field_E = 0;
        switch (func_08099664())
        {
        case 2:
            return 1;
        case 1:
        case 4:
            func_08082F84();
            func_0808889C(D_020209D8.id, D_020209D8.x, D_020209D8.y);
            func_08080C20();
            func_08088DB0();
            func_08079544(7, 0);
            func_0807970C();
            D_020209D8.current->flags &= ~2;
            func_08088630();
            D_020209D8.field_6A = 1;
            break;
        }
        return 0;
    }
    func_08088DD4();
    if (func_080796EC() && (D_0300000E & 8))
    {
        func_08075F20(0xCD);
        if (D_020209D8.mode != 0)
        {
            D_02020E4C.x = D_020209D8.current->x;
            D_02020E4C.y = D_020209D8.current->y;
        }
        D_020209D8.current->flags |= 2;
        func_08079544(0x10, 0);
        func_0807970C();
        func_08089C5C();
        D_0201F5F8 = 0;
        if (func_08091E48())
            return 1;
        func_08082F84();
        func_0808889C(D_020209D8.id, D_020209D8.x, D_020209D8.y);
        func_08080C20();
        func_08079544(0xF, 0);
        D_020209D8.current->flags &= ~2;
    }
    else if (func_080796EC() && (D_0300000E & 0x104))
    {
        func_08075F20(0xCD);
        D_020209D8.current->flags |= 2;
        if (D_020209D8.id >= 0xA8 && D_020209D8.id <= 0xAB)
        {
            func_08075F20(0x114);
            func_0807C290(D_08014B64);
            func_0807C290(D_080150F5);
            func_0807C290(D_08014B74);
            func_0807A1A4();
        }
        else
        {
            if (D_020209D8.mode != 0)
            {
                D_02020E4C.x = D_020209D8.current->x;
                D_02020E4C.y = D_020209D8.current->y;
            }
            func_08079544(0x10, 0);
            func_0807970C();
            func_08089C5C();
            func_08092B60(0);
            func_08082F84();
            func_0808889C(D_020209D8.id, D_020209D8.x, D_020209D8.y);
            func_08080C20();
            func_08079544(0xF, 0);
        }
        D_020209D8.current->flags &= ~2;
    }
    return 0;
}
