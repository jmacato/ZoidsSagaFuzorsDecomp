#include "types.h"

struct Map
{
    u8 pad_0[0x18];
    u8 mode;
    u8 flags;
    u8 pad_1A[0x42];
    s32 field_5C;
    s32 field_60;
    s32 field_64;
};

struct Cam
{
    s32 x;
    s32 y;
    s32 field_8;
    s32 field_C;
    s32 field_10;
    s32 field_14;
};

extern struct Map D_020209D8;
extern struct Cam D_03000060;
extern u16 D_0300004C;
void func_08080CF8(void);
void func_08088068(void);
void func_08087E68(void);

void func_080882A0(void)
{
    func_08080CF8();
    func_08088068();
    if (D_020209D8.mode != 0)
    {
        if (D_020209D8.flags & 1)
        {
            D_020209D8.field_5C -= 0x40;
            D_020209D8.field_60 += 0x30;
            D_03000060.field_8 = D_03000060.x + D_020209D8.field_5C;
            D_03000060.field_C = D_03000060.y + D_020209D8.field_60;
            D_0300004C |= 0x200;
        }
        else
            D_0300004C &= ~0x200;
        D_020209D8.field_64 += 0x10;
        D_03000060.field_10 = D_03000060.x;
        D_03000060.field_14 = D_03000060.y + D_020209D8.field_64;
        func_08087E68();
    }
}
