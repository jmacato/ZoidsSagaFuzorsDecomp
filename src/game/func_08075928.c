#include "types.h"

struct Timer
{
    struct Timer *next;
    void (*func)(u32);
    u32 arg;
    u8 delay;
};

extern struct Timer D_03000B20[];

void func_08075928(void)
{
    struct Timer *timer;

    for (timer = D_03000B20; timer->next != 0; timer++)
    {
        if (timer->func != (void (*)(u32))-1)
        {
            if (timer->delay == 0)
            {
                timer->func(timer->arg);
                timer->func = (void (*)(u32))-1;
            }
            else
            {
                timer->delay--;
            }
        }
    }
}
