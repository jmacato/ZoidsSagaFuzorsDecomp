#include "types.h"

struct Cell
{
    u16 cmd;
    u16 arg0;
    u16 arg1;
    u16 arg2;
};

struct Script
{
    u8 pad_0[0x2CC];
    u16 cells[14][32][4];
};

extern struct Script D_0201F6DC;
u8 func_08080C54(u8);
void func_08083C5C(u8, s32, s32);

s32 func_08085548(u8 id, u8 **pc)
{
    u8 slot = func_08080C54((*pc)[1]);
    u32 j;
    if (slot != 0xFF)
    {
        for (j = 0; j < 32 && D_0201F6DC.cells[slot][j][0] != 0; j++)
            ;
        if (j != 32)
        {
            D_0201F6DC.cells[slot][j][0] = (*pc)[0];
            if ((*pc)[0] >= 0x3C && (*pc)[0] <= 0x3E)
            {
                D_0201F6DC.cells[slot][j][1] = ((*pc)[3] << 8) | (*pc)[2];
                D_0201F6DC.cells[slot][j][2] = ((*pc)[5] << 8) | (*pc)[4];
                D_0201F6DC.cells[slot][j][3] = (*pc)[6];
            }
            else if ((*pc)[0] == 0x38)
            {
                D_0201F6DC.cells[slot][j][1] = (*pc)[2];
                D_0201F6DC.cells[slot][j][2] = ((*pc)[4] << 8) | (*pc)[3];
            }
            else
            {
                D_0201F6DC.cells[slot][j][1] = (*pc)[2];
                D_0201F6DC.cells[slot][j][2] = (*pc)[3];
                D_0201F6DC.cells[slot][j][3] = (*pc)[4];
            }
        }
    }
    func_08083C5C(id, -1, 0);
    return 0;
}
