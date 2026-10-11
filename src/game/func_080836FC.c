#include "types.h"

struct Cell
{
    u16 field_0;
    u8 pad_2[6];
};

struct Script
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[2];
    u32 regs[0x46];
    u32 pcs[0x46];
    u16 field_234;
    u8 field_236;
    u8 field_237[0x46];
    u8 pad_27D[7];
    u8 field_284[0x46];
    u8 pad_2CA[2];
    struct Cell cells[14][32];
    u16 field_10CC[14];
    u8 pad_10E8[0x4D];
    u8 field_1135;
};

extern struct Script D_0201F6DC;
void func_080832D8(void);
void func_08082F84(void);

void func_080836FC(void)
{
    u32 i, j;
    D_0201F6DC.field_0 = 0;
    D_0201F6DC.field_1 = 0;
    for (i = 0; i < 0x46; i++)
        D_0201F6DC.regs[i] = 0;
    func_080832D8();
    for (i = 0; i < 14; i++)
    {
        for (j = 0; j < 32; j++)
            D_0201F6DC.cells[i][j].field_0 = 0;
        D_0201F6DC.field_10CC[i] = 0;
    }
    D_0201F6DC.field_1135 = 0;
    D_0201F6DC.field_236 = 0;
    for (i = 0; i < 0x46; i++)
    {
        D_0201F6DC.field_284[i] = 1;
        D_0201F6DC.field_237[i] = 0;
    }
    func_08082F84();
}
