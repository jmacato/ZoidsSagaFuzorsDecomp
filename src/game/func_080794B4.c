#include "types.h"

extern u8 D_0300568C;

void func_08078910(void);
void func_08078A68(void);
void func_08078DC0(void);
void func_08079120(void);
void func_080791D8(void);

void func_080794B4(void)
{
    if (D_0300568C != 0)
    {
        switch (D_0300568C & 7)
        {
        case 1:
            break;
        case 2:
            func_08078910();
            break;
        case 3:
            func_08078A68();
            break;
        case 4:
            func_08078DC0();
            break;
        case 5:
            func_08079120();
            break;
        case 6:
            func_080791D8();
            break;
        }
    }
}
