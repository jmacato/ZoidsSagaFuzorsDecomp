#include "types.h"

struct State
{
    u8 pad_0[0x83];
    u8 field_83;
    u8 field_84;
};

extern struct State D_02030A40;

s32 func_080B8480(void)
{
    if (D_02030A40.field_83 == 5 && D_02030A40.field_84 != 0xFF)
        return 1;
    return 0;
}
