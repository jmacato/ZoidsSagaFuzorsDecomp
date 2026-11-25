#include "types.h"

struct Obj
{
    u8 pad_0[0x6E];
    s16 field_6E;
};

s16 func_080BD430(struct Obj *);

s32 func_0808A904(struct Obj *obj)
{
    return func_080BD430(obj) > obj->field_6E;
}
