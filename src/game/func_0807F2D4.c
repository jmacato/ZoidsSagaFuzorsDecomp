#include "types.h"

struct Save
{
    u8 pad0[0x7A5C];
    u32 money;
};

extern struct Save D_02020E4C;

u32 func_0807F2D4(u32 amount)
{
    u32 money = D_02020E4C.money + amount;
    u32 result;

    if (money > 999999999)
    {
        D_02020E4C.money = 999999999;
        result = 0;
    }
    else
    {
        D_02020E4C.money = money;
        result = 1;
    }
    return result;
}
