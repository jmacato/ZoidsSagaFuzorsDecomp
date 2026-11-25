#include "types.h"

struct Obj
{
    u8 pad0[6];
    s16 field_6;
    s16 field_8;
    u8 padA[0x58];
    s16 stats[7];
};

void func_080BDCD8(struct Obj *obj)
{
    if (obj->stats[0] <= 0)
        obj->stats[0] = 1;
    else if (obj->stats[0] > 9999)
        obj->stats[0] = 9999;
    if (obj->stats[1] <= 0)
        obj->stats[1] = 1;
    else if (obj->stats[1] > 9999)
        obj->stats[1] = 9999;
    if (obj->stats[2] <= 0)
        obj->stats[2] = 1;
    else if (obj->stats[2] > 9999)
        obj->stats[2] = 9999;
    if (obj->stats[3] <= 0)
        obj->stats[3] = 1;
    else if (obj->stats[3] > 9999)
        obj->stats[3] = 9999;
    if (obj->stats[4] <= 0)
        obj->stats[4] = 1;
    else if (obj->stats[4] > 9999)
        obj->stats[4] = 9999;
    if (obj->stats[5] <= 0)
        obj->stats[5] = 1;
    else if (obj->stats[5] > 9999)
        obj->stats[5] = 9999;
    if (obj->stats[6] <= 0)
        obj->stats[6] = 1;
    else if (obj->stats[6] > 9999)
        obj->stats[6] = 9999;
    if (obj->field_6 > obj->stats[0])
        obj->field_6 = obj->stats[0];
    if (obj->field_8 > obj->stats[1])
        obj->field_8 = obj->stats[1];
}
