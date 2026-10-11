#include "types.h"

struct Obj
{
    u32 flags;
};

struct Group
{
    u8 pad_0[0xC];
    struct Obj *objs[16];
};

struct State
{
    u8 pad_0[0x8C6];
    u8 field_8C6;
};

extern struct State D_02036E7C;
extern u16 D_0300004C;
extern u16 D_0300569E;
extern u16 D_03000056;
extern u16 D_03000058;
extern struct Obj *D_02030B4C[3];
extern struct Group *D_02030B48;
extern u8 D_03000080;

void func_08076F30(u32 arg);

void func_080A2178(void)
{
    u8 i;
    *(vu16 *)0x04000208 = 0;
    func_08076F30(1);
    D_0300004C = (D_0300004C & 0x7DFF) | 0x400;
    D_0300569E = *(vu16 *)0x0400004A &= 0xFF;
    D_03000056 = 0;
    D_03000058 = 0;
    for (i = 0; i < 3; i++)
    {
        if (D_02030B4C[i])
            D_02030B4C[i]->flags &= ~0x100400;
    }
    if (D_02030B48)
    {
        for (i = 0; i < 16; i++)
        {
            if (D_02030B48->objs[i])
                D_02030B48->objs[i]->flags &= ~0x100400;
        }
    }
    D_03000080 &= ~8;
    *(vu16 *)0x04000208 = 1;
    D_02036E7C.field_8C6 = 0;
}
