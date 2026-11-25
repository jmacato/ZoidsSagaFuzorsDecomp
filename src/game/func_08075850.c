#include "types.h"

struct Link
{
    u8 active;
    u8 pad1[3];
    u8 field_4;
};

extern u16 D_03000B18;
extern u32 D_03000B14;
extern u8 D_03000AD4[];
extern u8 D_03000AC4[];
extern struct Link D_030024B8;

u32 func_08076158(void *);
void func_0807626C(const void *);
void func_080760F0(void);

void func_08075850(void)
{
    if (D_03000B18 & 2)
    {
        u32 keys = func_08076158(D_03000AD4);
        D_03000B14 = keys;
        if (!(keys & 0x2000))
        {
            if (D_030024B8.field_4 == 0)
            {
                func_0807626C(D_03000AC4);
                D_03000B14 &= 0x7FFFFFFF;
            }
            else
            {
                D_03000B14 = keys | 0x80000000;
            }
        }
        func_080760F0();
    }
}
