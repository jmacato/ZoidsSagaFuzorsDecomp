#include "types.h"

struct Entry
{
    u8 id;
    u8 pad_1[0x3F];
};

extern struct Entry D_02027A10[];

struct Entry *func_080C5EF0(u8 id)
{
    u8 i;

    for (i = 0; i < 0x35; i++)
    {
        if (D_02027A10[i].id == id)
            return &D_02027A10[i];
    }
    return 0;
}
