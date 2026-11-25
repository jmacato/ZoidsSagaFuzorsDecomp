#include "types.h"

struct Timer
{
    struct Timer *next;
    void (*func)(u32);
    u32 arg;
    u8 delay;
};

extern struct Timer D_03000B20[];

struct Timer *func_080758EC(void (*func)(u32), u32 arg)
{
    struct Timer *timer;

    for (timer = D_03000B20; timer->next != 0; timer++)
    {
        if (timer->func == (void (*)(u32))-1)
        {
            timer->func = func;
            timer->arg = arg;
            timer->delay = 0;
            return timer;
        }
    }
    return (struct Timer *)-1;
}
