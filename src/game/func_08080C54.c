#include "types.h"

struct Actor
{
    u8 flags;
    u8 pad_1;
    u8 id;
    u8 pad_3[0x41];
};

extern struct Actor D_02020A44[14];

u8 func_08080C54(u8 id)
{
    u8 i;
    for (i = 0; i < 14; i++)
    {
        if ((D_02020A44[i].flags & 1) && D_02020A44[i].id == id)
            break;
    }
    if (i < 14)
        return i;
    return 0xFF;
}
