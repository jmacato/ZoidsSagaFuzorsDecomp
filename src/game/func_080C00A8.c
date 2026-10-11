#include "types.h"

struct Stats
{
    u8 pad0[0xE];
    s16 field_E;
    u8 pad10[2];
    s16 field_12;
};

struct Obj
{
    u8 pad0[0x6E];
    s16 capacity;
};

s16 func_080BD430(struct Obj *obj);

void func_080C00A8(struct Stats *stats, struct Obj *obj)
{
    s16 weight = func_080BD430(obj);
    if (weight > obj->capacity)
    {
        if (weight - obj->capacity < obj->capacity)
        {
            stats->field_E = stats->field_E * (obj->capacity * 2 - weight) / obj->capacity;
            stats->field_12 = stats->field_12 * (obj->capacity * 2 - weight) / obj->capacity;
        }
        else
        {
            stats->field_E = stats->field_12 = 0;
        }
    }
}
