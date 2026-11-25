#include "types.h"

struct Save
{
    u8 pad0[4];
    u16 field_4;
    u8 pad6[0x1A];
    u8 field_20;
    u8 pad21[5];
    u16 field_26;
    u8 pad28[0x7B08];
    u8 field_7B30[6][3];
};

extern struct Save D_02020E4C;

void func_080C8B7C(const void *, void *, u32);
u32 func_0807ECD8(u8, u8, u8, u8);
void func_080BDE24(u8, u8);
void func_0807F318(u8);
u32 func_0807F2D4(u32);

void func_0807EB78(void)
{
    u32 zero = 0;
    u8 i, j;

    func_080C8B7C(&zero, &D_02020E4C, 0x05001ED7);
    func_080BDE24(func_0807ECD8(0x59, 0, 1, 1), 1);
    func_0807F318(0x94);
    func_0807F2D4(1000);
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 3; j++)
            D_02020E4C.field_7B30[i][j] |= 0xFF;
    }
    D_02020E4C.field_20 = 0x88;
    D_02020E4C.field_4 = 25;
    D_02020E4C.field_26 = 0xFFFF;
}
