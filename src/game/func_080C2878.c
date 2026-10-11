#include "types.h"

struct Obj
{
    u8 pad0[4];
    u16 flags;
};

struct Data
{
    u8 pad0[0x2208];
    u8 slots[1];
};

extern struct Data D_02031A0C;

struct Obj *func_0809A908(u8, u8);

void func_080C2878(u8 i)
{
    if (D_02031A0C.slots[i] != 0xFF)
    {
        func_0809A908(0, D_02031A0C.slots[i])->flags &= ~1;
        D_02031A0C.slots[i] = 0xFF;
    }
}
