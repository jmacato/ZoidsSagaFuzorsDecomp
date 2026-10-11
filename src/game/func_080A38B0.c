#include "types.h"

extern s32 D_020378EC[][4];

s32 func_08075F20(u16);

s32 func_080A38B0(u8 id)
{
    return func_08075F20(D_020378EC[id][3]);
}
