#include "types.h"

struct Slot
{
    u8 active;
    u8 pad_1[15];
};

struct Script
{
    u8 pad_0[0x1144];
    u8 field_1144;
    u8 pad_1145[0x61];
    u16 field_11A6;
    u16 field_11A8;
    u8 pad_11AA[2];
    struct Slot slots[16];
    void *objs[16];
};

extern struct Script D_0201F6DC;

void func_08082F84(void)
{
    u8 i;
    D_0201F6DC.field_1144 = 0;
    D_0201F6DC.field_11A6 = 0x350;
    D_0201F6DC.field_11A8 = 10;
    for (i = 0; i < 16; i++)
    {
        D_0201F6DC.objs[i] = 0;
        D_0201F6DC.slots[i].active = 0;
    }
}
