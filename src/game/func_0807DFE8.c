#include "types.h"

struct Sprite
{
    u32 flags;
    s32 x;
    s32 y;
    u8 padC[0x24];
    s32 field_30;
    s32 field_34;
    s32 field_38;
    s32 field_3C;
};

struct Intro
{
    struct Sprite *logo[4];
    u8 pad10[4];
    struct Sprite *stars[32];
};

extern struct Intro D_020309AC;
extern const u8 D_080F0460[];
extern const u8 D_080F049C[];
extern const u8 D_087B14E8[];

struct Sprite *func_080771BC(const void *, const void *, u16, s16, s16, u16, u16, u32, u32);
struct Sprite *func_08077180(const void *, u16, u16, s16, s16, u16, u16, u32, void (*)(struct Sprite *));
void func_0807DED0(struct Sprite *);
void func_080C8FCC(u32);
void func_08075F20(u16);
u8 func_080796EC(void);
void func_08079544(u8, u8);
void func_0807970C(void);

void func_0807DFE8(void)
{
    u32 i, j;
    struct Sprite *star;

    D_020309AC.logo[0] = func_080771BC(D_080F0460, D_080F049C, 1, 120, -44, 0, 0, 0x108, 0);
    D_020309AC.logo[1] = func_080771BC(D_080F0460, D_080F049C, 2, 120, 156, 0, 0, 0x108, 0);
    D_020309AC.logo[2] = func_080771BC(D_080F0460, D_080F049C, 3, 0, 56, 0, 0, 0x108, 0);
    D_020309AC.logo[3] = func_080771BC(D_080F0460, D_080F049C, 4, 240, 56, 0, 0, 0x108, 0);
    for (i = 0; i < 15; i++)
    {
        D_020309AC.logo[2]->x += 0x800;
        D_020309AC.logo[3]->x -= 0x800;
        func_080C8FCC(1);
    }
    func_08075F20(0xD8);
    for (i = 0; i < 32; i++)
    {
        star = func_08077180(D_087B14E8, 9, 0, 120, 80, 0x3A4, 15, 0, func_0807DED0);
        D_020309AC.stars[i] = star;
        star->field_30 = star->field_34 = 0;
        star->field_38 = 0x8000;
        star->field_3C = i * 8;
    }
    while (D_020309AC.stars[0]->flags & 1)
        func_080C8FCC(1);
    for (i = 0; i < 32; i++)
        D_020309AC.stars[i] = 0;
    while (D_020309AC.logo[0]->y <= 0x37FF)
    {
        D_020309AC.logo[0]->y += 0x400;
        func_080C8FCC(1);
    }
    func_08075F20(0xDF);
    while (D_020309AC.logo[1]->y > 0x3800)
    {
        D_020309AC.logo[1]->y -= 0x400;
        func_080C8FCC(1);
    }
    func_08075F20(0xDF);
    for (i = 0; i < 30; i++)
        func_080C8FCC(1);
    if (func_080796EC())
        func_08079544(4, 30);
    for (i = 0; i < 30; i++)
    {
        if (i < 24)
        {
            for (j = 0; j < 4; j++)
                D_020309AC.logo[j]->y -= 0x200;
        }
        func_080C8FCC(1);
    }
    func_0807970C();
}
