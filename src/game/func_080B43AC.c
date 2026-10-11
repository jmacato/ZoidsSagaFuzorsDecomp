#include "types.h"

struct Ctx
{
    u8 pad_0[0x84];
    u8 digits;
    u8 cursor;
    u8 pad_86[2];
    s32 max;
    void *field_8C;
    void *field_90;
};

void func_080C8FCC(s32);

void func_08075F20(s32);

void func_08077204(void *, u16);

extern struct Ctx D_0201F5F8;

extern u16 D_030057EC;

extern u16 D_0300000E;

s32 func_080B43AC(s32 *value)
{
    s32 old;
    s32 step;
    s32 i;
    /* Keep r4 so agbcc shares the animation call tails. */
    register s32 current asm("r4");
    for (;;)
    {
        func_080C8FCC(1);
        if (D_030057EC & 0xC0)
        {
            old = *value;
            step = 1;
            for (i = 0; i < D_0201F5F8.cursor; i++)
                step *= 10;

            if (D_030057EC & 0x40)
            {
                if ((*value) > step)
                    *value = (*value) - step;
                else if (D_0201F5F8.cursor != 0)
                {
                    *value = (*value) + (D_0201F5F8.max - (D_0201F5F8.max % step));
                    if ((*value) > D_0201F5F8.max)
                        *value = (*value) - step;
                }
                else
                    *value = D_0201F5F8.max;
                if ((*value) != old)
                {
                    func_08075F20(0xCC);
                    func_08077204(D_0201F5F8.field_8C, 1);
                }
                else
                    func_08075F20(0x114);
            }
            else
            {
                if ((*value) <= (D_0201F5F8.max - step))
                {
                    current = *value;
                    *value = current + step;
                }
                else if (D_0201F5F8.cursor != 0)
                {
                    current = *value;
                    *value = current % step;
                    if ((*value) == 0)
                        *value = step;
                }
                else
                    *value = 1;
                if ((*value) != old)
                {
                    func_08075F20(0xCC);
                    func_08077204(D_0201F5F8.field_90, 1);
                }
                else
                    func_08075F20(0x114);
            }
            return 0;
        }
        if ((D_030057EC & 0x20) && (D_0201F5F8.cursor < (D_0201F5F8.digits - 1)))
        {
            func_08075F20(0xCC);
            D_0201F5F8.cursor++;
            return 2;
        }
        if ((D_030057EC & 0x10) && (D_0201F5F8.cursor != 0))
        {
            func_08075F20(0xCC);
            D_0201F5F8.cursor--;
            return 2;
        }
        if (D_0300000E & 1)
        {
            func_08075F20(0xCA);
            return 1;
        }
        if (D_0300000E & 2)
        {
            func_08075F20(0xCB);
            *value = 0;
            return 1;
        }
    }
}
