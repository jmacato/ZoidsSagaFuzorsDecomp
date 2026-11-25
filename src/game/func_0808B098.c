#include "types.h"

extern u8 D_020310A2;
extern u16 D_02030F92[];
extern u8 *D_087A43E0[];
extern const u8 D_080F3688[];
void func_0807BE64(u8);
void func_0807BEF4(u8, const u8 *, s32);

void func_0808B098(u8 id)
{
    u8 i;
    func_0807BE64(id);
    for (i = 0; i < D_020310A2; i++)
    {
        if (!(D_02030F92[i] & 0x8000))
            func_0807BEF4(id, D_087A43E0[D_02030F92[i]], 0);
        else
            func_0807BEF4(id, D_080F3688, 0);
    }
}
