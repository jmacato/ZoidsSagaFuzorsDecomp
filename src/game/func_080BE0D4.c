#include "types.h"

struct Slot
{
    u16 field_0;
    u16 item;
};

struct Obj
{
    u8 pad0[0x74];
    struct Slot slots[4];
};

struct Data
{
    u8 pad0[0x7904];
    u8 owned[1];
};

extern struct Data D_02020E4C;

void func_0807F0C4(u8, u8);
void func_0807F0F8(u8, u8);

void func_080BE0D4(struct Obj *obj, u8 slot, u8 item)
{
    if (item == 0)
    {
        if (obj->slots[slot].item != 0)
        {
            func_0807F0C4(obj->slots[slot].item, 1);
            obj->slots[slot].item = item;
        }
    }
    else if (D_02020E4C.owned[item] != 0)
    {
        if (obj->slots[slot].item != item)
        {
            if (obj->slots[slot].item != 0)
                func_080BE0D4(obj, slot, 0);
            func_0807F0F8(item, 1);
            obj->slots[slot].item = item;
        }
    }
}
