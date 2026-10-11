#include "types.h"

struct Mgr
{
    u8 pad_0[0x58];
    void *objs[1];
};

extern struct Mgr D_0201F5F8;
extern const u8 D_087352B4[];
extern const u16 D_0873533C[];
void func_0808A86C(u8);
void *func_08077180(const u8 *, u8, u8, s16, s16, u16, u8, u8, u8);

void func_0808A7F8(u8 slot, u8 kind, u16 x, u16 y)
{
    if (D_0201F5F8.objs[slot] != 0)
        func_0808A86C(slot);
    D_0201F5F8.objs[slot] = func_08077180(D_087352B4, kind, 0, x, y, D_0873533C[kind], 15, 0x20, 0);
}
