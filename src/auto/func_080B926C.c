#include "m2c.h"

s32 func_080771BC(M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32, s32);
M2C_UNK func_0807C290(M2C_UNK);
M2C_UNK func_0808A7F8(s32, s32, s32, s32);
M2C_UNK func_080B9154();

void func_080B926C(void)
{
    func_0807C290(0x08005895);
    *(s32 *)0x02030A40 = func_080771BC(0x080C9748, 0x080C977C, 0, 0x20, 0, 0x3F4, 0xF, 0x20, 0);
    func_0808A7F8(0, 1, 0xD8, 0x98);
    func_080B9154();
}
