#include "types.h"

struct State
{
    u8 pad_0[0x8C4];
    u8 field_8C4;
    u8 pad_8C5[0x2F];
    u8 field_8F4;
    u8 pad_8F5[0x23];
    void *objs[16];
};

extern struct State D_02036E7C;
extern u16 D_0300004C;
extern u16 D_03000056;
extern u8 D_03000081;
extern u8 D_030057F5;

void func_08077E6C(void *obj);
u8 func_080A2250(void);
void func_080A2178(void);
u8 func_080A24F0(void);
void func_080A24C8(void);
void func_080784F8(void);
void func_08078044(void);

void func_080A1204(void)
{
    u8 i;
    D_02036E7C.field_8F4 = 0;
    for (i = 0; i < 16; i++)
    {
        if (D_02036E7C.objs[i])
            func_08077E6C(D_02036E7C.objs[i]);
    }
    if (func_080A2250() <= 1)
        func_080A2178();
    if (!func_080A24F0())
        func_080A24C8();
    if (D_02036E7C.field_8C4)
    {
        D_0300004C = (D_0300004C & ~0x200) | 0x400;
        D_02036E7C.field_8C4 = 0;
    }
    D_03000056 = 0;
    func_080784F8();
    D_03000081 = D_030057F5 = 1;
    func_08078044();
}
