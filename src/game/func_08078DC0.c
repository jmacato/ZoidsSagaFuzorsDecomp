#include "types.h"

extern u8 D_03005696;
extern u8 D_030056B6;
extern u32 D_02000000[][160][2];

s16 func_08075AAC(s16);
s16 func_08075AF8(s16);

void func_08078DC0(void)
{
    u8 i;
    s32 x, y;
    s32 dx, dy;
    s32 err;
    s32 k, j;
    s32 c, row;
    s32 xneg, yneg;

    for (i = 0; i < 160; i++)
    {
        if (i < 80)
            D_02000000[D_030056B6 ^ 1][i][0] = 0x78F00000;
        else
            D_02000000[D_030056B6 ^ 1][i][0] = 0x00780000;
    }
    x = 0;
    y = 0;
    dx = -(func_08075AF8(D_03005696) * 160) / 256;
    dy = -(func_08075AAC(D_03005696) * 160) / 256;
    if (dx >= 0)
        xneg = 0;
    else
    {
        dx = -dx;
        xneg = 1;
    }
    if (dy >= 0)
        yneg = 0;
    else
    {
        dy = -dy;
        yneg = 1;
    }
    if (dx > dy)
    {
        err = 0;
        for (k = 0; k <= dx; k++)
        {
            if (y + 79 >= 0 && y + 79 <= 79)
            {
                c = x + 119;
                row = y + 79;
                if (c < 0)
                    c = 0;
                else if (c > 239)
                    c = 239;
                *(u16 *)&D_02000000[D_030056B6 ^ 1][row][0] = c + 1;
                c = 120 - x;
                row = 80 - y;
                if (c < 0)
                    c = 0;
                else if (c > 239)
                    c = 239;
                *(u16 *)&D_02000000[D_030056B6 ^ 1][row][0] = (c << 8) | 0xF0;
            }
            if (x + 79 >= 0 && x + 79 <= 79)
            {
                c = 119 - y;
                row = x + 79;
                if (c < 0)
                    c = 0;
                else if (c > 239)
                    c = 239;
                ((u16 *)&D_02000000[D_030056B6 ^ 1][row][0])[1] = (c + 1) | 0x7800;
                c = y + 120;
                row = 80 - x;
                if (c < 0)
                    c = 0;
                else if (c > 239)
                    c = 239;
                ((u16 *)&D_02000000[D_030056B6 ^ 1][row][0])[1] = (c << 8) | 0x78;
            }
            if (!xneg)
                x++;
            else
                x--;
            err += dy;
            if (err >= dx)
            {
                if (!yneg)
                    y++;
                else
                    y--;
                err -= dx;
            }
        }
    }
    else
    {
        err = 0;
        for (j = 0; j <= dy; j++)
        {
            if (y + 79 >= 0 && y + 79 <= 79)
            {
                c = x + 119;
                row = y + 79;
                if (c < 0)
                    c = 0;
                else if (c > 239)
                    c = 239;
                *(u16 *)&D_02000000[D_030056B6 ^ 1][row][0] = c + 1;
                c = 120 - x;
                row = 80 - y;
                if (c < 0)
                    c = 0;
                else if (c > 239)
                    c = 239;
                *(u16 *)&D_02000000[D_030056B6 ^ 1][row][0] = (c << 8) | 0xF0;
            }
            if (x + 79 >= 0 && x + 79 <= 79)
            {
                c = 119 - y;
                row = x + 79;
                if (c < 0)
                    c = 0;
                else if (c > 239)
                    c = 239;
                ((u16 *)&D_02000000[D_030056B6 ^ 1][row][0])[1] = (c + 1) | 0x7800;
                c = y + 120;
                row = 80 - x;
                if (c < 0)
                    c = 0;
                else if (c > 239)
                    c = 239;
                ((u16 *)&D_02000000[D_030056B6 ^ 1][row][0])[1] = (c << 8) | 0x78;
            }
            if (!yneg)
                y++;
            else
                y--;
            err += dx;
            if (err >= dy)
            {
                if (!xneg)
                    x++;
                else
                    x--;
                err -= dy;
            }
        }
    }
}
