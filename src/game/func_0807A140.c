#include "types.h"

struct Window
{
    u32 flags;
    u8 pad4[0xF];
    u8 id;
};

extern struct Window *D_0200C4FC[10];

void func_0807A140(u8 id)
{
    u8 i, j;
    struct Window *win;

    for (i = 0; i < 10; i++)
    {
        if (D_0200C4FC[i]->id == id)
            break;
    }
    win = D_0200C4FC[i];
    for (j = i; j < 9; j++)
        D_0200C4FC[j] = D_0200C4FC[j + 1];
    D_0200C4FC[9] = win;
    win->flags |= 2;
}
