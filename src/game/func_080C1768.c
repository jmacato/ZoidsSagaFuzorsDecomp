#include "types.h"

struct State
{
    u8 pad0[0x46];
    u8 a[3];
    u8 flag;
    u8 b[3];
    u8 pad4D[3];
    u32 field_50;
    u32 field_54;
};

struct Entry
{
    u8 active;
    u8 sub[3];
};

struct Data
{
    u8 pad0[0x244];
    u8 index;
    u8 pad245[0x4F84 - 0x245];
    struct Entry entries[1];
};

extern struct State D_02036E24;
extern struct Data D_02031A0C;

void func_080C10CC(void);
void func_080C180C(void);
void func_080C155C(u8, u8);

void func_080C1768(void)
{
    u8 i;
    func_080C10CC();
    func_080C180C();
    D_02036E24.field_50 = 0x80000000;
    for (i = 0; i < 3; i++)
    {
        D_02036E24.a[i] = (D_02036E24.b[i] |= 0xFF, D_02036E24.a[i] | 0xFF);
    }
    D_02036E24.field_54 = 0;
    func_080C155C(0, 0);
    if (D_02036E24.a[0] != 0xFF && D_02036E24.flag != 0)
    {
        D_02031A0C.entries[D_02031A0C.index].active = 0;
        for (i = 0; i < 3; i++)
            D_02031A0C.entries[D_02031A0C.index].sub[i] = D_02036E24.a[i];
    }
}
