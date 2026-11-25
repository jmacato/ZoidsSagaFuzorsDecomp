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

struct Pic
{
    u16 w;
    u16 h;
    u8 pad_4[0x20];
};

struct World
{
    u8 pad_0[0x1A];
    u16 pic;
};

extern struct State D_0201F5F8;
extern struct Camera D_03000060;
extern struct World D_020209D8;
extern const struct Pic D_0877E074[];
u32 func_080C8B8C(s32);

void func_080928D8(s32 tx, s32 ty, u8 instant)
{
    u8 i;
    s32 center = 0x4000;

    D_0201F5F8.obj_move.dx = (tx / 16 - D_0201F5F8.objs[0]->x) / 256;
    D_0201F5F8.obj_move.dy = (ty / 16 - D_0201F5F8.objs[0]->y) / 256;
    D_0201F5F8.obj_move.total = (u16)func_080C8B8C(D_0201F5F8.obj_move.dx * D_0201F5F8.obj_move.dx + D_0201F5F8.obj_move.dy * D_0201F5F8.obj_move.dy) >> 3;
    D_0201F5F8.obj_move.count = 0;
    if (D_0201F5F8.obj_move.total == 0 || instant)
    {
        for (i = 0; i < 8; i++)
        {
            D_0201F5F8.objs[i]->x += D_0201F5F8.obj_move.dx << 8;
            D_0201F5F8.objs[i]->y += D_0201F5F8.obj_move.dy << 8;
        }
        D_0201F5F8.obj_move.total = 0;
    }
    else
    {
        if (D_0201F5F8.obj_move.dx >= 0)
        {
            D_0201F5F8.obj_move.dirx = 0;
        }
        else
        {
            D_0201F5F8.obj_move.dx = -D_0201F5F8.obj_move.dx;
            D_0201F5F8.obj_move.dirx = 1;
        }
        if (D_0201F5F8.obj_move.dy >= 0)
        {
            D_0201F5F8.obj_move.diry = 0;
        }
        else
        {
            D_0201F5F8.obj_move.dy = -D_0201F5F8.obj_move.dy;
            D_0201F5F8.obj_move.diry = 1;
        }
        D_0201F5F8.obj_move.accx = D_0201F5F8.obj_move.accy = 0;
    }
    if (D_0877E074[D_020209D8.pic].w / 2 > 0x80)
    {
        D_0201F5F8.cam_move.dx = (tx / 16 - (D_03000060.x + center)) / 256;
    }
    else
    {
        D_03000060.x = ((D_0877E074[D_020209D8.pic].w / 2 - 0x80) / 2) << 8;
        D_0201F5F8.cam_move.dx = 0;
    }
    if (D_0877E074[D_020209D8.pic].h / 2 > 0x80)
    {
        D_0201F5F8.cam_move.dy = (ty / 16 - (D_03000060.y + center)) / 256;
    }
    else
    {
        D_03000060.y = ((D_0877E074[D_020209D8.pic].h / 2 - 0x80) / 2) << 8;
        D_0201F5F8.cam_move.dy = 0;
    }
    D_0201F5F8.cam_move.total = (u16)func_080C8B8C(D_0201F5F8.cam_move.dx * D_0201F5F8.cam_move.dx + D_0201F5F8.cam_move.dy * D_0201F5F8.cam_move.dy) >> 2;
    D_0201F5F8.cam_move.count = 0;
    if (D_0201F5F8.cam_move.total == 0 || instant)
    {
        D_03000060.x += D_0201F5F8.cam_move.dx << 8;
        D_03000060.y += D_0201F5F8.cam_move.dy << 8;
        D_0201F5F8.cam_move.total = 0;
    }
    else
    {
        if (D_0201F5F8.cam_move.dx >= 0)
        {
            D_0201F5F8.cam_move.dirx = 0;
        }
        else
        {
            D_0201F5F8.cam_move.dx = -D_0201F5F8.cam_move.dx;
            D_0201F5F8.cam_move.dirx = 1;
        }
        if (D_0201F5F8.cam_move.dy >= 0)
        {
            D_0201F5F8.cam_move.diry = 0;
        }
        else
        {
            D_0201F5F8.cam_move.dy = -D_0201F5F8.cam_move.dy;
            D_0201F5F8.cam_move.diry = 1;
        }
        D_0201F5F8.cam_move.accx = D_0201F5F8.cam_move.accy = 0;
    }
}
