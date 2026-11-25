#include "types.h"

extern u16 D_0300004C;
extern u16 D_030056A4;
extern u16 D_030056A6;
extern u16 D_0300569C;
extern u8 D_0300568C;
extern u8 D_03000080;

void func_080785C0(u8 a, u8 b, u8 c, u8 d, u8 e)
{
    D_0300004C |= 0x4000;
    D_030056A4 = (a << 8) | c;
    D_030056A6 = (b << 8) | d;
    D_0300569C = (D_0300569C & 0xFF) | (e << 8);
    D_0300568C = 1;
    D_03000080 |= 2;
}
