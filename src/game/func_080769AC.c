#include "types.h"

struct Camera
{
    u8 pad0[0x14];
    s32 x;
    s32 y;
    s32 z;
};

void func_08076698(struct Camera *, const void *, s16 *);
s32 func_080C8B80(s32, s32);

s16 func_080769AC(const void *vec, s16 *screen, struct Camera *cam)
{
    s32 pos[3];
    s16 rel[3];

    func_08076698(cam, vec, rel);
    pos[0] = rel[0] + cam->x;
    pos[1] = rel[1] + cam->y;
    pos[2] = rel[2] + cam->z;
    screen[0] = func_080C8B80(pos[0] << 8, pos[2]) + 120;
    screen[1] = func_080C8B80(pos[1] << 8, pos[2]) + 80;
    return pos[2];
}
