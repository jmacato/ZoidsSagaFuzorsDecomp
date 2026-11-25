#include "types.h"

struct Slot
{
    u8 id;
    u8 pad1[7];
};

struct List
{
    u8 count;
    u8 pad1[3];
    struct Slot slots[1];
};

struct Info
{
    u8 pad0[8];
    s16 field_8;
};

struct Unit
{
    u32 active:1;
    u32 flags:15;
    u32 type:16;
    s16 field_4;
    u8 pad6[0x26A];
};

struct Data
{
    u8 pad0[0x24C];
    struct Info *info;
    u8 pad250[0x222C - 0x250];
    struct Unit units[1];
};

extern struct List D_02036E24;
extern struct Data D_02031A0C;

void func_080C10CC(void);
void func_080C180C(void);
void func_080C1A78(u8, u8);
void func_080C112C(void);

void func_080C1220(void)
{
    u8 i;
    func_080C10CC();
    func_080C180C();
    for (i = 0; i < D_02036E24.count; i++)
    {
        struct Unit *unit = &D_02031A0C.units[D_02036E24.slots[i].id];
        if (unit->active && unit->type == 0x13 && D_02031A0C.info->field_8 >= unit->field_4)
        {
            func_080C1A78(i, 0);
            return;
        }
    }
    func_080C112C();
}
