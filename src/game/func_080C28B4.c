#include "types.h"

struct Obj
{
    u8 pad0[4];
    u16 flags;
};

struct Data
{
    u8 pad0[0x2208];
    u8 slots[6];
};

extern struct Data D_02031A0C;

struct Obj *func_0809A908(u8, u8);
void func_080C2878(u8);

void func_080C28B4(u8 id, u8 slot)
{
    struct Obj *obj = func_0809A908(0, id);
    u8 i;
    func_080C2878(slot);
    if (obj->flags & 1)
    {
        for (i = 0; i < 6; i++)
        {
            if (D_02031A0C.slots[i] == id)
            {
                func_080C2878(i);
                break;
            }
        }
    }
    D_02031A0C.slots[slot] = id;
    obj->flags |= 1;
}
