#include "types.h"

void func_080B453C(u8, u8, u8);
void func_0808AFB4(u8, u8, u8, void *, void *);
void func_0807B748(void *, s8, u8, s16, u8);
void func_0807A1A4(void);
s32 func_080B4610(s32 *, u8, u8);
void func_080B467C(void);

extern u8 D_0203198C[];
extern u8 D_020319CC[];

u8 func_080B469C(s32 value, u8 a, u8 b, u8 c, u8 d)
{
    u8 r;

    func_080B453C(b, d, a);
    do
    {
        func_0808AFB4(c, value, 10, D_0203198C, D_020319CC);
        func_0807B748(D_0203198C, 0, b, 0, d);
        func_0807A1A4();
    } while (func_080B4610(&value, b, 12) == 0);
    r = value;
    func_080B467C();
    return r;
}
