#include "types.h"

struct Data
{
    u8 pad0[0x4E5B];
    u8 list[10];
    u8 pad4E65[0x4F84 - 0x4E65];
    u8 active;
    u8 target;
};

extern struct Data D_02031A0C;

void func_080C3BB0(void)
{
    u8 i;
    if (D_02031A0C.active == 1)
    {
        for (i = 0; i < 10; i++)
        {
            if (D_02031A0C.list[i] == D_02031A0C.target)
            {
                D_02031A0C.list[i] = 0;
                break;
            }
        }
    }
}
