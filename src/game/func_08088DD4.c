#include "types.h"

struct Sprite
{
    u8 pad_0[0xE];
    s16 field_E;
};

struct Actor
{
    u8 flags;
    u8 kind;
    u8 id;
    u8 field_3;
    s32 x;
    s32 y;
    u8 pad_C[0xA];
    u8 dir;
    u8 pad_17[3];
    u8 field_1A;
    u8 pad_1B;
    struct Sprite *obj1;
    u8 pad_20[0x24];
};

struct Map
{
    u16 id;
    u8 pad_2[0x68];
    u8 field_6A;
    u8 pad_6B;
    struct Actor actors[14];
    struct Actor *current;
};

struct Save
{
    u8 pad_0[0x10];
    s32 x;
    s32 y;
    u8 pad_18[8];
    u8 kind;
    u8 pad_21;
    u8 dir;
    u8 field_23;
    u16 map;
};

extern struct Save D_02020E4C;
extern struct Map D_020209D8;
extern u16 D_0300000E;
extern u8 D_0200C4A2;
extern u8 D_0200C4A0;
extern const u8 D_08014FDD[];
extern const u8 D_08014B6F[];
extern const u8 D_08014B64[];
extern const u8 D_08015039[];
extern const u8 D_08014B74[];
s32 func_08081F04(u8, s32, s32);
void func_08075F20(u16);
void func_080C8FCC(u32);
void func_0807C290(const u8 *);
void func_0807A1A4(void);
struct Actor *func_08080B00(u8, u8, s32, s32, u8, u8, u8, u32);
void func_08088630(void);
void func_08080CA4(u8);
u8 func_08080C54(u8);

void func_08088DD4(void)
{
    s8 x_lo;
    s8 x_hi;
    s8 y_lo;
    s8 y_hi;
    s8 i;
    s8 j;
    u8 found;
    s32 f;

    if (D_02020E4C.field_23 == 0)
        return;
    if (D_020209D8.id != D_02020E4C.map)
        return;
    if (D_020209D8.current->kind == 0x8A)
    {
        if (!(D_0300000E & 1))
            return;
        D_020209D8.current->flags |= 2;
        x_lo = y_hi = 0;
        x_hi = 0;
        y_lo = 0;
        f = D_020209D8.current->x - D_020209D8.current->x / 4096 * 4096;
        if (f < 0x800)
            x_lo--;
        else if (f > 0x800)
            x_hi++;
        f = D_020209D8.current->y - D_020209D8.current->y / 4096 * 4096;
        if (f < 0x800)
            y_lo--;
        else if (f > 0x800)
            y_hi++;
        found = 0;
        for (i = x_lo; i <= x_hi && !found; i++)
        {
            for (j = y_lo; j <= y_hi && !found; j++)
            {
                if (func_08081F04(0x88, D_020209D8.current->x / 4096 + i, D_020209D8.current->y / 4096 + j))
                    found = 1;
            }
        }
        if (!found)
        {
            for (i = x_lo; i <= x_hi; i++)
            {
                if (func_08081F04(0x88, D_020209D8.current->x / 4096 + i, D_020209D8.current->y / 4096 + y_lo - 1))
                    found |= 1;
                if (func_08081F04(0x88, D_020209D8.current->x / 4096 + i, D_020209D8.current->y / 4096 + y_hi + 1))
                    found |= 2;
            }
            for (j = y_lo; j <= y_hi; j++)
            {
                if (func_08081F04(0x88, D_020209D8.current->x / 4096 + x_lo - 1, D_020209D8.current->y / 4096 + j))
                    found |= 4;
                if (func_08081F04(0x88, D_020209D8.current->x / 4096 + x_hi + 1, D_020209D8.current->y / 4096 + j))
                    found |= 8;
            }
            if (found != 0xF)
                found = 0;
        }
        if (D_020209D8.current->field_1A & 0x40)
            found = 1;
        if (!found)
        {
            func_08075F20(0xE2);
            while (D_020209D8.current->obj1->field_E != 0)
            {
                D_020209D8.current->obj1->field_E++;
                func_080C8FCC(1);
            }
            func_0807C290(D_08014FDD);
            func_0807C290(D_08014B6F);
            func_0807A1A4();
            func_080C8FCC(1);
            if (D_0200C4A2 == 1)
            {
                switch (D_0200C4A0)
                {
                case 0:
                    D_02020E4C.kind = 0x88;
                    break;
                case 1:
                    D_02020E4C.kind = 0x89;
                    break;
                }
                D_020209D8.current->field_3 = 0xFF;
                D_02020E4C.map = D_020209D8.id;
                D_02020E4C.x = D_020209D8.current->x;
                D_02020E4C.y = D_020209D8.current->y;
                D_02020E4C.dir = D_020209D8.current->dir;
                D_020209D8.current = func_08080B00(D_02020E4C.kind, 0, D_02020E4C.x, D_02020E4C.y, D_02020E4C.dir, 0, 0, 0);
                func_08088630();
                D_020209D8.field_6A = 1;
                return;
            }
            func_08075F20(0xE1);
            while (D_020209D8.current->obj1->field_E > -16)
            {
                D_020209D8.current->obj1->field_E--;
                func_080C8FCC(1);
            }
            D_020209D8.current->flags &= ~2;
        }
        else
        {
            func_08075F20(0x114);
            func_0807C290(D_08014B64);
            func_0807C290(D_08015039);
            func_0807C290(D_08014B74);
            func_0807A1A4();
            D_020209D8.current->flags &= ~2;
        }
        return;
    }
    if (D_020209D8.current->kind == 1)
        return;
    if (D_02020E4C.x - D_020209D8.current->x >= -0xFFF && D_02020E4C.x - D_020209D8.current->x <= 0xFFF
        && D_02020E4C.y - D_020209D8.current->y > -0x1000 && D_02020E4C.y - D_020209D8.current->y <= 0xFFF)
    {
        if (D_020209D8.field_6A != 0)
            return;
        func_08080CA4(0);
        D_02020E4C.kind = 0x8A;
        D_020209D8.current = &D_020209D8.actors[func_08080C54(0xD)];
        D_020209D8.current->field_3 = 0;
        func_08075F20(0xE1);
        while (D_020209D8.current->obj1->field_E > -16)
        {
            D_020209D8.current->obj1->field_E--;
            func_080C8FCC(1);
        }
        D_020209D8.current->flags &= ~2;
        return;
    }
    D_020209D8.field_6A = 0;
}
