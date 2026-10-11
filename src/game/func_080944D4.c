#include "types.h"

struct Obj
{
    u8 pad_0[4];
    s32 x;
    s32 y;
};

struct Vec
{
    s32 x;
    s32 y;
};

struct Big
{
    u8 pad_0[0x4EA4];
    struct Obj *objs[7];
    struct Vec pos[7];
    struct Vec vel[7];
    u8 flags[7];
};

extern struct Big D_02031A0C;

void func_080944D4(u8 id, s16 x, s16 y)
{
    D_02031A0C.vel[id].x = x << 8;
    D_02031A0C.vel[id].y = y << 8;
    D_02031A0C.pos[id].x = D_02031A0C.objs[id]->x;
    D_02031A0C.pos[id].y = D_02031A0C.objs[id]->y;
    D_02031A0C.flags[id] = 0;
}
