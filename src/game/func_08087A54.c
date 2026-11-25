#include "types.h"

struct Script
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[2];
    u8 *regs[0x46];
    u8 *pcs[0x46];
    u16 field_234;
    u8 pad_236[0xEFF];
    u8 field_1135;
};

struct Map
{
    u16 id;
    u8 pad_2[0x426];
    u8 field_428;
};

extern struct Script D_0201F6DC;
extern struct Map D_020209D8;
extern s32 (*const D_08734DFC[])(u8, u8 **);
void func_080C8FCC(s32);
void func_0808359C(void);
void func_080836FC(void);
void func_08083BBC(u32);
void func_08083BF4(void);

s32 func_08087A54(void)
{
    s32 i;
    u8 **pc;
    u8 r;

    for (i = 0; i < 0x46; i++)
    {
        pc = &D_0201F6DC.regs[i];
        if (*pc == 0)
            continue;
        r = 0;
        while (r == 0)
        {
            if (D_0201F6DC.field_1 == 0)
            {
                u8 op = **pc;
                if (op == 0 || op == 0xB || op == 4 || op == 0xC || op == 0xD || op == 0xE || op == 0x11 || op == 0x20 || op == 0x35
                    || op == 0x46 || op == 0x47 || op == 0x48 || op == 0x49 || op == 0x61 || op == 0x62 || op == 0x63 || op == 0x64
                    || op == 0x65 || op == 0x66 || op == 0x67 || op == 0x68 || op == 0x69 || op == 0x6A || op == 0x6B || op == 0x6C
                    || op == 0x6D || op == 0x6E || op == 0x6F || op == 0x79 || op == 0x82 || op == 0x88)
                {
                    while (D_020209D8.field_428 != 0)
                    {
                        func_080C8FCC(1);
                        if (D_0201F6DC.field_1135 == 0)
                            D_020209D8.field_428 = 0;
                    }
                }
            }
            r = D_08734DFC[**pc](i, pc);
            if (r > 1)
                return r - 1;
            {
                u8 op = **pc;
                if (op == 0 || op == 0xB || op == 0xC || op == 0xD || op == 4 || op == 0x35 || op == 0x46 || op == 0x47 || op == 0x48
                    || op == 0x49 || op == 0x5B || op == 0x5C || op == 0x5D || op == 0x5E || op == 0x5F || op == 0x7A || op == 0x82
                    || op == 0x79 || op == 0x8F)
                    func_0808359C();
            }
        }
        if (D_020209D8.id != D_0201F6DC.field_234)
        {
            func_080836FC();
            func_08083BBC(D_020209D8.id);
            i = -1;
        }
    }
    func_08083BF4();
    return 0;
}
