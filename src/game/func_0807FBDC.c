#include "types.h"

extern const void *const D_087AED7C[];
extern const void *const D_087AEFE4[][8];

void func_080C8B88(const void *, void *);
u32 func_0807806C(void *, void *, u16);

void func_0807FBDC(u8 set, u8 id, u16 tile, u8 palette, u8 *buf)
{
    func_080C8B88(D_087AED7C[set], buf);
    func_080C8B88(D_087AEFE4[set][id], buf + 0x800);
    func_0807806C(buf, (void *)(0x06010000 + tile * 32), 0x800);
    func_0807806C(buf + 0x800, (void *)(0x05000200 + palette * 32), 0x20);
}
