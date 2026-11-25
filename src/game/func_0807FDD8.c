#include "types.h"

struct Portrait
{
    const void *gfx;
    const void *pal;
    const void *gfx2;
    const void *pal2;
};

extern const struct Portrait D_087B1BA0[];

void func_080C8B84(const void *, void *);
void func_0807F860(const void *, void *, void *);

void func_0807FDD8(u8 id, u8 charBase, u8 screenBase, u8 charBase2, u8 screenBase2)
{
    u16 *map;
    u16 t;
    u8 x, y;

    func_080C8B84(D_087B1BA0[id].gfx, (void *)(0x06000000 + charBase * 0x4000));
    func_0807F860(D_087B1BA0[id].pal, (void *)0x05000000, (void *)0x02001480);
    map = (u16 *)(0x06000000 + screenBase * 0x800);
    t = 0x100;
    for (y = 0; y < 8; y++)
    {
        for (x = 0; x < 4; x++)
        {
            map[0] = t;
            map[4] = t;
            map[0x40] = t;
            map[0x44] = t;
            map++;
            t += 0x202;
        }
        map += 4;
    }
    func_080C8B84(D_087B1BA0[id].gfx2, (void *)(0x06000000 + charBase2 * 0x4000));
    func_0807F860(D_087B1BA0[id].pal2, (void *)0x05000080, (void *)0x02001480);
    map = (u16 *)(0x06000000 + screenBase2 * 0x800);
    t = 0;
    for (y = 0; y < 16; y++)
    {
        for (x = 0; x < 16; x++)
        {
            map[0] = t;
            map[0x10] = t;
            map++;
            t++;
        }
        map += 16;
    }
}
