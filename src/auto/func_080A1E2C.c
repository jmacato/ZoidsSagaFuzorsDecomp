#include "m2c.h"

extern struct { u8 pad_0[0x8C5]; s8 f_8C5; s8 f_8C6; } D_02036E7C;
extern struct { s8 f_0; } D_020378E0;

M2C_UNK func_080C8B7C(M2C_UNK, M2C_UNK, M2C_UNK);

void func_080A1E2C(void)
{
    D_02036E7C.f_8C5 = 0;
    D_02036E7C.f_8C6 = 0;
    D_020378E0.f_0 = 0;
    func_080C8B7C(0x08032634, 0x03005814, 0x04000028);
}
