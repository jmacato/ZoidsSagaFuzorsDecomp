#include "types.h"

struct State
{
    u8 pad_0[0x8F4];
    u8 field_8F4;
    u8 pad_8F5[0x1F];
    s32 field_914;
};

extern struct State D_02036E7C;
extern u8 D_02037770;

u8 func_080A1D20(void);
u8 func_080A0B54(void);
void func_080A0F8C(void);
s32 func_080A1B9C(void);
void func_080A1318(void);
void func_080A1BE0(void);
void func_080A1E6C(void);
void func_080A2510(void);
void func_080A0758(void);
void func_080A3034(void);
void func_080C8FCC(u32 frames);

void func_080A3158(void)
{
    u8 *active = &D_02037770;
    for (;;)
    {
        if (*active != 0)
        {
            if (func_080A1D20() && func_080A0B54())
                func_080A0F8C();
            if (D_02036E7C.field_8F4 == 2 && func_080A1B9C())
            {
                if (++D_02036E7C.field_914 == 30)
                    D_02036E7C.field_8F4 = 0;
            }
        }
        func_080A1318();
        func_080A1BE0();
        func_080A1E6C();
        func_080A2510();
        func_080A0758();
        func_080A3034();
        func_080C8FCC(1);
    }
}
