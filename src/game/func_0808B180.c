#include "types.h"

extern u8 D_0203116B;
extern u8 D_020310A3[][2];
extern u8 D_0203198C[];
extern u8 D_020319CC[];
void func_0807BE64(u8);
void func_0808B10C(u8, u8, s32, u8 *, u8 *);
void func_0807BEF4(u8, u8 *, s32);

void func_0808B180(u8 id)
{
    u8 i;
    func_0807BE64(id);
    for (i = 0; i < D_0203116B; i++)
    {
        func_0808B10C(D_020310A3[i][0], D_020310A3[i][1], 10, D_0203198C, D_020319CC);
        func_0807BEF4(id, D_0203198C, 0);
    }
}
