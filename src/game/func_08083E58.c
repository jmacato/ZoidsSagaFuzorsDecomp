#include "types.h"

struct Script
{
    u8 field_0;
    u8 field_1;
};

struct Map2
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[0xA];
    u8 field_C;
};

struct Battle
{
    u8 pad_0[0x14];
    s32 field_14;
    s32 field_18;
    s32 field_1C;
    u8 pad_20[0x40];
    s32 field_60;
};

extern struct Script D_0201F6DC;
extern struct Map2 D_02020E3C;
extern struct Battle D_030025A8;
void func_08089C5C(void);
void func_080A0358(void);
void func_080A3370(void);
void func_080832D8(void);
void func_08082F84(void);
void func_080A0244(u8);
void func_0809FCD4(s32, s32, s32, s32);
void func_080BE58C(u8);
void func_08083C5C(u8, s32, s32);

s32 func_08083E58(u8 id, u8 **pc)
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
    D_0201F6DC.field_1 = 1;
    func_080832D8();
    func_08082F84();
    func_080A0244((*pc)[1]);
    D_02020E3C.field_1 = (*pc)[1];
    D_02020E3C.field_C = 0;
    D_030025A8.field_14 = 0x78;
    D_030025A8.field_18 = 0x58;
    D_030025A8.field_1C = 0x80;
    D_030025A8.field_60 = 0x20000;
    func_0809FCD4(0, 0, 0, 1);
    for (i = 0; i < 2; i++)
        func_080BE58C(i);
    func_08083C5C(id, -1, 0);
    return 0;
}
