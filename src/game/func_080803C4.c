#include "types.h"

struct Packet
{
    u8 seq;
    u8 done;
    u8 data[14];
};

extern u8 D_03005810;
extern s32 D_03005808;
extern u8 D_030057F4;
extern struct Packet D_03000AD4[2];
extern struct Packet D_03000AC4;
extern u8 *D_030057F8;
extern u8 *D_03005800;

u8 func_080801F4(u8);

u32 func_080803C4(void)
{
    u8 i;
    u8 *p;
    u8 seq;
    u8 *dst;
    u8 *src;
    u8 n;

    if (func_080801F4(0) != 1)
        return 0;
    if (D_03005810 == 0)
        return 1;
    if (D_03005810 > 1 && D_03005808 <= 0)
    {
        if (D_030057F4)
        {
            p = &D_03000AD4[1].seq;
            seq = *p;
            if (seq != 0)
                return 0;
            p = &D_03000AD4[0].done;
            if (*p == 0)
                goto finish;
        }
        else
        {
            seq = D_03000AD4[0].seq;
            if (seq != 0)
                return 0;
            if (D_03000AD4[1].done == 0)
            {
            finish:
                D_03005810 = seq;
                return 1;
            }
        }
        p = &D_03000AC4.done;
        *p = seq;
        return 0;
    }
    if (D_030057F4)
    {
        p = &D_03000AD4[1].seq;
        if (*p != D_03005810)
            return 0;
    }
    else if (D_03000AD4[0].seq != D_03005810)
    {
        return 0;
    }
    if (D_03005810 == 1)
    {
        src = D_030057F8;
        dst = D_03000AC4.data;
        for (i = 0; i < 14; i++)
            *dst++ = *src++;
    }
    else
    {
        dst = D_03000AC4.data;
        for (i = 0; i < 14; i++)
        {
            *dst = *D_03005800;
            D_03005800++;
            dst++;
            D_03005808--;
        }
    }
    p = &D_03000AC4.done;
    n = D_03005810;
    *p = n;
    D_03005810 = n + 1;
    return 0;
}
