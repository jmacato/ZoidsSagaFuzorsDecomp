#include "types.h"

struct Script
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[0x10F2];
    u8 field_10F4;
};

struct Battle
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 pad_4[8];
    u8 field_C;
    u8 field_D;
    u8 field_E;
};

extern struct Script D_0201F6DC;
extern struct Battle D_02020E3C;
extern u8 D_02030584;
void func_08075EC4(void);
void func_08075F20(s32);
s32 func_08075F5C(s32);
void func_08079544(s32, s32);
u8 func_080796EC(void);
void func_080C8FCC(s32);
void func_08089C5C(void);
void func_080A0358(void);
void func_080A3370(void);
u8 func_08099664(void);
void func_0807F060(void);
void func_080892C8(void);
void func_08083C5C(u8, s32, s32);

s32 func_08083F78(u8 id, u8 **pc)
{
    D_0201F6DC.field_0 = 1;
    func_08075EC4();
    func_08075F20(0xE4);
    if (D_0201F6DC.field_1 == 1)
        func_08079544(2, 0x24);
    else
        func_08079544(8, 0);
    while (!func_080796EC() || !func_08075F5C(0xE4))
        func_080C8FCC(1);
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
    D_02020E3C.field_0 = 0;
    D_02020E3C.field_2 = (*pc)[1];
    D_02020E3C.field_3 = (*pc)[2];
    D_02020E3C.field_1 = (*pc)[3];
    D_02020E3C.field_D = (*pc)[4];
    D_02020E3C.field_C = D_02030584 & 1;
    D_02020E3C.field_E = 0;
    D_0201F6DC.field_10F4 = 0;
    switch (func_08099664())
    {
    case 1:
    case 4:
        func_08083C5C(id, -1, 0);
        return 0;
    case 2:
        func_0807F060();
        func_080892C8();
        return 2;
    }
}
