#include "types.h"

u8 func_0807B7A8(u8 type, u8 *buf, u8 pos, u8 flags)
{
    switch (type)
    {
    case 0:
        if (!(flags & 0x10))
            ((u16 *)buf)[pos] = 0x7D81;
        else
            buf[pos] = 0x2B;
        break;
    case 1:
        if (!(flags & 0x10))
            ((u16 *)buf)[pos] = 0x7B81;
        else
            buf[pos] = 0x2B;
        break;
    case 2:
        if (!(flags & 0x10))
            ((u16 *)buf)[pos] = 0x7C81;
        else
            buf[pos] = 0x2D;
        break;
    }
    pos++;
    return pos;
}
