#include "types.h"

struct Obj
{
    u32 flags;
    u8 pad_4[8];
    u16 field_C;
};

struct Slot
{
    u8 flags;
    u8 tile;
    u16 field_2;
    struct Obj *obj;
    struct Obj *icon;
    s32 x;
    s32 z;
    s32 y;
};

struct ZoidInfo
{
    u8 flags;
    u8 pad_1[0x33];
};

struct SlotPos
{
    s32 x;
    s32 z;
    s32 y;
};

extern struct Slot D_02037B6C[][6];
extern const struct ZoidInfo D_0873FCC8[];
extern const struct SlotPos D_087357D8[];
extern const u8 D_08424594[];
extern const u8 D_084245A0[];
extern const u8 D_08502A1C[];
extern const u8 D_08502A28[];

struct Obj *func_080771BC(const void *a, const void *b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i);
void func_0807FB7C(u8 type, u8 level, u32 vram, u8 tile);

void func_0809F530(u8 type, u8 level, u8 kind, u8 side, u8 slot, s32 dx, s32 dy)
{
    struct Slot *s = &D_02037B6C[side][slot];
    u8 tile, j, pal, idx;
    u32 num, vram;
    if (!(s->flags & 1))
    {
        for (tile = side * 6; tile < side * 6 + 6; tile++)
        {
            for (j = 0; j < 6; j++)
            {
                if ((D_02037B6C[side][j].flags & 1) && D_02037B6C[side][j].tile == tile)
                    break;
            }
            if (j == 6)
                break;
        }
        s->tile = tile;
    }
    else
        tile = s->tile;
    vram = tile << 6;
    num = tile;
    if (!(s->flags & 1))
    {
        s->flags |= 1;
        if (side == 0)
            pal = 3 - slot % 3;
        else
            pal = slot % 3 + 1;
        s->obj = func_080771BC(D_08424594, D_084245A0, 0, 0, 0, vram, num, (pal << 6) | 0x308, 0);
        s->icon = func_080771BC(D_08502A1C, D_08502A28, 0, 0, 0, (u16)(tile * 8 + 0x300), 0xE, 0x148, 0);
        if (side == 0)
            s->icon->field_C = 0x10;
        else
        {
            s->obj->flags |= 0x8000;
            s->icon->field_C = 0xFFD0;
        }
        if (kind == 4)
            s->flags |= 2;
        if (D_0873FCC8[type].flags & 0x80)
        {
            s->flags |= 0x40;
            s->field_2 = 0xF000;
        }
        else
            s->field_2 = 0;
        idx = slot + side * 6;
        s->x = D_087357D8[idx].x + dx;
        s->z = D_087357D8[idx].z;
        s->y = D_087357D8[idx].y + dy;
    }
    func_0807FB7C(type, level, vram, num);
}
