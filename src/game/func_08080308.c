#include "types.h"

extern u8 D_03005813;
extern u16 D_03000B18;
extern u32 D_03000B14;
extern u8 D_030057F4;

u8 func_080801F4(u8);
void func_08075DA8(u8, void (*)(void));
void func_08080258(void);

u32 func_08080308(void)
{
    u8 result;

    if (D_03005813 == 0)
    {
        D_03000B18 |= 1;
        D_03005813 = 1;
    }
    result = func_080801F4(0);
    if (result == 1)
    {
        if (D_03000B14 & 0x80)
            D_030057F4 = 1;
        else
            D_030057F4 = 0;
        func_08075DA8(6, func_08080258);
        return 1;
    }
    return 0;
}
