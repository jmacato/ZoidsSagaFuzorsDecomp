#include "types.h"

struct Vec3
{
    s32 x, y, z;
};

struct Vec2
{
    s32 x, y;
};

struct Camera
{
    u8 state;
    u8 pad_1[2];
    u8 field_3;
    struct Vec3 pos;
    struct Vec2 angle;
};

struct View
{
    struct Vec3 pos;
    struct Vec2 angle;
};

extern struct Camera D_02037C8C;
extern struct View D_030025A8;

void func_0809FEE4(struct Vec3 *pos, struct Vec2 *angle, u8 apply)
{
    D_02037C8C.state = 7;
    D_02037C8C.pos = *pos;
    D_02037C8C.angle = *angle;
    if (apply == 1)
    {
        D_030025A8.pos = D_02037C8C.pos;
        D_030025A8.angle = D_02037C8C.angle;
    }
    D_02037C8C.field_3 = 0;
}
