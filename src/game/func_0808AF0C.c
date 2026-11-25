#include "types.h"

struct Pilot
{
    u8 id;
    u8 pad_1[2];
    u8 flags;
    u8 pad_4[0x3C];
};

extern u8 D_02030C5A;
extern u8 D_02030C26[];
extern struct Pilot D_02027A10[];
void func_0807BE64(u8);
u8 *func_08082E70(u8);
void func_0807BEF4(u8, u8 *, u8);

void func_0808AF0C(u8 id, u32 mode, u8 sel)
{
    u8 i, state;
    struct Pilot *p;
    func_0807BE64(id);
    for (i = 0; i < D_02030C5A; i++)
    {
        p = &D_02027A10[D_02030C26[i]];
        if (((mode & 1) && (p->flags & 2)) || (sel != 0 && p->id == sel))
            state = 4;
        else if (p->flags & 1)
            state = 1;
        else if (p->id == 1)
            state = 2;
        else
            state = 0;
        func_0807BEF4(id, func_08082E70(p->id), state);
    }
}
