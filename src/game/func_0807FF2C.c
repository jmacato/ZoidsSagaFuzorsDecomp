#include "types.h"

struct GfxEntry
{
    const void *gfx;
    const void *pal;
};

extern const struct GfxEntry D_087B2910[][8];

void func_080C8B88(const void *, void *);
u32 func_0807806C(void *, void *, u16);

void func_0807FF2C(u16 set, u8 id, u16 tile, u16 palette, u8 *buf)
{
    const struct GfxEntry *entry = &D_087B2910[set][id];
    func_080C8B88(entry->gfx, buf);
    func_080C8B88(entry->pal, buf + 0x480);
    func_0807806C(buf, (void *)(0x06010000 + tile * 32), 0x480);
    func_0807806C(buf + 0x480, (void *)(0x05000200 + palette * 32), 0x20);
}
