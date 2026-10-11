#include "types.h"

extern u8 D_0201F6DC;
void func_08083BF4(void);
void func_08088630(void);

s32 func_08083DD4(u8 id, u32 *pc)
{
    func_08083BF4();
    func_08088630();
    *pc = 0;
    D_0201F6DC = 0;
    return 1;
}
