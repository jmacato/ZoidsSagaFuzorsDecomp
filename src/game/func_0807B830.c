#include "types.h"

u8 func_0807B7A8(s32, u8 *, u8, u8);
u8 func_080C8B80(s32, s32);

void func_0807B830(s32 value, u8 width, u8 flags, u8 *buf)
{
    s32 div = 1000000000;
    s32 started = 0;
    u8 pos = 0;
    s32 sign = 0;
    u8 i;
    u8 digit;
    u8 big;

    if (value != 0)
    {
        sign = 2;
        if (value > 0)
            sign = 1;
    }
    if (flags & 4)
    {
        if (((s8)flags & 0xB) != 0xA)
        {
            pos = func_0807B7A8(sign, buf, pos, flags);
        }
        else
        {
            if (!(flags & 0x10))
                ((u16 *)buf)[pos] = 0x4081;
            else
                buf[pos] = ' ';
            pos++;
        }
    }
    if (value < 0)
        value = -value;
    for (i = 0, big = flags & 0x10; i < 10; i++)
    {
        if (i >= 10 - width)
        {
            digit = func_080C8B80(value, div);
            if (digit != 0 || started || i == 9)
            {
                if (!started && ((s8)flags & 0xF) == 0xE)
                    pos = func_0807B7A8(sign, buf, pos - 1, flags);
                if (!big)
                    ((u16 *)buf)[pos] = (digit << 8) + 0x4F82;
                else
                    buf[pos] = digit + '0';
                pos++;
                value -= digit * div;
                started = 1;
            }
            else
            {
                switch (flags & 3)
                {
                case 1:
                    break;
                case 2:
                    if (!big)
                        ((u16 *)buf)[pos] = 0x4081;
                    else
                        buf[pos] = ' ';
                    pos++;
                    break;
                case 3:
                    if (!big)
                        ((u16 *)buf)[pos] = 0x4F82;
                    else
                        buf[pos] = '0';
                    pos++;
                    break;
                }
            }
        }
        div /= 10;
    }
    if ((flags & 3) == 1)
    {
        if (!(flags & 0x10))
        {
            while (pos < width)
            {
                ((u16 *)buf)[pos] = 0x4081;
                pos++;
            }
        }
        else
        {
            while (pos < width)
            {
                buf[pos] = ' ';
                pos++;
            }
        }
    }
    {
        u8 end = flags & 0x10;
        if (!end)
            buf[pos * 2] = end;
        else
            buf[pos] = 0;
    }
}
