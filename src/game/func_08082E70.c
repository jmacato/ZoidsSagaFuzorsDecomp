#include "types.h"

extern u8 D_02030586[];
extern u8 *D_087A464C[];

u8 *func_08082E70(u8 id)
{
    switch (id)
    {
    case 1:
        return D_02030586;
    default:
        return D_087A464C[id];
    case 0xFF:
        return D_087A464C[0x87];
    }
}
