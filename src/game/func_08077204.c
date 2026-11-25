#include "types.h"

struct Unk08077204
{
    u32 flags;
    u8 pad4[0x14];
    u16 field_18;
    u16 field_1A;
    u16 field_1C;
};

void func_08077204(struct Unk08077204 *p, u16 val)
{
    p->field_18 = val;
    p->field_1A = 0;
    p->field_1C = 0;
    p->flags &= ~0x0100000C;
}
