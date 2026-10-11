#include "types.h"

struct Obj
{
    u32 flags;
    s32 screenX;
    s32 screenY;
    u8 padC[4];
    u16 scaleX;
    u16 scaleY;
    u8 pad14[0x1C];
    s32 x;
    s32 y;
    s32 z;
    u32 dir;
};

s16 func_08075AAC(s16);
s16 func_08075AF8(s16);

void func_0807DED0(struct Obj *obj)
{
    s16 sa, ca, sp, cp;
    u8 speed;

    sa = func_08075AAC(obj->dir);
    ca = func_08075AF8(obj->dir);
    sp = func_08075AAC(-16);
    cp = func_08075AF8(-16);
    speed = ((obj->dir >> 3) & 3) + 1;
    obj->x += ca * sp * speed / 128 + sa * sp * speed / 128;
    obj->y += sa * cp * speed / 128;
    obj->z += speed * (ca * cp) / 128;
    obj->screenX = (obj->x << 15) / obj->z + 0x7800;
    obj->screenY = (obj->y << 15) / obj->z + 0x5000;
    obj->scaleX = obj->scaleY = 0x800000 / obj->z;
    if ((u32)obj->z <= 0x8000)
        obj->flags &= ~0x300;
    else
        obj->flags = (obj->flags & ~0x300) | 0x200;
}
