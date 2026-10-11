#include "types.h"

struct Slot
{
    u8 active;
    u8 pad_1[15];
};

struct Script
{
    u8 pad_0[0x11AC];
    struct Slot slots[16];
    void *objs[16];
};

extern struct Script D_0201F6DC;
void func_080771F4(void *);

void func_0808329C(u8 id)
{
    if (D_0201F6DC.objs[id] != 0)
    {
        func_080771F4(D_0201F6DC.objs[id]);
        D_0201F6DC.objs[id] = 0;
        D_0201F6DC.slots[id].active = 0;
    }
}
