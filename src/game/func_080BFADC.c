#include "types.h"

struct Obj
{
    u8 pad[8];
    u8 e[5][2];
};

struct Rate
{
    s16 value;
    u16 pad;
};

extern struct Rate D_08759AD8[];

s16 func_080BFADC(struct Obj *obj, u8 id)
{
    u8 i;
    for (i = 0; i < 5; i++)
    {
        if (obj->e[i][0] == id)
            return obj->e[i][1] * D_08759AD8[id].value;
    }
    return 0;
}
