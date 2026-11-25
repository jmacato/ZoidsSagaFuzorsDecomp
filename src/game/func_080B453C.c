#include "types.h"

struct Unit
{
    u8 pad_0[0x6];
    u16 field_6;
    u8 pad_8[0x4C8];
};

struct Ctx
{
    u8 pad_0[0x8C];
    s32 field_8C;
    s32 field_90;
};

void func_080B4390(s8, s32);
s32 func_080771BC(const void *, const void *, s16, s16, s16, u16, u16, u32, u32);

extern struct Unit D_02009480[];
extern struct Ctx D_0201F5F8;
extern u16 D_0201F5CC;
extern u16 D_0201F5CE;
extern const u8 D_080C93C8[];
extern const u8 D_080C93F0[];
extern const u8 D_080C9470[];
extern const u8 D_080C9498[];

void func_080B453C(u8 a, u8 b, s32 c)
{
    func_080B4390(2, c);
    D_0201F5F8.field_8C = func_080771BC(D_080C93C8, D_080C93F0, 0, 0, (D_02009480[a].field_6 + b + 1) * 8 - 4, D_0201F5CC, D_0201F5CE, 0x30, 0);
    D_0201F5F8.field_90 = func_080771BC(D_080C9470, D_080C9498, 0, 0, (D_02009480[a].field_6 + b + 2) * 8 + 4, D_0201F5CC + 2, D_0201F5CE, 0x30, 0);
}
