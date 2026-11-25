#include "types.h"

extern u8 *D_087A59D4[];
extern u8 D_02030586[];
extern vu16 D_0300000E;

u8 func_0807C100(u8 *);
void func_0807BAD4(u8, u8, u8, u8, u8, u8);
void func_0807B77C(u8 *, u8, u8);
void func_0807A1A4(void);
void func_080C8FCC(u32);
void func_08075F20(u32);
void func_0807BD8C(u8);

void func_080C1B4C(u8 win, u8 msg)
{
    u8 height = 0;
    u8 width = 0;
    u8 *p = D_087A59D4[msg];
    u8 w;
    while (*p != 0)
    {
        w = 0;
        while (*p != 0 && *p != '\n')
        {
            switch (*p)
            {
            default:
                w++;
                if ((u8)(*p - 0x20) < 0x60)
                    p += 1;
                else
                    p += 2;
                break;
            case 3:
                w += func_0807C100(D_02030586);
                p += 1;
                break;
            case 1:
                p += 2;
                break;
            }
        }
        if (w > width)
            width = w;
        height += 2;
        if (*p == 0)
            break;
        p++;
    }
    if (width & 1)
        width++;
    width += 2;
    height += 2;
    func_0807BAD4(win, (30 - width) / 2, (20 - height) / 2, width, height, 0);
    func_0807B77C(D_087A59D4[msg], 0, win);
    func_0807A1A4();
    do
        func_080C8FCC(1);
    while (!(D_0300000E & 3));
    func_08075F20(0xCD);
    func_0807BD8C(win);
}
