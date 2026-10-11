#include "types.h"

struct Flags
{
    u8 pad_0[0xC];
    u8 field_C;
};

extern u8 D_02036987;
extern struct Flags D_02020E3C;
extern u16 D_0300000E;

void func_08075F20(u16 se);
void func_080930C0(void);
void func_080C8FCC(u32 frames);

void func_0809961C(void)
{
    for (;;)
    {
        if (D_02036987 == 0)
        {
            if (D_0300000E & 4)
            {
                func_08075F20(0xCD);
                D_02020E3C.field_C ^= 1;
                func_080930C0();
            }
        }
        else
            D_02036987 &= ~4;
        func_080C8FCC(1);
    }
}
