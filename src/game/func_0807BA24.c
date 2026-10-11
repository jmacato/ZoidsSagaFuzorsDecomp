#include "types.h"

struct Win
{
    u8 pad0[0xC];
    u16 x;
    u16 y;
    u8 pad10[2];
    u8 field_12;
    u8 pad13[0x4BD];
};

extern struct Win D_02009480[];
extern u8 D_0201F5D6[];

void func_0807B830(u32, u8, u8);
void func_0807B048(struct Win *, void *);
void func_0807A0C8(u8);

void func_0807BA24(u32 a0, u8 a1, u8 a2, u8 a3, u8 id, u16 x, u16 y)
{
    struct Win *win;
    u8 *buf = D_0201F5D6;

    func_0807B830(a0, a1, a3);
    win = &D_02009480[id];
    win->x = x;
    win->y = y;
    win->field_12 = a2;
    func_0807B048(win, buf);
    func_0807A0C8(id);
}
