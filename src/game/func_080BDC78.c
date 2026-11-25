#include "types.h"

struct Obj
{
    u8 pad0[0x68];
    s16 field_68;
    s16 field_6A;
    u8 pad6C[2];
    s16 capacity;
};

s16 func_080BD430(struct Obj *obj);

void func_080BDC78(struct Obj *obj)
{
    s16 weight = func_080BD430(obj);
    if (weight > obj->capacity)
    {
        if (weight - obj->capacity < obj->capacity)
        {
            obj->field_68 = obj->field_68 * (obj->capacity * 2 - weight) / obj->capacity;
            obj->field_6A = obj->field_6A * (obj->capacity * 2 - weight) / obj->capacity;
        }
        else
        {
            obj->field_68 = obj->field_6A = 0;
        }
    }
}
