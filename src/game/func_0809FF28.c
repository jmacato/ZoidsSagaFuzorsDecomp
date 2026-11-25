#include "types.h"

struct Vec3
{
    s32 x, y, z;
};

struct Rot
{
    s16 x, y, z, w;
};

struct CameraTarget
{
    u8 state;
    u8 pad_1[2];
    u8 done;
    struct Vec3 pos;
    struct Rot rot;
};

struct Camera
{
    struct Vec3 pos;
    struct Rot rot;
};

extern struct CameraTarget D_02037C8C;
extern struct Camera D_030025A8;

void func_0809FF28(void)
{
    if (D_02037C8C.done)
        return;
    if (D_02037C8C.state == 1 || D_02037C8C.state == 8)
    {
        if (D_030025A8.pos.y < 0x8000)
        {
            D_030025A8.pos.y -= D_030025A8.pos.y / 8;
            if (D_030025A8.rot.x < 32)
                D_030025A8.rot.x++;
        }
        else
            D_030025A8.pos.y -= 0x1000;
        if (D_030025A8.rot.x == 32 && D_030025A8.pos.y < 64)
        {
            D_030025A8.pos.y = 0;
            D_02037C8C.done = 1;
        }
        return;
    }
    D_030025A8.pos.x += (D_02037C8C.pos.x - D_030025A8.pos.x) / 4;
    if ((D_02037C8C.pos.x > D_030025A8.pos.x && D_02037C8C.pos.x - D_030025A8.pos.x < 128) || (D_02037C8C.pos.x < D_030025A8.pos.x && D_02037C8C.pos.x - D_030025A8.pos.x > -128))
        D_030025A8.pos.x = D_02037C8C.pos.x;
    D_030025A8.pos.y += (D_02037C8C.pos.y - D_030025A8.pos.y) / 4;
    if ((D_02037C8C.pos.y > D_030025A8.pos.y && D_02037C8C.pos.y - D_030025A8.pos.y < 128) || (D_02037C8C.pos.y < D_030025A8.pos.y && D_02037C8C.pos.y - D_030025A8.pos.y > -128))
        D_030025A8.pos.y = D_02037C8C.pos.y;
    D_030025A8.pos.z += (D_02037C8C.pos.z - D_030025A8.pos.z) / 4;
    if ((D_02037C8C.pos.z > D_030025A8.pos.z && D_02037C8C.pos.z - D_030025A8.pos.z < 128) || (D_02037C8C.pos.z < D_030025A8.pos.z && D_02037C8C.pos.z - D_030025A8.pos.z > -128))
        D_030025A8.pos.z = D_02037C8C.pos.z;
    if (D_030025A8.rot.x != D_02037C8C.rot.x)
    {
        if (D_030025A8.rot.x < D_02037C8C.rot.x)
        {
            if (D_02037C8C.rot.x - D_030025A8.rot.x <= 128)
                D_030025A8.rot.x++;
            else
                D_030025A8.rot.x--;
        }
        else
        {
            if (D_030025A8.rot.x - D_02037C8C.rot.x <= 128)
                D_030025A8.rot.x--;
            else
                D_030025A8.rot.x++;
        }
    }
    if (D_030025A8.rot.y != D_02037C8C.rot.y)
    {
        if (D_030025A8.rot.y < D_02037C8C.rot.y)
        {
            if (D_02037C8C.rot.y - D_030025A8.rot.y <= 128)
                D_030025A8.rot.y++;
            else
                D_030025A8.rot.y--;
        }
        else
        {
            if (D_030025A8.rot.y - D_02037C8C.rot.y <= 128)
                D_030025A8.rot.y--;
            else
                D_030025A8.rot.y++;
        }
    }
    if (D_030025A8.rot.z != D_02037C8C.rot.z)
    {
        if (D_030025A8.rot.z < D_02037C8C.rot.z)
        {
            if (D_02037C8C.rot.z - D_030025A8.rot.z <= 128)
                D_030025A8.rot.z++;
            else
                D_030025A8.rot.z--;
        }
        else
        {
            if (D_030025A8.rot.z - D_02037C8C.rot.z <= 128)
                D_030025A8.rot.z--;
            else
                D_030025A8.rot.z++;
        }
    }
    if (D_030025A8.pos.x == D_02037C8C.pos.x && D_030025A8.pos.y == D_02037C8C.pos.y && D_030025A8.pos.z == D_02037C8C.pos.z
        && D_030025A8.rot.x == D_02037C8C.rot.x && D_030025A8.rot.y == D_02037C8C.rot.y && D_030025A8.rot.z == D_02037C8C.rot.z)
        D_02037C8C.done = 1;
}
