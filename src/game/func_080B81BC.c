#include "types.h"

struct Entry
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[2];
    u8 field_4;
    u8 field_5;
    u8 pad_6[2];
    u32 field_8;
    u8 field_C;
    u8 field_D;
    u8 pad_E[2];
};

struct Game
{
    u8 pad_0[0x7B49];
    u8 field_7B49;
    u8 field_7B4A;
};

void func_0807C290(const void *);
void func_080B7A60(u8, const struct Entry *, u8);
void func_08075EE0(u16);
void func_08075F00(void);
void func_0807F2D4(u32);
void func_0807F0C4(u8, u8);
void func_0807F128(u8, u8);
void func_0807F18C(u8);
void func_0807F1D0(u8, u8);
void func_0807F234(u8);
void func_080B7978(void);

extern struct Game D_02020E4C;
extern const struct Entry D_0877C7FC[][10];
extern const u8 D_08007313[];
extern const u8 D_080072D3[];
extern const u8 D_080071ED[];
extern const u8 D_08007328[];

void func_080B81BC(void)
{
    const struct Entry *e = &D_0877C7FC[D_02020E4C.field_7B49][D_02020E4C.field_7B4A];

    func_0807C290(D_08007313);
    func_080B7A60(5, e, 0);
    func_08075EE0(0x67);
    func_0807C290(D_080072D3);
    func_08075F00();
    func_0807C290(D_080071ED);
    func_0807F2D4(e->field_8);
    switch (e->field_C)
    {
    case 1:
        func_0807F0C4(e->field_D, 1);
        break;
    case 2:
        func_0807F128(e->field_D, 1);
        break;
    case 3:
        func_0807F18C(e->field_D);
        break;
    case 4:
        func_0807F1D0(e->field_D, 1);
        break;
    case 5:
        func_0807F234(e->field_D);
        break;
    }
    func_080B7978();
    func_0807C290(D_08007328);
}
