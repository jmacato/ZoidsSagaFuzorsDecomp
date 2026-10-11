#include "types.h"

struct Obj
{
    u8 pad0[0x12];
    u8 nibbles[1];
};

void func_080BF5C0(struct Obj *obj, u8 i, u8 v)
{
    if (!(i & 1))
        obj->nibbles[i >> 1] = (obj->nibbles[i >> 1] & 0xF0) | (v & 0xF);
    else
        obj->nibbles[i >> 1] = (obj->nibbles[i >> 1] & 0xF) | ((v & 0xF) << 4);
}
