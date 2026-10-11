#include "types.h"

extern const void *const D_087AED7C[];
extern const void *const D_087AEFE4[][8];

void func_080C8B84(const void *, void *);
void func_0807F860(const void *, void *, void *);

void func_0807FB7C(u8 set, u8 id, u16 tile, u8 palette)
{
    func_080C8B84(D_087AED7C[set], (void *)(0x06010000 + tile * 32));
    func_0807F860(D_087AEFE4[set][id], (void *)(0x05000200 + palette * 32), (void *)0x02001480);
}
