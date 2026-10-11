#include "types.h"

struct Actor
{
    u8 flags;
    u8 id;
    u8 pad_2;
    u8 field_3;
    s32 x;
    s32 y;
    s32 field_C;
    s32 field_10;
    u8 pad_14[0x30];
};

extern struct Actor D_02020A44[14];
s32 func_08082E58(struct Actor *);

void func_08081D68(struct Actor *a)
{
    u8 i;
    struct Actor *b;
    s32 ax, ay, by, dx, dy, ex, ey;
    if ((a->field_3 == 6 || a->field_3 == 7) || a->field_3 == 0xFF || (a->flags & 4))
        return;
    for (i = 0; i < 14; i++)
    {
        b = &D_02020A44[i];
        if ((b->flags & 1) && b != a && b->field_3 != 6 && b->field_3 != 7 && b->field_3 != 0xFF && !(b->flags & 4))
        {
            ay = a->y + ((u8)func_08082E58(a) ? 0 : 0x800);
            by = b->y + ((u8)func_08082E58(b) ? 0 : 0x800);
            ax = a->x;
            dx = ax + a->field_C - b->x;
            dy = ay + a->field_10 - by;
            if (dx < 0)
                dx = -dx;
            if (dy < 0)
                dy = -dy;
            if (dx <= 0xFFF && dy <= 0xFFF)
            {
                dx = ax - b->x;
                ex = dx;
                by = ay - by;
                ey = by;
                if (dx < 0)
                    dx = -dx;
                if (by < 0)
                    by = -by;
                if (dx >= by)
                {
                    if (ex >= 0)
                        a->field_C = 0x1000 - dx;
                    else
                        a->field_C = dx - 0x1000;
                }
                else
                {
                    if (ey >= 0)
                        a->field_10 = 0x1000 - by;
                    else
                        a->field_10 = by - 0x1000;
                }
            }
        }
    }
}
