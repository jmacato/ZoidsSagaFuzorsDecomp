#include "types.h"

struct Event
{
    u8 side;
    u8 slot;
    u8 id;
    u8 pad_3;
    s16 prio;
    u16 pad_6;
};

struct Game
{
    u8 field_0;
    u8 side;
    u8 count;
    u8 cursor;
    struct Event events[1];
};

extern struct Game D_02031A0C;

void func_0809AC04(u8 side, u8 slot, u8 id, s16 prio)
{
    struct Event ev;
    s8 i;
    ev.side = side;
    ev.slot = slot;
    ev.id = id;
    ev.prio = prio;
    for (i = D_02031A0C.count - 1; i >= 0; i--)
    {
        if (ev.prio > D_02031A0C.events[i].prio || (ev.prio == D_02031A0C.events[i].prio && ev.side != D_02031A0C.events[i].side && ev.side == D_02031A0C.side))
            D_02031A0C.events[i + 1] = D_02031A0C.events[i];
        else
            break;
    }
    D_02031A0C.events[i + 1] = ev;
    D_02031A0C.count++;
}
