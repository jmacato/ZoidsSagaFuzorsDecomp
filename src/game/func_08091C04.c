#include "types.h"

struct Obj
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    s32 x;
    s32 y;
    u8 pad_C[0xA];
    u8 field_16;
    u8 pad_17[0x2D];
};

struct Saved
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    s16 x;
    s16 y;
};

struct Save
{
    u32 flags;
    u16 field_4;
    u8 pad_6[2];
    s32 x;
    s32 y;
    u8 pad_10[0x11];
    u8 field_21;
    u8 pad_22[0x7A70 - 0x22];
    struct Saved objs[14];
};

struct World
{
    u16 field_0;
    u8 pad_2[0x6A];
    struct Obj objs[14];
    struct Obj *player;
};

extern struct Save D_02020E4C;
extern struct World D_020209D8;
extern u8 D_0201F6DC;
extern u8 D_0201F5F4;
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern const s32 D_08734B24[][2];
extern const u8 D_08003C40[];
extern const u8 D_08003B10[];
extern const u8 D_08003B33[];
extern const u8 D_08003B91[];
extern const u8 D_08003BB0[];
extern const u8 D_08003BB3[];
extern const u8 D_08003BD5[];
void func_08075F20(u32);
void func_0807C290(const u8 *);
void func_0807560C(void);
void func_080755F4(void);
u8 func_0807DA64(void);
u8 func_0807DAB0(void);
u8 func_0807DAFC(void);

void func_08091C04(void)
{
    u8 i;

    if (D_0201F6DC == 0 && !(D_02020E4C.flags & 2))
    {
        func_0807C290(D_08003B10);
        if (D_0200C4A2 != 1 || D_0200C4A0 != 0)
            return;
        if (D_0201F5F4 != 0)
        {
            func_0807C290(D_08003B33);
            if (D_0200C4A2 == 2 || D_0200C4A0 == 1)
                return;
        }
        func_0807C290(D_08003B91);
        D_02020E4C.field_4 = D_020209D8.field_0;
        D_02020E4C.x = D_020209D8.player->x;
        D_02020E4C.y = D_020209D8.player->y;
        D_02020E4C.field_21 = D_020209D8.player->field_16;
        for (i = 0; i < 14; i++)
        {
            struct Obj *src = &D_020209D8.objs[i];
            struct Saved *dst = &D_02020E4C.objs[i];

            dst->field_0 = src->field_0;
            dst->field_1 = src->field_1;
            dst->field_2 = (src->field_2 << 4) | src->field_16;
            dst->field_3 = src->field_3;
            if (src->field_3 != 4)
            {
                dst->x = src->x / 256;
                dst->y = src->y / 256;
            }
            else
            {
                dst->x = (src->x - D_08734B24[src->field_16][0] * 16) / 256;
                dst->y = (src->y - D_08734B24[src->field_16][1] * 16) / 256;
            }
        }
        func_0807560C();
        if (func_0807DA64() && func_0807DAB0() && func_0807DAFC())
        {
            func_080755F4();
            func_08075F20(0xC9);
            func_0807C290(D_08003BB0);
            func_0807C290(D_08003BB3);
            D_0201F5F4 = 1;
        }
        else
        {
            func_080755F4();
            func_08075F20(0x114);
            func_0807C290(D_08003BB0);
            func_0807C290(D_08003BD5);
        }
    }
    else
    {
        func_08075F20(0x114);
        func_0807C290(D_08003C40);
    }
}
