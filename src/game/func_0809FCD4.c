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
    u8 side;
    u8 slot;
    u8 done;
    struct Vec3 pos;
    struct Rot rot;
};

struct Camera
{
    struct Vec3 pos;
    struct Rot rot;
};

struct SlotPos
{
    s32 x;
    s32 z;
    s32 y;
};

struct Slot
{
    u8 flags;
    u8 pad_1[0x17];
};

extern struct CameraTarget D_02037C8C;
extern struct Camera D_030025A8;
extern const struct SlotPos D_087357D8[];
extern struct Slot D_02037B6C[][6];

void func_0809FCD4(u8 state, u8 side, u8 slot, u8 apply)
{
    D_02037C8C.state = state;
    D_02037C8C.side = side;
    D_02037C8C.slot = slot;
    switch (D_02037C8C.state)
    {
    case 0:
        D_02037C8C.pos.x = 0;
        D_02037C8C.pos.y = 0;
        D_02037C8C.pos.z = 0x8000;
        D_02037C8C.rot.x = 0x20;
        D_02037C8C.rot.y = D_02037C8C.rot.z = 0;
        break;
    case 1:
        D_02037C8C.pos.x = -0xD000;
        D_02037C8C.pos.y = 0x20000;
        D_02037C8C.pos.z = 0x8000;
        D_02037C8C.rot.x = 4;
        D_02037C8C.rot.y = D_02037C8C.rot.z = 0;
        break;
    case 8:
        D_02037C8C.pos.x = 0;
        D_02037C8C.pos.y = 0x20000;
        D_02037C8C.pos.z = 0x8000;
        D_02037C8C.rot.x = 4;
        D_02037C8C.rot.y = D_02037C8C.rot.z = 0;
        break;
    case 2:
        if (D_02037C8C.side == 0)
        {
            D_02037C8C.pos.x = 0xD000;
            D_02037C8C.pos.y = 0;
            D_02037C8C.pos.z = 0x8000;
            D_02037C8C.rot.x = 0x20;
            D_02037C8C.rot.y = D_02037C8C.rot.z = 0;
        }
        else
        {
            D_02037C8C.pos.x = -0xD000;
            D_02037C8C.pos.y = 0;
            D_02037C8C.pos.z = 0x8000;
            D_02037C8C.rot.x = 0x20;
            D_02037C8C.rot.y = D_02037C8C.rot.z = 0;
        }
        break;
    case 3:
        if (D_02037C8C.side == 0)
        {
            D_02037C8C.pos.x = 0xB000;
            D_02037C8C.pos.y = 0;
            D_02037C8C.pos.z = 0x8000;
            D_02037C8C.rot.x = 0x20;
            D_02037C8C.rot.y = D_02037C8C.rot.z = 0;
        }
        else
        {
            D_02037C8C.pos.x = -0xF000;
            D_02037C8C.pos.y = 0;
            D_02037C8C.pos.z = 0x8000;
            D_02037C8C.rot.x = 0x20;
            D_02037C8C.rot.y = D_02037C8C.rot.z = 0;
        }
        break;
    case 4:
        if (D_02037C8C.side == 0)
        {
            D_02037C8C.pos.x = 0xC000;
            D_02037C8C.pos.y = 0;
            D_02037C8C.pos.z = 0x8000;
            D_02037C8C.rot.x = 0x20;
            D_02037C8C.rot.y = D_02037C8C.rot.z = 0;
        }
        else
        {
            D_02037C8C.pos.x = -0x10000;
            D_02037C8C.pos.y = 0;
            D_02037C8C.pos.z = 0x8000;
            D_02037C8C.rot.x = 0x20;
            D_02037C8C.rot.y = D_02037C8C.rot.z = 0;
        }
        break;
    case 5:
        D_02037C8C.pos.x = D_087357D8[D_02037C8C.side * 6 + D_02037C8C.slot].x;
        D_02037C8C.pos.y = D_087357D8[D_02037C8C.side * 6 + D_02037C8C.slot].y;
        D_02037C8C.pos.z = 0x8000;
        D_02037C8C.rot.x = 0x20;
        D_02037C8C.rot.y = D_02037C8C.rot.z = 0;
        break;
    case 6:
        D_02037C8C.pos.x = 0;
        D_02037C8C.pos.y = 0;
        D_02037C8C.pos.z = 0x8000;
        D_02037C8C.rot.x = 0x20;
        D_02037C8C.rot.y = D_02037C8C.rot.z = 0;
        break;
    case 9:
        D_02037C8C.pos.x = D_087357D8[D_02037C8C.side * 6 + D_02037C8C.slot].x;
        D_02037C8C.pos.y = D_087357D8[D_02037C8C.side * 6 + D_02037C8C.slot].y;
        if (!(D_02037B6C[D_02037C8C.side][D_02037C8C.slot].flags & 2))
            D_02037C8C.pos.z = 0x4000;
        else
            D_02037C8C.pos.z = 0x8000;
        D_02037C8C.rot.x = 0x20;
        D_02037C8C.rot.y = D_02037C8C.rot.z = 0;
        break;
    case 10:
        D_02037C8C.pos.x = 0;
        D_02037C8C.pos.y = 0;
        D_02037C8C.pos.z = 0x10000;
        D_02037C8C.rot.x = 0x20;
        D_02037C8C.rot.y = D_02037C8C.rot.z = 0;
        break;
    }
    if (apply == 1)
    {
        D_030025A8.pos = D_02037C8C.pos;
        D_030025A8.rot = D_02037C8C.rot;
    }
    D_02037C8C.done = 0;
}
