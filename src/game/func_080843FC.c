#include "types.h"

struct Cell
{
    u16 cmd;
    u8 pad_2[6];
};

struct Slot
{
    u8 active;
    u8 pad_1[15];
};

struct Script
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[0x234];
    u8 field_236;
    u8 pad_237[0x95];
    struct Cell cells[14][32];
    u8 pad_10CC[0x69];
    u8 field_1135;
    u8 pad_1136[0x76];
    struct Slot slots[16];
    u32 *objs[16];
};

extern struct Script D_0201F6DC;
extern u8 D_02037B6C[][6][0x18];
u8 func_080796EC(void);
s32 func_080A00FC(void);
s32 func_080A1B9C(void);
u8 func_08079724(void);
void func_080A1204(void);
void func_080C8FCC(s32);

void func_080843FC(void)
{
    u32 i, j;
    if (D_0201F6DC.field_1 == 0)
    {
        for (j = 0; j < 14 && D_0201F6DC.cells[j][0].cmd == 0; j++)
            ;
        for (i = 0; i < 16; i++)
        {
            if (D_0201F6DC.objs[i] != 0 && !(*D_0201F6DC.objs[i] & 1))
                D_0201F6DC.objs[i] = 0;
        }
        for (i = 0; i < 16; i++)
        {
            if (D_0201F6DC.objs[i] != 0 && (!(*D_0201F6DC.objs[i] & 4) || D_0201F6DC.slots[i].active != 0))
                break;
        }
    }
    else if (D_0201F6DC.field_1 == 1)
    {
        for (j = 0; j < 12; j++)
        {
            i = j / 6;
            if ((D_02037B6C[i][j % 6][0] & 1) && (D_02037B6C[i][j % 6][0] & 0x1C))
                break;
        }
    }
    if (func_080796EC())
    {
        if ((D_0201F6DC.field_1 == 0 && j == 14 && i == 16 && D_0201F6DC.field_1135 == 0)
            || (D_0201F6DC.field_1 == 1 && j == 12 && func_080A00FC())
            || (D_0201F6DC.field_1 == 2 && func_080A1B9C()))
        {
            if (D_0201F6DC.field_1 == 2 && func_08079724())
                func_080A1204();
            D_0201F6DC.field_236 = 0;
            return;
        }
    }
    D_0201F6DC.field_236 = 1;
    func_080C8FCC(1);
}
