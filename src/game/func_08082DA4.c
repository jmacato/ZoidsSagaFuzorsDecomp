#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
};

struct Actor
{
    u8 flags;
    u8 pad_1[3];
    s32 x;
    s32 y;
    u8 pad_C[0x10];
    struct Obj *obj1;
    struct Obj *obj2;
    u8 pad_24[0x20];
};

struct Map
{
    u8 pad_0[0x14];
    u16 width;
    u16 height;
    u8 pad_18[0x54];
    struct Actor actors[14];
};

struct Cam
{
    s32 x;
    s32 y;
};

extern struct Map D_020209D8;
extern struct Cam D_03000060;

void func_08082DA4(void)
{
    u8 i;
    for (i = 0; i < 14; i++)
    {
        struct Actor *a = &D_020209D8.actors[i];
        struct Obj *o;
        if (a->flags & 1)
        {
            o = a->obj1;
            if (o != 0)
            {
                u16 size;
                if (D_03000060.x < ((size = D_020209D8.width) - 0x20) << 11 || a->x >= D_03000060.x - 0x10000)
                    o->x = a->x;
                else
                    o->x = a->x + (size << 11);
                if (D_03000060.y < ((size = D_020209D8.height) - 0x20) << 11 || a->y >= D_03000060.y - 0x10000)
                    o->y = a->y;
                else
                    o->y = a->y + (size << 11);
            }
            if (a->obj2 != 0)
            {
                a->obj2->x = o->x;
                a->obj2->y = o->y;
            }
        }
    }
}
