#include "types.h"

extern u8 D_0203198C[];
extern u8 D_0200C4A0;
extern const u8 D_08014BAB[];
void func_0807BAD4(u8, u8, u8, u8, u8, u8);
void func_0807BEF4(u8, u8 *, s32);
void func_0807C290(const u8 *);
void func_0807A1A4(void);
void func_080C8FCC(s32);

u8 func_08083628(const u8 *text)
{
    u8 *lines[4];
    u8 *dst;
    u8 maxw, w, n, i;
    u16 c;

    lines[0] = D_0203198C;
    dst = D_0203198C;
    maxw = 0;
    w = 0;
    n = 0;
    while ((c = *text) != 0)
    {
        switch ((u8)c)
        {
        case 10:
            if (maxw < w)
                maxw = w;
            w = 0;
            n++;
            *dst++ = 0;
            lines[n] = dst;
            text++;
            break;
        default:
            w++;
        case 1:
            dst[0] = c;
            dst[1] = text[1];
            dst += 2;
            text += 2;
            break;
        }
    }
    if (maxw < w)
        maxw = w;
    n++;
    *dst = 0;
    func_0807BAD4(3, 0x1B - maxw, 9 - n * 2, maxw + 2, n * 2 + 2, 0x80);
    for (i = 0; i < n; i++)
        func_0807BEF4(3, lines[i], 0);
    func_0807C290(D_08014BAB);
    func_0807A1A4();
    func_080C8FCC(1);
    return D_0200C4A0;
}
