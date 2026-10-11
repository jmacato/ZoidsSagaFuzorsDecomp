#include "types.h"

extern u8 D_0300568C;
extern void *D_030056A8[2];
extern u16 D_0300568E[2];
extern u16 D_03005692[2];
extern u16 D_0300004C;
extern u16 D_0300569C;
extern u16 D_0300569E;
extern u8 D_03000080;

void func_08078698(void);

void func_080786DC(void *win0, u16 x0, u16 y0, void *win1, u16 x1, u16 y1, u16 in, u16 out, u8 mode)
{
    D_0300568C = mode | 2;
    D_030056A8[0] = win0;
    D_0300568E[0] = x0;
    D_03005692[0] = y0;
    if (win0)
        D_0300004C |= 0x2000;
    D_030056A8[1] = win1;
    D_0300568E[1] = x1;
    D_03005692[1] = y1;
    if (win1)
        D_0300004C |= 0x4000;
    D_0300569C = in;
    D_0300569E = out;
    func_08078698();
    D_03000080 |= 2;
}
