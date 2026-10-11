#include "types.h"

struct Event
{
    u8 side;
    u8 slot;
    u8 id;
    u8 pad_3;
    u32 field_4;
};

struct Game
{
    u8 field_0;
    u8 field_1;
    u8 count;
    u8 cursor;
    struct Event events[1];
};

extern struct Game D_02031A0C;

void func_0809ACCC(u8 side, u8 slot, u8 id)
{
    s16 i, j;
    for (i = 0; i < D_02031A0C.count; i++)
    {
        if (D_02031A0C.events[i].side == side && D_02031A0C.events[i].slot == slot && (id == 0xFF || D_02031A0C.events[i].id == id))
        {
            D_02031A0C.count--;
            if (i < D_02031A0C.cursor)
                D_02031A0C.cursor--;
            for (j = i; j < D_02031A0C.count; j++)
                D_02031A0C.events[j] = D_02031A0C.events[j + 1];
            i--;
        }
    }
}
