#include "m2c.h"

extern struct { u8 pad_0[0x7B4D]; s8 f_7B4D; s16 f_7B4E; s16 f_7B50; s16 f_7B52; } D_02020E4C;

M2C_UNK func_08083C5C(u8, s32, s32);
M2C_UNK func_080872F4();

s32 func_08087694(u8 arg0, u8 **arg1)
{
    u8 *temp_r0;
    u8 *temp_r0_2;
    u8 *temp_r0_3;

    D_02020E4C.f_7B4D = M2C_FIELD(*arg1, u8 *, 1) + 1;
    temp_r0 = *arg1;
    D_02020E4C.f_7B4E = M2C_FIELD(temp_r0, u8 *, 2) | (M2C_FIELD(temp_r0, u8 *, 3) << 8);
    temp_r0_2 = *arg1;
    D_02020E4C.f_7B50 = M2C_FIELD(temp_r0_2, u8 *, 4) | (M2C_FIELD(temp_r0_2, u8 *, 5) << 8);
    temp_r0_3 = *arg1;
    D_02020E4C.f_7B52 = M2C_FIELD(temp_r0_3, u8 *, 6) | (M2C_FIELD(temp_r0_3, u8 *, 7) << 8);
    func_080872F4();
    func_08083C5C(arg0, -1, 0);
    return 0;
}
