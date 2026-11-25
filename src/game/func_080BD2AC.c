#include "types.h"

extern u8 D_0873F9F4[][0x26];

u8 func_080BD2AC(u8 id, u8 row)
{
    u8 i;
    for (i = 0; D_0873F9F4[row][i] != 0; )
    {
        if (D_0873F9F4[row][i] == id)
            return 1;
        i++;
        if (i > 0x25)
            break;
    }
    return 0;
}
