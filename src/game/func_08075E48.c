#include "types.h"

extern u16 D_03002350;
extern u16 D_03002352;
extern u16 D_03002354;
void func_080C74D8(void);

void func_08075E48(void)
{
    D_03002350 = D_03002352 = D_03002354 = 0;
    func_080C74D8();
}
