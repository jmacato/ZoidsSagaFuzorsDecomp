#include "types.h"

struct Window
{
    u32 flags;
    u8 pad4[0xF];
    u8 id;
};

extern struct Window *D_0200C4FC[10];

void func_0807A0C8(u8 id)
{
    u8 i, j;
    struct Window *win;

    for (i = 0; i < 10; i++)
    {
        if (D_0200C4FC[i]->id == id)
            break;
    }
    if (!(D_0200C4FC[i]->flags & 0x200))
    {
        win = D_0200C4FC[i];
        for (j = i; j != 0; j--)
            D_0200C4FC[j] = D_0200C4FC[j - 1];
        D_0200C4FC[0] = win;
        win->flags |= 2;
    }
    else
    {
        D_0200C4FC[i]->flags |= 2;
    }
}
