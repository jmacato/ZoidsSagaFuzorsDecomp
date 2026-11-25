#include "types.h"

extern u16 D_02031488[2][160][2];
extern u8 D_02031988;

void func_0807DC04(u8 line, u16 a, u16 b)
{
    D_02031488[D_02031988 ^ 1][line][0] = a;
    D_02031488[D_02031988 ^ 1][line][1] = b;
}
