#include "types.h"

s32 func_08081E80(u8 id, u16 kind)
{
    switch (kind & 0x1F)
    {
    case 4:
    case 6:
    case 7:
    case 9:
        if (id >= 0x88 && id <= 0x89)
            return 1;
        return 0;
    case 8:
    case 10:
        if (id == 0x88)
            return 1;
        return 0;
    case 11:
        if (id >= 0x88 && id <= 0x89)
            return 1;
        return 0;
    case 0:
    case 1:
    case 2:
    case 3:
    case 5:
    case 12:
    default:
        return 0;
    }
}
