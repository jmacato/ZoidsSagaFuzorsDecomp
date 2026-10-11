#include "types.h"

extern u8 D_0203198A;
extern u8 D_02031988;
extern u8 D_02031989;
extern u8 D_03000080;
extern s32 D_03000060[];
extern s16 D_02031488[2][320];
extern u8 D_030058B4[];

void func_08076F30(u8);
void func_08076EE0(u8, void (*)(void));

void func_0807DC5C(u8 swap)
{
    u8 i;

    if (swap)
    {
        switch (D_0203198A)
        {
        case 2:
            *(vu16 *)0x04000208 = 0;
            func_08076F30(1);
            D_03000080 &= ~4;
            *(vu16 *)0x04000208 = 1;
            return;
        case 1:
            *(vu16 *)0x04000208 = 0;
            func_08076EE0(1, (void (*)(void))D_030058B4);
            *(vu16 *)0x04000208 = 1;
            D_0203198A = 0;
            break;
        }
        D_02031988 ^= 1;
    }
    if (D_0203198A == 0)
    {
        for (i = 0; i < 4; i++)
        {
            if ((D_02031989 >> i) & 1)
            {
                D_03000060[i * 2] = D_02031488[D_02031988][0] << 8;
                D_03000060[i * 2 + 1] = D_02031488[D_02031988][1] << 8;
            }
        }
    }
}
