#include "types.h"

struct Copy
{
    const void *src;
    void *dst;
    u32 size;
};

struct Rect
{
    u16 *src[2][2];
    u16 *dst[2][2];
    u8 countI;
    u8 countJ;
    u8 width;
    u8 pad23;
    u8 mode[2];
    u8 rows[2];
};

struct Transfer
{
    u32 flags;
    union
    {
        struct Copy copy;
        struct Rect rect;
    } u;
};

extern struct Transfer D_030053CC[16];

void func_080C8B7C(const void *, void *, u32);

void func_080783AC(void)
{
    u8 i, n, j, k;
    u16 *src;
    u16 *dst;
    struct Transfer *r;

    for (n = 0; n < 16; n++)
    {
        struct Transfer *t = &D_030053CC[n];
        if (!(t->flags & 1))
            continue;
        switch (t->flags & 2)
        {
        case 0:
            func_080C8B7C(t->u.copy.src, t->u.copy.dst, (t->u.copy.size / 2) & 0x1FFFFF);
            break;
        case 2:
            r = t;
            for (i = 0; i < r->u.rect.countI; i++)
            {
                for (j = 0; j < r->u.rect.countJ; j++)
                {
                    src = r->u.rect.src[i][j];
                    dst = r->u.rect.dst[i][j];
                    for (k = 0; k < r->u.rect.rows[j]; k++)
                    {
                        func_080C8B7C(src, dst, r->u.rect.mode[i]);
                        src += r->u.rect.width;
                        dst += 32;
                    }
                }
            }
            break;
        }
        D_030053CC[n].flags &= ~1;
    }
}
