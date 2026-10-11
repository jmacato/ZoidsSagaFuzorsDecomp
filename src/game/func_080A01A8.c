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
};

struct Display
{
    s32 field_0;
    s32 field_4;
};

extern struct Camera D_030025A8;
extern struct Display D_03000060;

void func_0809FF28(void);
u8 func_08076B98(void);
void func_080A0120(void);
s32 func_08075AF8(s16 angle);
s32 func_08075AAC(s16 angle);
void func_080785C0(u8 a, u8 b, u8 c, u8 d, u8 e);
void func_0809F9FC(void);
void func_080C8FCC(u32 frames);

void func_080A01A8(void)
{
    for (;;)
    {
        u8 level, a, b;
        s32 c, s;
        func_0809FF28();
        level = func_08076B98();
        func_080A0120();
        c = func_08075AF8(D_030025A8.rot.y);
        s = func_08075AAC(D_030025A8.rot.y);
        D_03000060.field_0 = D_030025A8.pos.x * (s16)c / 1024 - (D_030025A8.target.x << 8) + (s16)s * D_030025A8.pos.y / 1024 + (D_030025A8.rot.y << 10);
        D_03000060.field_4 = (0x80 - level) << 8;
        if (level != 0xFF)
        {
            a = 0;
            b = level;
        }
        else
        {
            a = 0xFF;
            b = 0;
        }
        func_080785C0(0, a, 0xF0, b, 0x3B);
        func_0809F9FC();
        func_080C8FCC(1);
    }
}
