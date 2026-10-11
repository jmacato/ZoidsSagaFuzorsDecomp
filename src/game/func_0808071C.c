#include "types.h"

struct Field
{
    u8 pad0[0x14];
    u16 width;
    u16 height;
    u8 wrap;
};

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    u8 padC[0xE];
    u8 tile;
};

extern struct Field D_020209D8;
extern u8 *D_02031A18;

u8 func_08082E58(struct Obj *);

void func_0808071C(struct Obj *obj)
{
    u8 t[4];
    u32 tx, ty, row;
    u8 *map;

    if (D_020209D8.wrap)
    {
        tx = obj->x / 4096 % (D_020209D8.width >> 1);
        row = obj->y / 4096 % (D_020209D8.height >> 1);
        obj->tile = D_02031A18[tx + row * (D_020209D8.width >> 1)];
        return;
    }
    tx = obj->x / 2048;
    if (obj->x % 2048 <= 0x3FF)
        tx--;
    ty = obj->y / 2048;
    if (obj->y % 2048 <= 0x3FF)
        ty--;
    row = func_08082E58(obj) ? ty : ty + 1;
    t[0] = D_02031A18[tx + row * D_020209D8.width];
    map = D_02031A18;
    if (tx + 1 < D_020209D8.width)
    {
        t[1] = map[row * D_020209D8.width + tx + 1];
        if (row + 1 < D_020209D8.height)
        {
            t[2] = map[tx + (row + 1) * D_020209D8.width];
            t[3] = map[(row + 1) * D_020209D8.width + tx + 1];
        }
        else
        {
            t[2] = map[tx];
            t[3] = map[tx + 1];
        }
    }
    else
    {
        t[1] = map[row * D_020209D8.width];
        if (row + 1 < D_020209D8.height)
        {
            t[2] = map[tx + (row + 1) * D_020209D8.width];
            t[3] = map[(row + 1) * D_020209D8.width];
        }
        else
        {
            t[2] = map[tx];
            t[3] = map[0];
        }
    }
    if (t[0] == t[1] && t[0] == t[2] && t[0] == t[3])
    {
        obj->tile = t[0];
        return;
    }
    if (!(t[0] & 0x40))
        obj->tile = t[0];
    else if (!(t[1] & 0x40))
        obj->tile = t[1];
    else if (!(t[2] & 0x40))
        obj->tile = t[2];
    else if (!(t[3] & 0x40))
        obj->tile = t[3];
}
