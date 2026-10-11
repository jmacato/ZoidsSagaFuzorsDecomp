#include "types.h"

struct Obj
{
    u8 pad_0[0x10];
    s16 field_10;
    s16 field_12;
    u8 pad_14[0x1C];
    s32 field_30;
    s32 field_34;
};

struct Demo
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 pad_3;
    struct Obj *objs[2][6];
    u8 flags[2][6];
    u16 pal[16];
};

struct Pos
{
    s16 x;
    s16 y;
};

extern struct Demo D_02030AE8;
extern const s16 D_0873FC98[2][6][2];
extern const u8 D_080284F4[];
extern const u8 D_083F21E4[];
extern const u8 D_08424594[];
extern const u8 D_084245A0[];

void func_08091DB4(void);
void func_0807C290(const u8 *);
void func_0807A1A4(void);
void func_0807FB7C(u8 set, u8 id, u16 tile, u8 palette);
void func_080C8B88(const void *src, void *dest);
struct Obj *func_080771BC(const u8 *, const u8 *, u16, s16, s16, u16, u16, u32, void (*)(struct Obj *));
void func_080C5B6C(struct Obj *);
void func_08079544(s32, s32);
void func_0807970C(void);
void func_080C8FCC(s32);

void func_080C5D44(void)
{
    u8 i;
    u8 j;

    func_08091DB4();
    func_0807C290(D_080284F4);
    func_0807A1A4();

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 6; j++)
        {
            D_02030AE8.flags[i][j] = 0;
            func_0807FB7C(1, 0, 0, i * 6 + j);
        }
    }

    func_080C8B88(D_083F21E4, D_02030AE8.pal);

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 6; j++)
        {
            D_02030AE8.objs[i][j] = func_080771BC(D_08424594, D_084245A0, 0, D_0873FC98[i][j][0], D_0873FC98[i][j][1], 0, i * 6 + j, i ? 0x8048 : 0x48, func_080C5B6C);
            D_02030AE8.objs[i][j]->field_10 = D_02030AE8.objs[i][j]->field_12 = 0xA0;
            D_02030AE8.objs[i][j]->field_30 = i;
            D_02030AE8.objs[i][j]->field_34 = j;
        }
    }

    func_08079544(0xF, 0);
    func_0807970C();

    for (;;)
        func_080C8FCC(1);
}
