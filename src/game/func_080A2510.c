#include "types.h"

struct State
{
    u8 pad_0[0x8CC];
    u8 field_8CC;
    u8 field_8CD;
};

struct Display
{
    s32 field_0;
    s32 field_4;
    s32 field_8;
};

extern struct State D_02036E7C;
extern struct Display D_03000060;

s16 func_08075AAC(u16 angle);
void func_080A24C8(void);

void func_080A2510(void)
{
    struct Display *disp;
    s32 v;
    s32 base;
    switch (D_02036E7C.field_8CC)
    {
    case 2:
        if ((D_02036E7C.field_8CD & 0x7F) == 0 || (D_02036E7C.field_8CD & 0x7F) == 0x40)
        {
            func_080A24C8();
            break;
        }
    case 1:
        disp = &D_03000060;
        v = func_08075AAC(D_02036E7C.field_8CD * 2);
        base = disp->field_0;
        if (D_02036E7C.field_8CD & 1)
            disp->field_8 = base - v * 8;
        else
            disp->field_8 = base + v * 8;
        D_02036E7C.field_8CD++;
        break;
    }
}
