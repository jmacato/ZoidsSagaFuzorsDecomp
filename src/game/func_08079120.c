#include "types.h"

struct Entry
{
    u16 win;
    u16 pad2;
    u32 field_4;
};

extern u8 D_030056B6;
extern u8 D_030056B4;
extern u8 D_030056B5;
extern u16 D_03005698;
extern struct Entry D_02000000[2][160];

void func_08079120(void)
{
    struct Entry *entry = D_02000000[D_030056B6 ^ 1];
    u8 i;
    u16 x;

    for (i = 0; i < 160; i++)
    {
        if (D_030056B4 == 0)
        {
            s32 w = 240 - D_03005698;
            s32 half = 80;
            x = i < 80 ? w + half - i : w - half + i;
            if ((s16)x < 0)
                x = 0;
            else if ((s16)x > 240)
                x = 240;
            if (D_030056B5 == 0)
                entry->win = x;
            else
                entry->win = (s16)x * 256 | 240;
        }
        else
        {
            s32 w = D_03005698;
            s32 half = 80;
            x = i < 80 ? w - half + i : w + half - i;
            if ((s16)x < 0)
                x = 0;
            else if ((s16)x > 240)
                x = 240;
            if (D_030056B5 == 0)
                entry->win = (s16)x * 256 | 240;
            else
                entry->win = x;
        }
        entry++;
    }
}
