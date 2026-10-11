#include "types.h"

struct Task
{
    u8 id;
    u8 active;
    u8 pad2[2];
    s32 wait;
    s32 next;
    u8 padC[0x40];
};

extern struct Task D_03000BB4[];
extern struct Task *D_03000E44;

void func_08075D9C(void);
void func_08075DA8(u8, void (*)(void));

void func_08075D3C(void)
{
    u8 i;

    for (i = 0; i < 8; i++)
    {
        D_03000BB4[i].id = i + 1;
        D_03000BB4[i].active = 1;
        D_03000BB4[i].wait = -1;
        D_03000BB4[i].next = -1;
    }
    func_08075DA8(0, func_08075D9C);
    D_03000E44 = D_03000BB4;
}
