#include "types.h"

struct Slot
{
    u8 flags;
    u8 pad_1[3];
    void *field_4;
    void *field_8;
    u8 pad_C[0xC];
};

extern struct Slot D_02037B6C[][6];

void func_080771F4(void *p);

void func_0809F724(u8 side, u8 slot)
{
    struct Slot *s = &D_02037B6C[side][slot];
    if (s->flags & 1)
    {
        func_080771F4(s->field_4);
        func_080771F4(s->field_8);
        s->flags = 0;
    }
}
