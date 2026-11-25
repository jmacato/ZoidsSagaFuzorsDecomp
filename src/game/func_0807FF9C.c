#include "types.h"

struct GfxEntry
{
    const void *gfx;
    const void *pal;
};

void func_080C8B84(const void *, void *);
void func_0807F860(const void *, void *, void *);

void func_0807FF9C(const struct GfxEntry *table, u8 id, u16 tile, u16 palette)
{
    const struct GfxEntry *entry = &table[id];
    func_080C8B84(entry->gfx, (void *)(0x06010000 + tile * 32));
    func_0807F860(entry->pal, (void *)(0x05000200 + palette * 32), (void *)0x02001480);
}
