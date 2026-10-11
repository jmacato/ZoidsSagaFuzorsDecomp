#include "types.h"

struct Obj
{
    u8 pad0[8];
    u8 e[5][2];
};

u8 func_080BF9B4(struct Obj *obj, u8 id);
void func_080BFAC4(struct Obj *obj, u8 i);
void func_080BF978(struct Obj *obj, u8 id, u8 n);

void func_080BFA34(struct Obj *obj, u8 slot, u8 id)
{
    u8 i = func_080BF9B4(obj, id);
    if (i == 5)
    {
        func_080BFAC4(obj, slot);
        obj->e[slot][0] = id;
        obj->e[slot][1] = 1;
        func_080BF978(obj, id, 1);
    }
    else if (obj->e[i][0] == id)
    {
        if (obj->e[i][1] < 9)
        {
            obj->e[i][1]++;
            func_080BF978(obj, id, 1);
        }
    }
    else
    {
        if (--obj->e[i][1] == 0)
            func_080BFAC4(obj, i);
        func_080BF978(obj, id, 1);
    }
}
