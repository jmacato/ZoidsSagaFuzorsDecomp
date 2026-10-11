#include "types.h"

extern u8 (*D_0873FC30[])(u8, u8, u8);

void func_080C3BF8(u8);
void func_080C3C20(u8);
u32 func_0809A99C(u8, u8);
void func_0809B26C(u8, u8, u8, u8, u8, u8, u8, u8, u8);
void func_080B3B94(u8, u8, u8, u8);
void func_0809F7CC(u8, u8);
void func_080C8FCC(u32);

void func_080C3D1C(u8 side, u8 kind, u8 arg)
{
    u8 other = side == 0;
    u8 (*check)(u8, u8, u8) = D_0873FC30[kind];
    u8 found, i;

    func_080C3BF8(side);
    found = 0;
    for (i = 0; i < 6; i++)
    {
        if (func_0809A99C(side, i) && check(side, i, arg))
        {
            func_0809B26C(side, i, 0x28, 0, 1, 0, 0xFF, 0xFF, 0xFF);
            func_080B3B94(3, side, i, 0);
            func_0809F7CC(side, i);
            found = 1;
        }
    }
    if (!found)
    {
        for (i = 0; i < 30; i++)
            func_080C8FCC(1);
    }
    func_080C3C20(side);

    func_080C3BF8(other);
    found = 0;
    for (i = 0; i < 6; i++)
    {
        if (func_0809A99C(other, i) && check(other, i, arg))
        {
            func_0809B26C(other, i, 0x28, 0, 1, 0, 0xFF, 0xFF, 0xFF);
            func_080B3B94(3, other, i, 0);
            func_0809F7CC(other, i);
            found = 1;
        }
    }
    if (!found)
    {
        for (i = 0; i < 30; i++)
            func_080C8FCC(1);
    }
    func_080C3C20(other);
}
