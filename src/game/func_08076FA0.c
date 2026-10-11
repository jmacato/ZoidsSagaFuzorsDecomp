#include "types.h"

struct Unk030031C8
{
    u32 field_0;
    u8 pad4[0x3C];
};

struct Unk03002688
{
    u32 field_0;
    u8 pad4[0xB0];
};

extern struct Unk030031C8 D_030031C8[];
extern struct Unk03002688 D_03002688[];

void func_08076FA0(void)
{
    u8 i;

    for (i = 0; i < 128; i++)
        D_030031C8[i].field_0 = 0;
    for (i = 0; i < 16; i++)
        D_03002688[i].field_0 = 0;
}
