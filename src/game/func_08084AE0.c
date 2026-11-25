#include "types.h"

extern u8 D_0201F960[];
extern u8 D_08734D3C[][2];
void func_08082EF4(u8);
void func_0807F420(u8);
void func_08083C5C(u8, s32, s32);

s32 func_08084AE0(u8 id, u8 **pc)
{
    u8 i;
    func_08082EF4((*pc)[1]);
    for (i = 0; i < 0x46; i++)
        D_0201F960[i] = 1;
    for (i = 0; D_08734D3C[i][0] != 0; i++)
    {
        if ((*pc)[1] == D_08734D3C[i][0])
            func_0807F420(D_08734D3C[i][1]);
    }
    func_08083C5C(id, -1, 0);
    return 0;
}
