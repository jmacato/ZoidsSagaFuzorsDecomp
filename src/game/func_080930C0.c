#include "types.h"

struct Cfg
{
    u8 pad_0[0xC];
    u8 field_C;
};

extern struct Cfg D_02020E3C;
extern u16 *D_0201F5BC;
extern u32 D_0201F5C4;
extern u16 D_0201F5C8;

void func_080930C0(void)
{
    u8 i;
    u8 j;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 6; j++)
        {
            if (D_02020E3C.field_C == 0)
                (D_0201F5BC + j)[i * 32 + 0x18] = D_0201F5C4;
            else
                (D_0201F5BC + j)[i * 32 + 0x18] = (D_0201F5C4 + 0x20 + j + i * 6) | D_0201F5C8;
        }
    }
}
