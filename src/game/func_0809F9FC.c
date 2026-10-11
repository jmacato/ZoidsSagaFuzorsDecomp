#include "types.h"

struct Obj
{
    u32 flags;
    s32 x;
    s32 y;
    u8 pad_C[2];
    s16 field_E;
    s16 scaleX;
    s16 scaleY;
};

struct Slot
{
    u8 flags;
    u8 tile;
    s16 field_2;
    struct Obj *obj;
    struct Obj *icon;
    s32 x;
    s32 z;
    s32 y;
};

struct SlotPos
{
    s32 x;
    s32 z;
    s32 y;
};

struct CameraTarget
{
    u8 state;
    u8 side;
    u8 slot;
    u8 done;
    s32 x;
};

struct Screen
{
    s16 x;
    s16 y;
};

extern struct Slot D_02037B6C[][6];
extern const struct SlotPos D_087357D8[];
extern struct CameraTarget D_02037C8C;
extern u32 D_03000084;

u16 func_08076E48(s32 *pos, struct Screen *screen, u8 *visible);

void func_0809F9FC(void)
{
    u8 visible;
    struct Screen screen;
    u8 side, slot;
    u16 scale;
    u16 wob;
    s32 base;
    for (side = 0; side < 2; side++)
    {
        for (slot = 0; slot < 6; slot++)
        {
            struct Slot *s = &D_02037B6C[side][slot];
            if (!(s->flags & 1))
                continue;
            if (s->flags & 4)
            {
                if (D_087357D8[side * 6 + slot].x > s->x)
                    s->x += 0x1000;
                else if (D_087357D8[side * 6 + slot].x < s->x)
                    s->x -= 0x1000;
                if (D_087357D8[side * 6 + slot].y > s->y)
                    s->y += 0xA00;
                else if (D_087357D8[side * 6 + slot].y < s->y)
                    s->y -= 0xA00;
                if (D_087357D8[side * 6 + slot].x == s->x && D_087357D8[side * 6 + slot].y == s->y)
                    s->flags &= ~4;
            }
            else if (s->flags & 8)
            {
                if (side == 0)
                {
                    s->x += 0x1000;
                    if (s->x >= D_02037C8C.x + 0x13000)
                        s->flags &= ~8;
                }
                else
                {
                    s->x -= 0x1000;
                    if (s->x <= D_02037C8C.x - 0x13000)
                        s->flags &= ~8;
                }
            }
            else if (s->flags & 0x10)
            {
                if (side == 0)
                {
                    s->x -= 0x1000;
                    if (s->x <= D_02037C8C.x - 0x13000)
                        s->flags &= ~0x10;
                }
                else
                {
                    s->x += 0x1000;
                    if (s->x >= D_02037C8C.x + 0x13000)
                        s->flags &= ~0x10;
                }
            }
            scale = func_08076E48(&s->x, &screen, &visible);
            base = s->field_2 / 256;
            wob = !(D_03000084 & 0x20) ? base + ((D_03000084 >> 3) & 3) - 4 : base - ((D_03000084 >> 3) & 3);
            if (visible
                && ((!(s->flags & 2) && (s16)scale <= 0x300) || ((s->flags & 2) && (s16)scale <= 0x180)))
            {
                s->obj->x = screen.x << 8;
                s->obj->y = screen.y << 8;
                if (!(s->flags & 2))
                {
                    s->obj->scaleX = s->obj->scaleY = scale;
                }
                else
                {
                    s->obj->scaleX = s->obj->scaleY = (s16)scale * 2;
                    if (s->obj->scaleX <= 0x100)
                        s->obj->flags &= ~0x80000;
                    else
                        s->obj->flags |= 0x80000;
                }
                if (s->flags & 0x40)
                    s->obj->field_E = (s16)wob * (s16)scale / 256;
                s->obj->flags &= ~0x20000;
                if (s->flags & 0x20)
                {
                    s->icon->x = s->obj->x;
                    s->icon->y = s->obj->y;
                    s->icon->flags &= ~0x20000;
                }
                else
                    s->icon->flags |= 0x20000;
            }
            else
            {
                s->obj->flags |= 0x20000;
                s->icon->flags |= 0x20000;
            }
        }
    }
}
