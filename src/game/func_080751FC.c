#include "types.h"

struct Task
{
    u8 priority;
};

extern struct Task *D_03000890;
extern struct Task *D_03000894;
extern u8 D_03000898;

void func_08075488(void);

void func_080751FC(void)
{
    struct Task *head = D_03000890;

    if (head != (struct Task *)-1)
    {
        D_03000894 = head;
        if (D_03000898)
        {
            *(vu16 *)0x04000200 |= 4;
            *(vu16 *)0x04000004 |= 0x20;
            D_03000898 = 0;
        }
        *(vu16 *)0x04000004 = (D_03000894->priority << 8) | (*(vu16 *)0x04000004 & 0xFF);
    }
    else if (D_03000898)
    {
        *(vu16 *)0x04000200 &= ~4;
        *(vu16 *)0x04000004 &= ~0x20;
        func_08075488();
    }
}
