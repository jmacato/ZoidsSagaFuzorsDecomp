#include "types.h"

extern u8 D_02030F90;
extern u8 D_02030F7E[][2];
extern u8 D_0203198C[];
extern u8 D_020319CC[];
void func_0807BE64(u8);
void func_0808AFB4(u8, u8, s32, u8 *, u8 *);
void func_0807BEF4(u8, u8 *, s32);

void func_0808B028(u8 id)
{
    u8 i;
    func_0807BE64(id);
    for (i = 0; i < D_02030F90; i++)
    {
        func_0808AFB4(D_02030F7E[i][0], D_02030F7E[i][1], 10, D_0203198C, D_020319CC);
        func_0807BEF4(id, D_0203198C, 0);
    }
}
