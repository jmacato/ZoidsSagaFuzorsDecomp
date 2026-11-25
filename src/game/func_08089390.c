#include "types.h"

struct Zoid
{
    u8 id;
    u8 pad_1;
    u8 pilot;
    u8 pad_3;
    u16 flags;
    u8 pad_6[0x8E];
};

struct Save
{
    u8 pad_0[0x3C];
    struct Zoid zoids[186];
    u8 pad_6BC4[0xEA6];
    u8 team[6];
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
    u16 id;
    u8 pad_2[2];
    s32 x;
    s32 y;
    u8 pad_C[0x418];
    struct Actor *current;
};

struct Cam
{
    s32 x;
    s32 y;
};

extern struct Save D_02020E4C;
extern struct Map D_020209D8;
extern struct Cam D_03000060;
extern s16 D_03005718;
extern s16 D_0300571A;
extern const u8 D_08014B64[];
extern const u8 D_0801505D[];
extern const u8 D_08014B74[];
extern const u8 D_080150B8[];
void func_0807970C(void);
void func_08075F20(s32);
void func_0807C290(const u8 *);
void func_0807A1A4(void);
void func_08079544(s32, s32);
void func_080892C8(void);
void func_08089C5C(void);
void func_08091DB4(void);
void func_0809104C(void);
void func_08082F84(void);
void func_0808889C(u16, s32, s32);
void func_08080C20(void);

s32 func_08089390(void)
{
    u8 i;
    for (i = 1; i < 0xBA; i++)
    {
        if (D_02020E4C.zoids[i].id != 0 && !(D_02020E4C.zoids[i].flags & 2) && D_02020E4C.zoids[i].pilot != 0)
            break;
    }
    if (i == 0xBA)
    {
        D_020209D8.current->flags |= 2;
        func_0807970C();
        func_08075F20(0x114);
        func_0807C290(D_08014B64);
        func_0807C290(D_0801505D);
        func_0807C290(D_08014B74);
        func_0807A1A4();
        D_03005718 = (D_020209D8.current->x - D_03000060.x) / 256;
        D_0300571A = (D_020209D8.current->y - D_03000060.y) / 256;
        func_08079544(6, 0);
        func_0807970C();
        func_080892C8();
        return 1;
    }
    for (i = 0; i < 6 && D_02020E4C.team[i] == 0; i++)
        ;
    if (i == 6)
    {
        D_020209D8.current->flags |= 2;
        func_0807970C();
        func_08075F20(0x114);
        func_0807C290(D_08014B64);
        func_0807C290(D_080150B8);
        func_0807C290(D_08014B74);
        func_0807A1A4();
        func_08079544(0x10, 0);
        func_0807970C();
        func_08089C5C();
        func_08091DB4();
        func_08079544(0xF, 0);
        func_0809104C();
        func_08079544(0x10, 0);
        func_0807970C();
        func_08082F84();
        func_0808889C(D_020209D8.id, D_020209D8.x, D_020209D8.y);
        func_08080C20();
        func_08079544(0xF, 0);
        D_020209D8.current->flags &= ~2;
    }
    return 0;
}
