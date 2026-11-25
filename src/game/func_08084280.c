#include "types.h"

struct Actor
{
    u8 flags;
    u8 pad_1;
    u8 id;
    u8 field_3;
    u8 pad_4[8];
    s32 field_C;
    s32 field_10;
    u8 field_14;
    u8 pad_15[0x2F];
};

struct Actors
{
    struct Actor actors[14];
    struct Actor *current;
};

extern struct Actors D_02020A44;
u8 func_08080C54(u8);
void func_08084078(struct Actor *, u8);
void func_08083C5C(u8, s32, s32);

s32 func_08084280(u8 id, u8 **pc)
{
    struct Actor *a;
    u8 *p;
    u8 cur, prev;
    u8 slot = func_08080C54((*pc)[1]);
    if (slot != 0xFF)
    {
        a = &D_02020A44.actors[slot];
        p = *pc;
        cur = a->field_3;
        if (cur != p[2])
        {
            a->flags &= ~2;
            if (cur == 0)
                D_02020A44.current = 0;
            prev = a->field_3;
            a->field_3 = (*pc)[2];
            a->field_C = a->field_10 = 0;
            if (a->field_14 != 8)
                a->field_14 = 0;
            func_08084078(a, prev);
        }
    }
    func_08083C5C(id, -1, 0);
    return 0;
}
