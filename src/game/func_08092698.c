#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
};

struct Mover
{
    u16 total;
    u16 count;
    u8 dirx;
    u8 diry;
    u8 pad_6[2];
    s32 dx;
    s32 dy;
    s32 accx;
    s32 accy;
};

struct State
{
    u8 pad_0[0x94];
    struct Obj *objs[8];
    struct Mover obj_move;
    struct Mover cam_move;
};

struct Camera
{
    s32 x;
    s32 y;
};

extern struct State D_0201F5F8;
extern struct Camera D_03000060;
extern u32 D_03000084;
void func_080C8FCC(u32);

void func_08092698(void)
{
    s32 r;
    s32 g;
    s32 b;
    u8 i;
    u8 t;

    r = *(u16 *)0x0500001E & 0x1F;
    g = (*(u16 *)0x0500001E >> 5) % 32;
    b = (*(u16 *)0x0500001E >> 10) % 32;
    while (1)
    {
        if (D_0201F5F8.obj_move.count < D_0201F5F8.obj_move.total)
        {
            D_0201F5F8.obj_move.accx += D_0201F5F8.obj_move.dx;
            D_0201F5F8.obj_move.accy += D_0201F5F8.obj_move.dy;
            while (D_0201F5F8.obj_move.accx >= D_0201F5F8.obj_move.total)
            {
                if (D_0201F5F8.obj_move.dirx == 0)
                    D_0201F5F8.objs[0]->x += 0x100;
                else
                    D_0201F5F8.objs[0]->x -= 0x100;
                D_0201F5F8.obj_move.accx -= D_0201F5F8.obj_move.total;
            }
            while (D_0201F5F8.obj_move.accy >= D_0201F5F8.obj_move.total)
            {
                if (D_0201F5F8.obj_move.diry == 0)
                    D_0201F5F8.objs[0]->y += 0x100;
                else
                    D_0201F5F8.objs[0]->y -= 0x100;
                D_0201F5F8.obj_move.accy -= D_0201F5F8.obj_move.total;
            }
            D_0201F5F8.obj_move.count++;
        }
        for (i = 8; i != 0; i--)
        {
            D_0201F5F8.objs[i]->x = D_0201F5F8.objs[i - 1]->x;
            D_0201F5F8.objs[i]->y = D_0201F5F8.objs[i - 1]->y;
        }
        if (D_0201F5F8.cam_move.count < D_0201F5F8.cam_move.total)
        {
            D_0201F5F8.cam_move.accx += D_0201F5F8.cam_move.dx;
            D_0201F5F8.cam_move.accy += D_0201F5F8.cam_move.dy;
            while (D_0201F5F8.cam_move.accx >= D_0201F5F8.cam_move.total)
            {
                if (D_0201F5F8.cam_move.dirx == 0)
                    D_03000060.x += 0x100;
                else
                    D_03000060.x -= 0x100;
                D_0201F5F8.cam_move.accx -= D_0201F5F8.cam_move.total;
            }
            while (D_0201F5F8.cam_move.accy >= D_0201F5F8.cam_move.total)
            {
                if (D_0201F5F8.cam_move.diry == 0)
                    D_03000060.y += 0x100;
                else
                    D_03000060.y -= 0x100;
                D_0201F5F8.cam_move.accy -= D_0201F5F8.cam_move.total;
            }
            D_0201F5F8.cam_move.count++;
        }
        if (!(D_03000084 & 0x20))
            t = D_03000084 & 0x1F;
        else
            t = 0x20 - (D_03000084 & 0x1F);
        *(vu16 *)0x0500001E = ((b * t / 32) << 10) | ((g * t / 32) << 5) | (r * t / 32);
        func_080C8FCC(1);
    }
}
