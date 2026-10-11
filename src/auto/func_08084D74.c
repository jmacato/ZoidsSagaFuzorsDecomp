#include "m2c.h"

M2C_UNK func_0808330C(u8, u8, u8);
M2C_UNK func_08083C5C(u8, s32, s32);

s32 func_08084D74(u8 arg0, u8 **arg1)
{
    u8 *temp_r2;

    temp_r2 = *arg1;
    func_0808330C(M2C_FIELD(temp_r2, u8 *, 1), M2C_FIELD(temp_r2, u8 *, 2), M2C_FIELD(temp_r2, u8 *, 3));
    func_08083C5C(arg0, -1, 0);
    return 0;
}
