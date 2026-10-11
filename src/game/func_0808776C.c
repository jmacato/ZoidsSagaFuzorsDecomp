#include "types.h"

struct Script
{
    u8 field_0;
    u8 field_1;
};

struct Pilot
{
    u8 flag;
    u8 pad_1[7];
};

struct Save
{
    u32 flags;
    u16 map;
    u8 pad_6[2];
    s32 x;
    s32 y;
    s32 x2;
    s32 y2;
    u8 pad_18[9];
    u8 field_21;
    u8 field_22;
    u8 field_23;
    u16 field_24;
    u16 field_26;
    u8 pad_28[0x7A48];
    struct Pilot pilots[14];
};

extern struct Script D_0201F6DC;
extern struct Save D_02020E4C;
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern const u8 D_08015167[];
extern const u8 D_080151BC[];
extern const u8 D_080151C0[];
extern const u8 D_08015216[];
extern const u8 D_08015236[];
void func_08089C5C(void);
void func_080A0358(void);
void func_080A3370(void);
void func_08091DB4(void);
void func_0807C290(const u8 *);
void func_0807A1A4(void);
void func_08079544(s32, s32);
void func_0807970C(void);
void func_0807560C(void);
u8 func_0807DA64(void);
u8 func_0807DAB0(void);
void func_080755F4(void);
void func_08075F20(s32);
void func_08083C5C(u8, s32, s32);

s32 func_0808776C(u8 id)
{
    u8 i;
    D_0201F6DC.field_0 = 1;
    switch (D_0201F6DC.field_1)
    {
    case 0:
        func_08089C5C();
        break;
    case 1:
        func_080A0358();
        break;
    case 2:
        func_080A3370();
        break;
    }
    D_0201F6DC.field_1 = 0xFF;
    D_02020E4C.map = 4;
    D_02020E4C.x = 0xF000;
    D_02020E4C.y = 0x13800;
    D_02020E4C.x2 = 0x64000;
    D_02020E4C.y2 = 0x6D000;
    D_02020E4C.field_21 = 4;
    D_02020E4C.field_22 = 6;
    D_02020E4C.field_24 = 0;
    D_02020E4C.field_26 = 0xFFFF;
    for (i = 0; i < 14; i++)
        D_02020E4C.pilots[i].flag = 0;
    func_08091DB4();
    func_0807C290(D_08015167);
    func_0807A1A4();
    func_08079544(0xF, 0);
    func_0807970C();
    for (;;)
    {
        func_0807C290(D_080151BC);
        if (D_0200C4A0 == 0)
        {
            D_02020E4C.flags |= 1;
            func_0807560C();
            if (func_0807DA64() && func_0807DAB0())
            {
                func_080755F4();
                func_0807C290(D_08015216);
                break;
            }
            func_080755F4();
            func_08075F20(0x114);
            func_0807C290(D_08015236);
        }
        else
        {
            func_0807C290(D_080151C0);
            if (D_0200C4A2 == 1 && D_0200C4A0 == 0)
                break;
        }
    }
    func_08079544(0x10, 0);
    func_0807970C();
    func_08083C5C(id, -1, 0);
    return 0;
}
