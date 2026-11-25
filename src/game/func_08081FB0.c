#include "types.h"

struct Map
{
    u8 pad_0[0x14];
    u16 width;
    u16 height;
};

extern struct Map D_020209D8;
extern u8 *D_02031A18;

s32 func_08081FB0(void *unused, u16 flag, s32 x, s32 y)
{
    u8 mask;
    if (x < 0 || y < 0 || x >= D_020209D8.width || y >= D_020209D8.height)
        return 1;
    mask = 0xC0;
    if (flag == 0)
        mask = 0x80;
    return mask & D_02031A18[x + y * D_020209D8.width];
}
