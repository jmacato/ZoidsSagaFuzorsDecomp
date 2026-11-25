#include "types.h"

struct Obj
{
    u32 flags;
};

struct Task
{
    u8 pad_0[0x8C];
    s32 field_8C;
    s32 field_90;
};

struct State
{
    u8 stage;
    u8 pad_1[0x99];
    u8 field_9A;
    u8 field_9B;
    u8 field_9C;
    u8 pad_9D;
    u16 field_9E;
    u16 field_A0;
    u8 pad_A2[2];
    u8 buf[1];
};

extern struct State D_02036E7C;
extern struct Obj *D_02030B4C[3];
extern struct Task *D_02030B48;
extern const void *const D_087AA7D8[][10];

void func_080A05A0(void);
void func_080C8B88(const void *src, void *dst);

void func_080A05BC(u8 n)
{
    D_02036E7C.field_9A = n;
    if (n <= 3)
    {
        if (n <= 2 && D_02030B4C[n] != 0)
        {
            D_02030B4C[n]->flags &= ~8;
            D_02036E7C.field_9B = 2;
            D_02036E7C.field_9C = 0;
            return;
        }
        func_080A05A0();
        return;
    }
    n -= 4;
    if (D_087AA7D8[D_02036E7C.stage][n] != 0)
    {
        func_080C8B88(D_087AA7D8[D_02036E7C.stage][n], D_02036E7C.buf);
        if (D_02036E7C.stage == 0x11 && n == 2)
            D_02030B48->field_8C = 1;
        else if (D_02036E7C.stage == 0x29 && n == 1)
        {
            D_02030B48->field_8C = 1;
            D_02030B48->field_90 = 0;
        }
        D_02036E7C.field_9B = 1;
        D_02036E7C.field_9C = 0;
        D_02036E7C.field_9E = 0;
        D_02036E7C.field_A0 = 0;
        return;
    }
    if (D_02036E7C.stage == 7 && n == 1)
    {
        D_02030B48->field_8C = 1;
        D_02036E7C.field_9B = 2;
        D_02036E7C.field_9C = 0;
        return;
    }
    if (D_02036E7C.stage == 0x29)
    {
        if (n == 0)
        {
            D_02030B48->field_8C = 1;
            D_02030B48->field_90 = 2;
            D_02036E7C.field_9B = 2;
            D_02036E7C.field_9C = 0;
            return;
        }
        if (n == 2)
        {
            D_02030B48->field_8C = 1;
            D_02030B48->field_90 = 1;
            D_02036E7C.field_9B = 2;
            D_02036E7C.field_9C = 0;
            return;
        }
    }
    if (D_02036E7C.stage == 0x2A && n == 0)
    {
        D_02030B48->field_8C = 1;
        D_02036E7C.field_9B = 2;
        D_02036E7C.field_9C = 0;
        return;
    }
    if (D_02036E7C.stage == 0x7E && n == 2)
    {
        D_02030B48->field_8C = 1;
        D_02036E7C.field_9B = 2;
        D_02036E7C.field_9C = 0;
        return;
    }
    if (D_02036E7C.stage == 0x7F && n == 2)
    {
        D_02030B48->field_8C = 1;
        D_02036E7C.field_9B = 2;
        D_02036E7C.field_9C = 0;
        return;
    }
    func_080A05A0();
}
