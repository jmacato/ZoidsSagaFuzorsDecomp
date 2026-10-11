#include "types.h"

struct SaveBlock
{
    const void *data;
    u32 size;
};

extern const struct SaveBlock D_08734614[];

u32 func_080C8B34(const u8 *, u8 *, u32);

u32 func_0807DA0C(u8 count)
{
    u8 *dst = (u8 *)0x0E000000;
    const struct SaveBlock *block = D_08734614;
    u8 i;
    u8 zero;

    for (i = 0; i < count; i++)
    {
        if (block->data == 0 && block->size == 0)
            return 0;
        dst += block->size + 5;
        block++;
    }
    zero = 0;
    if (func_080C8B34(&zero, dst, 1) != 0)
        return 0;
    return 1;
}
