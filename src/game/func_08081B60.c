#include "types.h"

struct Obj
{
    u8 flags;
    u8 pad_1[3];
    s32 x;
    s32 y;
    u8 pad_C[0x30];
    s32 tx;
    s32 ty;
};

void func_08081B60(struct Obj *a, struct Obj *b)
{
    a->tx = b->x;
    a->ty = b->y;
    b->tx = a->x;
    b->ty = a->y;
    a->flags |= 8;
    b->flags |= 8;
}
