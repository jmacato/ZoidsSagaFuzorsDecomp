#include "types.h"

struct Win
{
    u8 pad0[0xA];
    u16 height;
    u16 field_C;
    s16 field_E;
    u8 pad10[3];
    u8 id;
    u8 top;
};

extern u8 D_0200C624[];
extern u8 D_0200C62E[][0x1E5A];

void func_0807B048(struct Win *, u8 *);

void func_0807BE80(struct Win *win)
{
    if (D_0200C624[win->id] >= win->top && D_0200C624[win->id] < (win->height - 2) / 2 + win->top)
    {
        if (win->field_E == 0 && (win->height & 1))
            win->field_E = 1;
        func_0807B048(win, &D_0200C62E[win->id][D_0200C624[win->id] * 0x25]);
        win->field_C = 0;
        win->field_E += 2;
    }
}
