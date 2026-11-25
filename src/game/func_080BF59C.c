#include "types.h"

struct Obj
{
    u8 pad0[0x12];
    u8 nibbles[1];
};

u8 func_080BF59C(struct Obj *obj, u8 i)
{
    u8 v = obj->nibbles[i >> 1];
    u8 r;
    if (i & 1)
        r = v >> 4;
    else
        r = v & 0xF;
    return r;
}
