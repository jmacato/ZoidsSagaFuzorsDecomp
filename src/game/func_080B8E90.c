#include "types.h"

struct State
{
    u8 pad_0[0x64];
    u32 *field_64;
    u32 *field_68;
    u32 *field_6C;
    void *field_70;
    void *field_74;
    void *field_78;
};

struct Lists
{
    u16 field_0;
    u16 list[9];
};

void func_0807C290(const void *);
void func_080B870C(u16 *, u8, u8, u8);
void *func_080771BC(const void *, const void *, u16, s16, s16, u16, u16, u32, u32);
void func_0807FEDC(u8, u8, u16, u8);
void func_0807970C(void);
void func_080C8FCC(s32);
u8 func_080B88DC(void);
void func_080C8F78(u16 *, const void *);
void func_080B84A8(void);
void func_0807A1A4(void);
void func_080B8E40(void);
void func_080771F4(void *);

extern struct State D_02030A40;
extern struct Lists D_02030584;
extern const void *const D_087A464C[];
extern u8 D_0200C4A2;
extern u8 D_0200C4A0;
extern const u8 D_08005C3D[];
extern const u8 D_08005C73[];
extern const u8 D_08005C6A[];
extern const u8 D_080F20C0[];
extern const u8 D_080F20FC[];
extern const u8 D_085ECCF0[];
extern const u8 D_085ECCFC[];

void func_080B8E90(u8 flag)
{
    func_0807C290(D_08005C3D);
    func_080B870C(D_02030584.list, 8, 3, 12);
    D_02030A40.field_70 = func_080771BC(D_080F20C0, D_080F20FC, 0, 0x60, 0x38, 0xB, 0xF, 8, 0);
    D_02030A40.field_74 = func_080771BC(D_080F20C0, D_080F20FC, 4, 0xA0, 0x38, 0xB, 0xF, 8, 0);
    func_0807FEDC(1, 0, 0x3C2, 0xE);
    D_02030A40.field_78 = func_080771BC(D_085ECCF0, D_085ECCFC, 0, 8, 8, 0x3C2, 0xE, 8, 0);
    if (flag)
        func_0807970C();
    for (;;)
    {
        do
        {
            func_080C8FCC(1);
        } while (func_080B88DC() == 0);
        *D_02030A40.field_64 |= 0x20000;
        *D_02030A40.field_68 |= 0x20000;
        *D_02030A40.field_6C |= 0x20000;
        if (D_02030584.list[0] == 0)
        {
            func_080C8F78(D_02030584.list, D_087A464C[1]);
            func_080B84A8();
        }
        func_0807C290(D_08005C73);
        func_0807A1A4();
        if (D_0200C4A2 != 1 || D_0200C4A0 != 0)
            *D_02030A40.field_64 &= ~0x20000;
        else
            break;
    }
    if (!flag)
    {
        func_0807C290(D_08005C6A);
        func_080B8E40();
        func_080771F4(D_02030A40.field_70);
        func_080771F4(D_02030A40.field_74);
        func_080771F4(D_02030A40.field_78);
    }
}
