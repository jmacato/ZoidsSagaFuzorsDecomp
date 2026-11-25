#include "types.h"

struct Unit
{
    u8 id;
    u8 pad[0x107];
};

struct Group
{
    struct Unit units[7];
};

struct Data
{
    u8 pad0[0x258];
    struct Group groups[1];
};

extern struct Data D_02031A0C;

u8 func_080C40B8(u8 g, u8 id)
{
    u8 i;
    for (i = 0; i < 6; i++)
    {
        if (D_02031A0C.groups[g].units[i].id == id)
            return i;
    }
    return 0xFF;
}
