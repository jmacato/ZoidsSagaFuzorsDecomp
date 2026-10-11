#include "types.h"

struct Data
{
    u8 pad0[0x2208];
    u8 slots[6];
};

extern struct Data D_02031A0C;
extern void *D_087A43E0[];
extern u8 D_080F5C64[];

void func_0807BD4C(u8);
u8 *func_0809A908(u8, u8);
void func_0807B748(void *, u8, u8, u8, s32);

void func_080C2920(void)
{
    u8 i;
    func_0807BD4C(4);
    for (i = 0; i < 6; i++)
    {
        if (D_02031A0C.slots[i] != 0xFF)
            func_0807B748(D_087A43E0[*func_0809A908(0, D_02031A0C.slots[i])], 0, 4, 0, i * 2);
        else
            func_0807B748(D_080F5C64, 0, 4, 0, i * 2);
    }
}
