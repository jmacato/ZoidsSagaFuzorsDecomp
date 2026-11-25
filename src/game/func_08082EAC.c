#include "types.h"

extern u8 D_02036A04[][0x12];
extern u8 *D_087A464C[];

u8 *func_08082EAC(u8 id, u8 n)
{
    switch (id)
    {
    case 1:
        return D_02036A04[n];
    default:
        return D_087A464C[id];
    case 0xFF:
        return D_087A464C[0x87];
    }
}
