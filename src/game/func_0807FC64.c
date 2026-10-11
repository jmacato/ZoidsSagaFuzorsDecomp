#include "types.h"

struct GfxEntry
{
    const void *gfx;
    const void *pal;
};

extern u16 D_03000052;
extern const struct GfxEntry D_087B1960[][3];
extern const u8 D_0848F730[];
extern const u8 D_0848FD4C[];

void func_080C8B84(const void *, void *);
void func_0807F860(const void *, void *, void *);

void func_0807FC64(u8 id, u8 sub, u8 charBase, u8 screenBase, u8 pal)
{
    u16 *map;
    u16 t;
    u16 i;
    u8 x, y;

    if (id != 0xFF)
    {
        D_03000052 = 0x80 | (screenBase << 8) | (pal << 2) | 3;
        func_080C8B84(D_087B1960[id][sub > 2 ? sub - 2 : 0].gfx, (void *)(0x06000000 + charBase * 0x4000));
        func_0807F860(D_087B1960[id][sub > 2 ? sub - 2 : 0].pal, (void *)0x05000080, (void *)0x02001480);
        map = (u16 *)(0x06000000 + screenBase * 0x800);
        t = (u8)(charBase - pal) << 8;
        for (y = 0; y < 32; y++)
        {
            for (x = 0; x < 16; x++)
            {
                if (y < 16)
                {
                    map[0] = t;
                    map[16] = t;
                    t++;
                }
                else
                {
                    map[16] = 0;
                    map[0] = 0;
                }
                map++;
            }
            map += 16;
        }
    }
    else
    {
        D_03000052 = (screenBase << 8) | (charBase << 2) | 3;
        func_080C8B84(D_0848F730, (void *)(0x06000000 + charBase * 0x4000));
        map = (u16 *)(0x06000000 + charBase * 0x4000 + 0x7A0);
        for (i = 0; i < 16; i++)
            *map++ = 0;
        func_080C8B84(D_0848FD4C, (void *)(0x06000000 + screenBase * 0x800));
        map = (u16 *)(0x06000000 + screenBase * 0x800);
        for (i = 0; i < 0x400; i++)
        {
            if (i < 0x100)
                *map |= 0x4000;
            else
                *map = 0x3D;
            map++;
        }
        *(vu16 *)0x05000000 = 0;
    }
}
