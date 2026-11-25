#include "types.h"

struct Obj
{
    u8 pad0[8];
    u8 e[5][2];
};

extern u8 D_08759BB8[2][10];

u8 func_080BF9B4(struct Obj *obj, u8 id)
{
    u8 i, j;
    i = 0;
    if (obj->e[0][0] != id)
    {
        while (1)
        {
            for (j = 0; j < 10; j++)
            {
                if (obj->e[i][0] == D_08759BB8[0][j] && id == D_08759BB8[1][j])
                    break;
            }
            if (j < 10)
                break;
            i++;
            if (i >= 5 || obj->e[i][0] == id)
                break;
        }
    }
    return i;
}
