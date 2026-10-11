#include "types.h"

struct Task
{
    u8 priority;
    u8 pad1[7];
    struct Task *prev;
    struct Task *next;
};

extern struct Task *D_03000890;
extern u8 D_03000898;

void func_080754C0(struct Task *task)
{
    struct Task *cur;
    struct Task *next;

    if (D_03000890 != (struct Task *)-1)
    {
        cur = D_03000890;
        for (;;)
        {
            if (cur->priority > task->priority)
            {
                task->prev = cur->prev;
                cur->prev = task;
                task->next = cur;
                if (D_03000890 == cur)
                    D_03000890 = task;
                break;
            }
            next = cur->next;
            if (next == (struct Task *)-1)
            {
                cur->next = task;
                task->prev = cur;
                task->next = next;
                break;
            }
            cur = next;
        }
    }
    else
    {
        D_03000890 = task;
        task->next = (struct Task *)-1;
        task->prev = (struct Task *)-1;
        D_03000898 = 1;
    }
}
