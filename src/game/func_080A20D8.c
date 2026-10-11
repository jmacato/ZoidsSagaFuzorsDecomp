#include "types.h"

struct State
{
    u8 pad_0[0x8C5];
    u8 field_8C5;
    u8 field_8C6;
    u8 pad_8C7;
    s16 field_8C8;
    s16 field_8CA;
};

struct Display
{
    u8 pad_0[0xC];
    s32 field_C;
};

extern struct State D_02036E7C;
extern u8 D_03000080;
extern struct Display D_03000060;
extern u16 D_0300004C;
extern u16 D_03000050;
extern u16 D_03000052;

void func_080A1E6C(void);

void func_080A20D8(void)
{
    D_02036E7C.field_8C6 = 2;
    D_02036E7C.field_8C8 = -16;
    D_02036E7C.field_8CA = 0;
    D_03000080 |= 8;
    D_03000060.field_C = 0;
    D_0300004C |= 0x200;
    D_03000050 = D_03000052;
    D_02036E7C.field_8C5 = 1;
    func_080A1E6C();
}
