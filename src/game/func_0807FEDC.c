#include "types.h"

struct GfxEntry
{
    const void *gfx;
    const void *pal;
};

extern const struct GfxEntry D_087B2910[][8];

void func_080C8B84(const void *, void *);
void func_0807F860(const void *, void *, void *);

void func_0807FEDC(u16 set, u8 id, u16 tile, u16 palette)
{
    const struct GfxEntry *entry = &D_087B2910[set][id];
    func_080C8B84(entry->gfx, (void *)(0x06010000 + tile * 32));
    func_0807F860(entry->pal, (void *)(0x05000200 + palette * 32), (void *)0x02001480);
}
