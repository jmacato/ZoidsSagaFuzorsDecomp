#include "types.h"

extern u8 D_03005810;
extern u8 D_03005811;
extern u8 D_03005812;
extern u8 D_03005813;

u32 func_080801D0(u32 arg)
{
    D_03005812 = 0;
    D_03005813 = 0;
    D_03005810 = D_03005811 = 0;
    return arg;
}
