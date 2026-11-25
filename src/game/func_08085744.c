#include "types.h"

extern u16 D_020209D8;
void func_08082F84(void);
void func_0808889C(u16, s32, s32);
void func_08080C20(void);
void func_08083C5C(u8, s32, s32);

s32 func_08085744(u8 id, u8 **pc)
{
    func_08082F84();
    func_0808889C(D_020209D8, ((*pc)[1] | ((*pc)[2] << 8)) << 11, ((*pc)[3] | ((*pc)[4] << 8)) << 11);
    func_08080C20();
    func_08083C5C(id, -1, 0);
    return 0;
}
