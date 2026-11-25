#include "types.h"

#define REG_IME (*(vu16 *)0x04000208)
#define REG_WINOUT (*(vu16 *)0x0400004A)

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
    u8 pad_0[0x8C5];
    u8 field_8C5;
};

extern struct State D_02036E7C;
extern u8 D_03005814[];
extern u16 D_03000058;
extern struct Obj *D_02030B4C[3];
extern struct Group *D_02030B48;
extern u8 D_020378E0;
extern u8 D_020377E0[][128];
extern u16 D_0300004C;
extern u16 D_03000056;
extern u16 D_0300569E;

u8 func_08079724(void);
u8 func_080796EC(void);
s32 func_08076F80(u32 a);
void func_08076F30(u32 a);
void func_08076EE0(u32 a, void *b);
void func_080A2178(void);

void func_080A2278(u8 toggle)
{
    u8 i;
    if (D_02036E7C.field_8C5 == 0)
    {
        if (func_08079724() && func_080796EC())
        {
            if (func_08076F80(1) == 0)
                return;
            REG_IME = 0;
            func_08076F30(1);
            REG_IME = 1;
            return;
        }
        if (func_08076F80(1) == 0)
        {
            REG_IME = 0;
            func_08076EE0(1, D_03005814);
            REG_IME = 1;
        }
    }
    if (toggle)
    {
        if (D_02036E7C.field_8C5 == 1)
        {
            REG_IME = 0;
            func_08076EE0(1, D_03005814);
            D_03000058 = 0x1000;
            for (i = 0; i < 3; i++)
            {
                if (D_02030B4C[i])
                    D_02030B4C[i]->flags |= 0x100400;
            }
            if (D_02030B48)
            {
                for (i = 0; i < 16; i++)
                {
                    if (D_02030B48->objs[i])
                        D_02030B48->objs[i]->flags |= 0x100400;
                }
            }
            REG_IME = 1;
            D_02036E7C.field_8C5 = 0;
        }
        else if (D_02036E7C.field_8C5 == 2)
        {
            func_080A2178();
            return;
        }
        D_020378E0 ^= 1;
    }
    if (D_02036E7C.field_8C5 == 0)
    {
        if (D_020377E0[D_020378E0][0])
        {
            D_0300004C &= 0x7DFF;
            D_03000056 = 0;
        }
        else
        {
            D_0300004C |= 0x8200;
            D_03000056 = 0x1643;
        }
        D_0300569E = REG_WINOUT = 0x3E3F;
    }
}
