#include "m2c.h"

M2C_UNK func_0807C290(M2C_UNK);

void func_0808F850(u8 *arg0)
{
    u8 temp_r0;

    if (M2C_FIELD(arg0, s16 *, 0x10) == 0)
    {
        temp_r0 = M2C_FIELD(arg0, u8 *, 7);
        if (temp_r0 == 7)
        {
            func_0807C290(0x08002F1A);
            return;
        }
        if (temp_r0 == 0)
        {
            func_0807C290(0x08002F8A);
            return;
        }
        func_0807C290(0x08003001);
        return;
    }
    func_0807C290(0x08003071);
}
