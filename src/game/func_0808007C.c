#include "types.h"

extern const u8 D_080F077C[];
extern const u8 D_080F0874[];
extern const u8 D_080F089C[];
extern u16 D_0300004C;
extern u16 D_0300004E[];
extern s32 D_03000060[];

void func_080C8B84(const void *, void *);
void func_0807F860(const void *, void *, void *);

void func_0808007C(u8 bg, u16 charBase, u16 tileOfs, u16 pal, u16 screenBase)
{
    u16 *map;
    u16 x, y;

    func_080C8B84(D_080F077C, (u8 *)(0x06000000 + charBase * 0x4000) + tileOfs * 32);
    func_0807F860(D_080F0874, (void *)(0x05000000 + pal * 32), (void *)0x02001480);
    map = (u16 *)(0x06000000 + screenBase * 0x800);
    func_080C8B84(D_080F089C, map);
    for (y = 0; y < 20; y++)
    {
        for (x = 0; x < 32; x++)
        {
            *map = (*map + tileOfs) | (pal << 12);
            map++;
        }
    }
    D_0300004C |= 0x100 << bg;
    *(bg + D_0300004E) = (screenBase << 8) | (charBase << 2) | 3;
    D_03000060[bg * 2] = D_03000060[bg * 2 + 1] = 0;
}
