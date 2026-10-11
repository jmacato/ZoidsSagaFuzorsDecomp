#include "types.h"

struct Script
{
    u8 pad_0[0x10E8];
    u8 field_10E8;
    u8 pad_10E9[3];
    u32 field_10EC;
    u32 field_10F0;
    u8 pad_10F4;
    u8 field_10F5;
};

extern struct Script D_0201F6DC;

void func_080832D8(void)
{
    D_0201F6DC.field_10E8 = 0;
    D_0201F6DC.field_10EC = D_0201F6DC.field_10F0 = 0;
    D_0201F6DC.field_10F5 = 0;
}
