#include "types.h"

extern u16 D_0300000C;
extern u16 D_0300000E;
extern u16 D_030057EC;
extern u16 D_030057EE;
extern s8 D_030057F0;
extern u8 D_03000081;

void func_08079E88(void)
{
    if (D_0300000C == D_030057EE)
    {
        D_030057F0 -= D_03000081;
        if (D_030057F0 <= 0)
        {
            D_030057EC = D_0300000C;
            D_030057F0 = 8;
        }
        else
        {
            D_030057EC = 0;
        }
    }
    else
    {
        D_030057EE = D_0300000C;
        D_030057EC = D_0300000E;
        D_030057F0 = 16;
    }
}
