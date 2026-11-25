#include "types.h"

struct Big
{
    u8 pad_0[0x244];
    u8 field_244;
    u8 pad_245[0xB];
    u8 *field_250;
    u8 pad_254[0x4F77 - 0x254];
    u8 field_4F77;
};

extern struct Big D_02031A0C;
void func_080A2D70(u8, u32, u32, u32, u8);
void func_080A0F00(u32);
void func_080A3358(void);

void func_080972F8(void)
{
    func_080A2D70(*D_02031A0C.field_250, 2, 0, 0x32C, D_02031A0C.field_244);
    func_080A0F00(0x32C);
    func_080A3358();
    D_02031A0C.field_4F77 = 1;
}
