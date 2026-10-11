#include "types.h"

struct Obj
{
    u8 pad0[7];
    u8 type;
};

s32 func_080C0008(struct Obj *obj)
{
    switch (obj->type)
    {
    case 0:
    case 7:
        return 1;
    case 1:
    case 3:
        return 2;
    case 2:
        return 3;
    case 4:
        return 4;
    case 5:
        return 6;
    case 6:
        return 12;
    }
}
