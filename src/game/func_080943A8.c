#include "types.h"

struct Obj
{
    u32 flags;
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
    u8 mode;
};

extern struct Big D_02031A0C;
extern struct Vec D_03000060;

void func_080943A8(u8 req)
{
    u8 i;

    switch (D_02031A0C.mode)
    {
    case 0:
        if (req == 1)
        {
            for (i = 1; i < 7; i++)
            {
                D_02031A0C.objs[i]->flags &= ~0x1000;
                D_02031A0C.objs[i]->x -= D_03000060.x;
                D_02031A0C.objs[i]->y -= D_03000060.y;
                D_02031A0C.flags[i] = 8;
            }
            D_02031A0C.mode = 1;
        }
        break;
    case 1:
        if (req == 0)
        {
            for (i = 1; i < 7; i++)
            {
                D_02031A0C.objs[i]->flags |= 0x1000;
                D_02031A0C.objs[i]->x = D_02031A0C.objs[0]->x;
                D_02031A0C.objs[i]->y = D_02031A0C.objs[0]->y;
                D_02031A0C.vel[i].x = D_02031A0C.objs[0]->x;
                D_02031A0C.vel[i].y = D_02031A0C.objs[0]->y;
                D_02031A0C.pos[i].x = D_02031A0C.objs[0]->x;
                D_02031A0C.pos[i].y = D_02031A0C.objs[0]->y;
                D_02031A0C.flags[i] = 8;
            }
            D_02031A0C.mode = 0;
        }
        break;
    }
}
