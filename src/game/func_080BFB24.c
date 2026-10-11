#include "types.h"

struct Template
{
    u8 field_0;
    u8 field_1;
    u8 type;
    u8 pad3[0x31];
};

extern struct Template D_0873FCC8[];

s32 func_080BD2AC(u8, u8);
s16 func_080BFADC(void *, u8);

s16 func_080BFB24(void *pilot, u8 *unit)
{
    s16 total = 0;
    if (func_080BD2AC(*unit, 12))
        total += func_080BFADC(pilot, 1);
    if (func_080BD2AC(*unit, 7))
        total += func_080BFADC(pilot, 2);
    if (func_080BD2AC(*unit, 2))
        total += func_080BFADC(pilot, 3);
    if (func_080BD2AC(*unit, 3))
        total += func_080BFADC(pilot, 4);
    if (func_080BD2AC(*unit, 4))
        total += func_080BFADC(pilot, 5);
    if (func_080BD2AC(*unit, 9))
        total += func_080BFADC(pilot, 6);
    if (func_080BD2AC(*unit, 6))
        total += func_080BFADC(pilot, 7);
    if (func_080BD2AC(*unit, 11))
        total += func_080BFADC(pilot, 8);
    if (func_080BD2AC(*unit, 8))
        total += func_080BFADC(pilot, 9);
    if (func_080BD2AC(*unit, 5))
        total += func_080BFADC(pilot, 10);
    if (func_080BD2AC(*unit, 1))
        total += func_080BFADC(pilot, 11);
    if (func_080BD2AC(*unit, 10))
        total += func_080BFADC(pilot, 12);
    if (func_080BD2AC(*unit, 13))
        total += func_080BFADC(pilot, 13);
    if (func_080BD2AC(*unit, 14))
        total += func_080BFADC(pilot, 14);
    switch (D_0873FCC8[*unit].type)
    {
    case 0:
        total += func_080BFADC(pilot, 0x27);
        total += func_080BFADC(pilot, 0x2C);
        break;
    case 1:
        total += func_080BFADC(pilot, 0x28);
        total += func_080BFADC(pilot, 0x2C);
        break;
    case 2:
        total += func_080BFADC(pilot, 0x29);
        break;
    case 3:
        total += func_080BFADC(pilot, 0x2A);
        total += func_080BFADC(pilot, 0x2D);
        break;
    case 4:
        total += func_080BFADC(pilot, 0x2B);
        total += func_080BFADC(pilot, 0x2D);
        break;
    }
    return total;
}
