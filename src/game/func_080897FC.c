#include "types.h"

struct MapInfo
{
    u8 pad_0[0x1C];
    u8 field_1C;
    u8 pad_1D[7];
};

struct Save
{
    u8 pad_0[4];
    u16 map;
    u8 pad_6[2];
    s32 x;
    s32 y;
    s32 x2;
    s32 y2;
    u8 pad_18[8];
    u8 field_20;
    u8 field_21;
    u8 field_22;
    u8 field_23;
    u16 field_24;
};

struct Actor
{
    u8 flags;
    u8 pad_1[3];
    s32 x;
    s32 y;
};

struct Map
{
    u8 pad_0[0x424];
    struct Actor *current;
};

struct Cam
{
    s32 x;
    s32 y;
};

extern struct MapInfo D_0877E074[];
extern struct Save D_02020E4C;
extern struct Map D_020209D8;
extern struct Cam D_03000060;
extern s16 D_03005718;
extern s16 D_0300571A;
extern u8 D_03005714;
u8 func_08089524(u16, u8, s32 *, s32 *);
void func_08082F84(void);
void func_0808889C(u16, s32, s32);
void func_08080C20(void);
struct Actor *func_08080B00(u8, u8, s32, s32, u8, u8, u8, u32);
void func_08079544(s32, s32);
void func_08088DB0(void);

void func_080897FC(void)
{
    u8 k;
    if (D_0877E074[D_02020E4C.map].field_1C == 0)
        k = 1;
    else
        k = D_02020E4C.field_20;
    if (func_08089524(D_02020E4C.map, k, &D_02020E4C.x, &D_02020E4C.y))
    {
        func_08082F84();
        func_0808889C(D_02020E4C.map, D_02020E4C.x, D_02020E4C.y);
        func_08080C20();
    }
    D_020209D8.current = func_08080B00(k, k == 0x8A ? 0xD : 0, D_02020E4C.x, D_02020E4C.y, D_02020E4C.field_21, 0, 0, 0);
    D_03005718 = (D_020209D8.current->x - D_03000060.x) / 256;
    D_0300571A = (D_020209D8.current->y - D_03000060.y) / 256;
    if (D_03005714 == 6)
        func_08079544(5, 0);
    else
        func_08079544(0xD, 0);
    if (D_02020E4C.field_23 != 0 && D_02020E4C.map == D_02020E4C.field_24 && D_02020E4C.field_20 != 0x8A)
    {
        func_08089524(D_02020E4C.map, 0x8A, &D_02020E4C.x2, &D_02020E4C.y2);
        func_08080B00(0x8A, 0xD, D_02020E4C.x2, D_02020E4C.y2, D_02020E4C.field_22, 2, 0xFF, 0);
    }
    func_08088DB0();
}
