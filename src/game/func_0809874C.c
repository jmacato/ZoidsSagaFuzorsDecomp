#include "types.h"

struct Game
{
    u8 pad_0[0x244];
    u8 field_244;
    u8 pad_245[7];
    s32 field_24C;
    u8 *field_250;
    u8 pad_254[0x4D23];
    u8 field_4F77;
};

extern struct Game D_02031A0C;
extern u16 D_03000056;
extern u16 D_0300005A;

void func_080A2D70(u8 a, u8 b, u8 c, u16 d, u8 e);
void func_080A0F00(u16 a);
void func_080A3358(void);
void func_080C8FCC(u32 frames);
void func_08093140(u8 a, s32 b, u8 *c, u8 d);
void func_08075F20(u16 se);
s32 func_080A1B9C(void);

void func_0809874C(s32 won)
{
    func_080A2D70(*D_02031A0C.field_250, 2, 1, 0x32E, D_02031A0C.field_244);
    func_080A0F00(0x32E);
    func_080A3358();
    D_03000056 = 0xBF;
    D_0300005A = 0;
    do
    {
        D_0300005A++;
        func_080C8FCC(1);
    } while (D_0300005A < 16);
    func_08093140(D_02031A0C.field_244, D_02031A0C.field_24C, D_02031A0C.field_250, 2);
    if (won == 0)
        func_08075F20(0xE1);
    else
        func_08075F20(0xE2);
    while (!func_080A1B9C())
    {
        if (D_0300005A != 0)
        {
            if (--D_0300005A == 0)
                D_03000056 = 0;
        }
        func_080C8FCC(1);
    }
    D_02031A0C.field_4F77 = 1;
}
