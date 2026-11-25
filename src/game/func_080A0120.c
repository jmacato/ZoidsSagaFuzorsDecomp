#include "types.h"

struct Vec3
{
    s32 x, y, z;
};

struct Rot
{
    s16 x, y, z, w;
};

struct Camera
{
    struct Vec3 pos;
    struct Rot rot;
    struct Vec3 target;
    struct Vec3 prevPos;
    struct Rot prevRot;
    struct Vec3 prevTarget;
    u8 matrix[0x24];
};

extern struct Camera D_030025A8;

void func_080767AC(struct Rot *rot, void *matrix);

void func_080A0120(void)
{
    struct Rot rot;
    if (D_030025A8.rot.x != D_030025A8.prevRot.x || D_030025A8.rot.y != D_030025A8.prevRot.y || D_030025A8.rot.z != D_030025A8.prevRot.z)
    {
        rot.x = D_030025A8.rot.x;
        rot.y = -D_030025A8.rot.y;
        rot.z = 0;
        func_080767AC(&rot, D_030025A8.matrix);
        D_030025A8.prevRot = D_030025A8.rot;
    }
    if (D_030025A8.pos.z != D_030025A8.prevPos.z || D_030025A8.target.x != D_030025A8.prevTarget.x || D_030025A8.target.y != D_030025A8.prevTarget.y || D_030025A8.target.z != D_030025A8.prevTarget.z)
    {
        D_030025A8.prevPos = D_030025A8.pos;
        D_030025A8.prevTarget = D_030025A8.target;
    }
}
