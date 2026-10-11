#include "types.h"

void func_080C8B88(const void *, void *);
u32 func_0807806C(void *, void *, u16);

void func_0807FFE0(const u8 *(*table)[2], u8 id, u16 tile, u16 palette, u8 *buf)
{
    const u8 **entry = table[id];
    u32 gfxSize = entry[0][1] | (entry[0][2] << 8) | (entry[3][3] << 16);
    u32 palSize = entry[1][1] | (entry[1][2] << 8) | (entry[3][3] << 16);

    func_080C8B88(entry[0], buf);
    func_080C8B88(entry[1], buf + gfxSize);
    func_0807806C(buf, (void *)(0x06010000 + tile * 32), gfxSize);
    func_0807806C(buf + gfxSize, (void *)(0x05000200 + palette * 32), palSize);
}
