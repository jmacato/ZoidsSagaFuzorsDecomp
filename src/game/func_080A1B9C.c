#include "types.h"
struct State { u8 pad_0[0x8A4]; u8 field_8A4; };
extern struct State D_02036E7C;
s32 func_080A1B9C(void)
{
s32 r = 0; if ((D_02036E7C.field_8A4 & 0x80) || D_02036E7C.field_8A4 == 0 || D_02036E7C.field_8A4 == 1) r = 1; return r;
}
