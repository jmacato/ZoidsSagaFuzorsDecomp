#include "m2c.h"

extern struct { u8 pad_0[0x7B49]; s8 f_7B49; s8 f_7B4A; s8 f_7B4B; s8 f_7B4C; } D_02020E4C;

void func_080B7978(void)
{
    D_02020E4C.f_7B4A = 0;
    D_02020E4C.f_7B49 = 0;
    D_02020E4C.f_7B4C = 0;
    D_02020E4C.f_7B4B = 0;
}
