#include "types.h"

struct Stats
{
    u8 flags;
    u8 pad1[3];
    s16 field_4;
    u8 pad6[6];
    s16 field_C;
    s16 field_E;
};

void func_080C0100(struct Stats *s)
{
    if (!(s->flags & 1))
    {
        if (s->field_C < 0)
            s->field_C = 0;
        else if (s->field_C > 9999)
            s->field_C = 9999;
    }
    else
    {
        if (s->field_C < 0)
            s->field_C = 0;
        else if (s->field_C > 9999)
            s->field_C = 9999;
        if (s->field_E < 0)
            s->field_E = 0;
        else if (s->field_E > 9999)
            s->field_E = 9999;
    }
    if (s->field_4 < 0)
        s->field_4 = 0;
    else if (s->field_4 > 9999)
        s->field_4 = 9999;
}
