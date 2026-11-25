#include "types.h"

struct Entry
{
    u8 active;
    s8 field_1;
    s8 field_2;
    u8 field_3;
};

struct Data
{
    u8 pad0[0x244];
    u8 index;
    u8 pad245[0x4F84 - 0x245];
    struct Entry entries[1];
};

struct State
{
    u8 pad0[0x44];
    u16 field_44;
};

extern struct Data D_02031A0C;
extern struct State D_02036E24;

void func_080C10CC(void)
{
    D_02031A0C.entries[D_02031A0C.index].active = 1;
    D_02031A0C.entries[D_02031A0C.index].field_1 = D_02031A0C.entries[D_02031A0C.index].field_2 = D_02031A0C.entries[D_02031A0C.index].field_3 = 0xFF;
    D_02036E24.field_44 = 0;
}
