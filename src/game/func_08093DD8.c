#include "types.h"

struct Obj
{
    u8 pad_0[4];
    s32 x;
    s32 y;
    u8 pad_C[6];
    s16 h;
};

struct Slot
{
    u8 pad_0[4];
    struct Obj *obj;
    u8 pad_8[0x10];
};

struct Pos
{
    u8 pad_0[4];
    s32 x;
    s32 y;
};

struct Big
{
    u8 pad_0[0x4E9C];
    s8 side;
    s8 slot;
};

extern struct Big D_02031A0C;
extern struct Slot D_02037B6C[][6];

void func_08093DD8(struct Pos *pos)
{
    struct Slot *s = &D_02037B6C[D_02031A0C.side][D_02031A0C.slot];
    struct Obj *obj = s->obj;

    pos->x = obj->x;
    pos->y = obj->y - (obj->h << 5);
}
