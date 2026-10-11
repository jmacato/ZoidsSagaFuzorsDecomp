#include "types.h"

struct Obj
{
    u32 flags;
};

struct State
{
    u8 pad_0[0x98];
    u8 mirror;
    u8 pad_99[0x80B];
    u8 mode;
    u8 pad_8A5[3];
    s32 field_8A8;
    u8 pad_8AC[0x25];
    u8 fadeLoaded;
    u8 fadeActive;
    u8 fadeStep;
    u8 pad_8D4[0x20];
    u8 field_8F4;
    u8 field_8F5;
    u8 pad_8F6[0x66];
    struct Obj **field_95C;
    struct Obj *field_960;
};

struct Display
{
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_C;
    s32 field_10;
    s32 field_14;
};

struct Save
{
    u8 field_0;
    u8 pad_1[0x10F3];
    u8 field_10F4;
};

extern struct State D_02036E7C;
extern u16 D_0300004C;
extern u16 D_0300004E;
extern struct Display D_03000060;
extern struct Save D_0201F6DC;
extern const u8 D_08005566[];
extern const u8 D_0800557C[];

void func_08079EF4(u8 a, u8 b, u16 c, u16 d, u16 e, u8 f, u8 g, u8 h, u16 i, u8 j);
void func_08076FA0(void);
void func_0807C290(const u8 *script);
void func_0807FC64(u8 a, u8 b, u8 c, u8 d, u8 e);
void func_080A12B0(u8 mode, s32 arg);
void func_080A1E2C(void);
void func_080A2424(void);
void func_08075DA8(u8 id, void (*fn)(void));
void func_080A3158(void);

void func_080A31D0(u8 a, u8 b, u8 mirror, u8 mode, struct Obj **obj)
{
    D_0300004C = 0x1D40;
    D_0300004E = 0x4086;
    D_03000060.field_14 = 0;
    D_03000060.field_4 = 0;
    func_08079EF4(3, 0, 0x100, 0xC0, 0x1C0, 3, 0xE, 0, 0x366, 0xD);
    func_08076FA0();
    if (D_0201F6DC.field_0 == 0 || D_0201F6DC.field_10F4 == 0)
    {
        if (mirror == 0)
            func_0807C290(D_08005566);
        else
            func_0807C290(D_0800557C);
    }
    D_02036E7C.field_8F5 = a;
    D_02036E7C.mirror = mirror;
    func_0807FC64(a, b, 3, 2, 1);
    D_02036E7C.mode = 0;
    if (mode == 2)
    {
        D_02036E7C.field_8A8 = -0x10000;
        func_080A12B0(2, 0);
    }
    else
    {
        D_02036E7C.field_8A8 = 0x1000;
        func_080A12B0(mode, 0);
    }
    D_02036E7C.field_8F4 = 0;
    func_080A1E2C();
    func_080A2424();
    D_02036E7C.field_95C = obj;
    D_02036E7C.field_960 = 0;
    D_02036E7C.fadeStep = 0;
    D_02036E7C.fadeActive = 0;
    D_02036E7C.fadeLoaded = 0;
    func_08075DA8(3, func_080A3158);
}
