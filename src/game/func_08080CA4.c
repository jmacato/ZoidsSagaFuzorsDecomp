#include "types.h"

struct Actor
{
    u8 flags;
    u8 pad_1;
    u8 id;
    u8 pad_3[0x19];
    void *obj1;
    void *obj2;
    u8 pad_24[0x20];
};

struct Actors
{
    struct Actor actors[14];
    struct Actor *current;
};

extern struct Actors D_02020A44;
u8 func_08080C54(u8);
void func_080771F4(void *);

void func_08080CA4(u8 id)
{
    struct Actor *a;
    u8 slot = func_08080C54(id);
    if (slot != 0xFF)
    {
        a = &D_02020A44.actors[slot];
        if (a->obj1 != 0)
            func_080771F4(a->obj1);
        if (a->obj2 != 0)
            func_080771F4(a->obj2);
        a->flags &= ~1;
        if (a == D_02020A44.current)
            D_02020A44.current = 0;
    }
}
