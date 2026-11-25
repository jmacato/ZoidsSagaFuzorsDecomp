#include "types.h"

extern u8 *D_0201F6E0[];
extern u8 D_08734CAC[];

void func_08083C5C(u16 id, s16 target, u8 arg)
{
    u8 **pc = &D_0201F6E0[id];
    u8 depth = 0;
    u8 n = 0;
    u8 counts[4];
    u32 i;
    u8 cnt;

    for (;;)
    {
        if (target == 15 || target == 16)
        {
            if (**pc == 0xE || **pc == 0x19 || **pc == 0x1A || **pc == 0x1B || **pc == 0x1C)
                depth++;
        }
        if (target == 0x12 && **pc == 0x11)
        {
            counts[n] = 0;
            n++;
        }
        switch (**pc)
        {
        case 9:
            cnt = (*pc)[1];
            *pc += 2;
            for (i = 0; i < cnt; i++)
                *pc += 4;
            break;
        case 0x20:
            *pc += 2;
            if (**pc != 0)
            {
                do
                {
                    if (**pc == 1)
                        *pc += 1;
                    else if (**pc == 2)
                        *pc += 2;
                    else if (**pc == 0xD && n != 0)
                        counts[n - 1]++;
                } while (*++*pc != 0);
            }
            *pc += 1;
            break;
        default:
            *pc += D_08734CAC[**pc];
            break;
        }
        if ((target == 15 || target == 16) && **pc == target)
        {
            if (depth == 1)
                break;
            depth--;
        }
        if (target == 0x12 && **pc == 0x12)
        {
            if (n == 1)
            {
                if ((*pc)[1] == arg)
                    break;
            }
            else if (--counts[n - 1] == 0)
                n--;
        }
        if (target == -1 || **pc == target)
        {
            if (!(target == 15 || target == 16) && target != 0x12)
                break;
        }
    }
}
