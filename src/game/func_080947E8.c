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

void func_080947E8(void)
{
    u8 i;

    if (D_02031A0C.flags[0] < 8)
        D_02031A0C.flags[0]++;
    D_02031A0C.objs[0]->x = D_02031A0C.pos[0].x + (D_02031A0C.vel[0].x - D_02031A0C.pos[0].x) * D_02031A0C.flags[0] / 8;
    D_02031A0C.objs[0]->y = D_02031A0C.pos[0].y + (D_02031A0C.vel[0].y - D_02031A0C.pos[0].y) * D_02031A0C.flags[0] / 8;
    switch (D_02031A0C.mode)
    {
    case 0:
        for (i = 6; i != 0; i--)
        {
            D_02031A0C.objs[i]->x = D_02031A0C.objs[i - 1]->x;
            D_02031A0C.objs[i]->y = D_02031A0C.objs[i - 1]->y;
        }
        break;
    case 1:
        for (i = 1; i < 7; i++)
        {
            if (D_02031A0C.flags[i] < 8)
                D_02031A0C.flags[i]++;
            D_02031A0C.objs[i]->x = D_02031A0C.pos[i].x + (D_02031A0C.vel[i].x - D_02031A0C.pos[i].x) * D_02031A0C.flags[i] / 8;
            D_02031A0C.objs[i]->y = D_02031A0C.pos[i].y + (D_02031A0C.vel[i].y - D_02031A0C.pos[i].y) * D_02031A0C.flags[i] / 8;
        }
        break;
    }
}
