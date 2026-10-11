#include "types.h"

extern u16 D_03002352;
void func_080C7550(void);
s32 func_08075F5C(u16);
void func_08075F00(void);

void func_08075FF4(void)
{
    func_080C7550();
    if (D_03002352 != 0 && func_08075F5C(D_03002352) != 0)
        func_08075F00();
}
