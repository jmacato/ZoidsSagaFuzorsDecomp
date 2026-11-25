#include "types.h"

struct Sprite
{
    u32 flags;
    u32 field_4;
    s32 depth;
    u8 padC[0x12];
    s16 field_1E;
    u8 pad20[0x20];
};

extern struct Sprite D_030031C8[128];
extern struct Sprite *D_030051C8[128];
extern u8 D_030053C8;

void func_0807721C(void)
{
    s16 i, j;
    struct Sprite *s;
    struct Sprite *t;
    s32 ks, kt;

    D_030053C8 = 0;
    for (i = 0; i < 128; i++)
    {
        s = &D_030031C8[i];
        if (s->flags & 1)
        {
            D_030051C8[D_030053C8] = s;
            D_030053C8++;
        }
        else
            s->flags &= ~2;
    }
    for (i = 1; i < D_030053C8; i++)
    {
        s = D_030051C8[i];
        if (!(s->flags & 0x2000000))
            ks = s->depth;
        else
            ks = s->field_1E;
        for (j = i - 1; j >= 0; j--)
        {
            t = D_030051C8[j];
            if (!(t->flags & 0x2000000))
                kt = t->depth;
            else
                kt = t->field_1E;
            if ((s->flags & 0xC0) >= (t->flags & 0xC0))
            {
                if ((s->flags & 0xC0) != (t->flags & 0xC0))
                    break;
                if ((s->flags & 0x300) >= (t->flags & 0x300))
                {
                    if ((s->flags & 0x300) != (t->flags & 0x300))
                        break;
                    if (!(s->flags & 0x40000))
                        break;
                    if ((t->flags & 0x40000) && ks <= kt)
                        break;
                }
            }
            D_030051C8[j + 1] = t;
        }
        D_030051C8[j + 1] = s;
    }
}
