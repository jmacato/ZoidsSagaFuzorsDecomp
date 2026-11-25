#include "types.h"

struct Obj
{
    u8 pad[8];
    u8 e[1][2];
};

void func_080BFAC4(struct Obj *obj, u8 i)
{
    if (obj->e[i][0])
        obj->e[i][0] = 0;
}
