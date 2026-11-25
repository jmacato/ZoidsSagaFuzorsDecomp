#include "types.h"

struct Entry
{
    u32 win;
    u32 field_4;
};

extern u8 D_030056B6;
extern u8 D_0300569A;
extern struct Entry D_02000000[2][160];

void func_080791D8(void)
{
    struct Entry *entry = D_02000000[D_030056B6 ^ 1];
    u8 i;

    if (D_0300569A < 40)
    {
        for (i = 0; i < 160; i++)
        {
            if ((u8)(i % 40) <= D_0300569A)
            {
                if (!((i / 40) & 1))
                    entry->win = 0x78B4003C;
                else
                    entry->win = 0xB4F03C78;
            }
            else
            {
                entry->win = 0;
            }
            entry++;
        }
    }
    else if (D_0300569A < 80)
    {
        for (i = 0; i < 160; i++)
        {
            if ((u8)(i % 40) > 80 - D_0300569A)
                entry->win = 0x00F000F0;
            else if (!((i / 40) & 1))
                entry->win = 0x78B4003C;
            else
                entry->win = 0xB4F03C78;
            entry++;
        }
    }
    else
    {
        for (i = 0; i < 160; i++)
        {
            entry->win = 0x00F000F0;
            entry++;
        }
    }
}
