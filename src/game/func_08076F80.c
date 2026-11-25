#include "types.h"

void func_08075470(void);

extern void (*D_03000000[])(void);

u32 func_08076F80(u8 id)
{
    return D_03000000[id] != func_08075470;
}
