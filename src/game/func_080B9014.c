#include "types.h"

struct State
{
    u8 pad_0[0x64];
    u32 *field_64;
    u32 *field_68;
    u32 *field_6C;
    void *field_70;
    void *field_74;
};

void func_0807C290(const void *);
void func_080B870C(u16 *, u8, u8, u8);
void *func_080771BC(const void *, const void *, u16, s16, s16, u16, u16, u32, u32);
void func_080C8FCC(s32);
u8 func_080B88DC(void);
void func_080C8F78(u16 *, const void *);
void func_080B84A8(void);
void func_0807A1A4(void);
void func_080B8E40(void);
void func_080771F4(void *);

extern struct State D_02030A40;
struct Lists
{
    u16 field_0;
    u16 list[9];
    u16 lists[8][23];
};

extern struct Lists D_02030584;
extern const void *const D_08734AF8[];
extern u8 D_0200C4A2;
extern u8 D_0200C4A0;
extern const u8 D_08005CA4[];
extern const u8 D_08005CCA[];
extern const u8 D_08005CC3[];
extern const u8 D_080F2810[];
extern const u8 D_080F2828[];

void func_080B9014(u8 idx)
{
    func_0807C290(D_08005CA4);
    func_080B870C(D_02030584.lists[idx], 0x16, 0, 1);
    D_02030A40.field_70 = func_080771BC(D_080F2810, D_080F2828, 0, 8, 0x38, 0xAA, 0xF, 8, 0);
    D_02030A40.field_74 = func_080771BC(D_080F2810, D_080F2828, 1, 0xB8, 0x38, 0xAA, 0xF, 8, 0);
    for (;;)
    {
        do
        {
            func_080C8FCC(1);
        } while (func_080B88DC() == 0);
        *D_02030A40.field_64 |= 0x20000;
        *D_02030A40.field_68 |= 0x20000;
        *D_02030A40.field_6C |= 0x20000;
        if (D_02030584.lists[idx][0] == 0)
        {
            func_080C8F78(D_02030584.lists[idx], D_08734AF8[idx]);
            func_080B84A8();
        }
        func_0807C290(D_08005CCA);
        func_0807A1A4();
        if (D_0200C4A2 != 1 || D_0200C4A0 != 0)
            *D_02030A40.field_64 &= ~0x20000;
        else
            break;
    }
    func_0807C290(D_08005CC3);
    func_080B8E40();
    func_080771F4(D_02030A40.field_70);
    func_080771F4(D_02030A40.field_74);
}
