#include "types.h"

struct Camera
{
    s32 x;
    s32 y;
    s32 z;
    u8 padC[8];
    s32 originX;
    s32 originY;
    s32 focal;
    u8 pad20[0x20];
    u8 matrix[0x20];
    s32 farZ;
};

extern struct Camera D_030025A8;

void func_0807672C(void *, s32 *, s32 *);
s32 func_080C8B80(s32, s32);

s16 func_08076E48(const s32 *pos, s16 *screen, u8 *visible)
{
    s32 rel[3];
    s32 out[3];
    s32 z;

    rel[0] = pos[0] - D_030025A8.x;
    rel[1] = pos[1];
    rel[2] = D_030025A8.y - pos[2];
    func_0807672C(D_030025A8.matrix, rel, out);
    z = out[2] + D_030025A8.z;
    if (z <= 0 || z >= D_030025A8.farZ || D_030025A8.focal == 0)
    {
        *visible = 0;
        return;
    }
    screen[0] = D_030025A8.originX + func_080C8B80(out[0] * D_030025A8.focal, z);
    screen[1] = D_030025A8.originY + func_080C8B80(out[1] * D_030025A8.focal, z);
    *visible = 1;
    return func_080C8B80(D_030025A8.focal << 16, z);
}
