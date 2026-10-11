#include "types.h"

struct Actor
{
    u8 flags;
    u8 pad_1[2];
    u8 kind;
    s32 pos[2];
    u8 pad_C[0x38];
};

struct Map
{
    u8 pad_0[0x18];
    u8 mode;
    u8 pad_19[0x53];
    struct Actor actors[14];
};

extern struct Map D_020209D8;
s16 func_08075AF8(s16);
s16 func_08075AAC(s16);
s32 func_08081F04(u8, s32, s32);
s32 func_08081FB0(u8, u16, s32, s32);

#define ABS_DIFF(a, b) ((a) - (b) < 0 ? (b) - (a) : (a) - (b))

s32 func_08089524(void *unused, u8 layer, s32 *px, s32 *py)
{
    s32 nx;
    s32 ny;
    u8 i;
    u8 k;
    u8 j;
    s32 tx;
    s32 ty;

    for (i = 0; i < 14; i++)
    {
        if ((D_020209D8.actors[i].flags & 1) && D_020209D8.actors[i].kind == 7
            && ABS_DIFF(*px, D_020209D8.actors[i].pos[0]) <= 0x27FF
            && ABS_DIFF(*py, D_020209D8.actors[i].pos[1]) <= 0x27FF)
        {
            for (k = 0; k < 4; k++)
            {
                nx = *px + func_08075AF8(k * 64) * 40;
                ny = *py + func_08075AAC(k * 64) * 40;
                for (j = 0; j < 14; j++)
                {
                    if ((D_020209D8.actors[j].flags & 1) && D_020209D8.actors[j].kind == 7
                        && ABS_DIFF(nx, D_020209D8.actors[j].pos[0]) <= 0x27FF
                        && ABS_DIFF(ny, D_020209D8.actors[j].pos[1]) <= 0x27FF)
                        break;
                }
                if (j != 14)
                    continue;
                if (D_020209D8.mode != 0)
                {
                    tx = nx / 4096;
                    ty = ny / 4096;
                    if (!func_08081F04(layer, tx - 1, ty - 1) && !func_08081F04(layer, tx, ty - 1)
                        && !func_08081F04(layer, tx - 1, ty) && !func_08081F04(layer, tx, ty))
                        break;
                }
                else
                {
                    tx = nx / 2048;
                    ty = ny / 2048;
                    if (!func_08081FB0(layer, 0, tx - 1, ty - 1) && !func_08081FB0(layer, 0, tx, ty - 1)
                        && !func_08081FB0(layer, 0, tx + 1, ty - 1) && !func_08081FB0(layer, 0, tx - 1, ty)
                        && !func_08081FB0(layer, 0, tx, ty) && !func_08081FB0(layer, 0, tx + 1, ty)
                        && !func_08081FB0(layer, 0, tx - 1, ty + 1) && !func_08081FB0(layer, 0, tx, ty + 1)
                        && !func_08081FB0(layer, 0, tx + 1, ty + 1))
                        break;
                }
            }
            if (k < 4)
                break;
        }
    }
    if (i == 14)
        return 0;
    *px = nx;
    *py = ny;
    return 1;
}
