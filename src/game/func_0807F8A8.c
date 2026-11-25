#include "types.h"

struct Background
{
    const void *gfx;
    const void *map;
    const void *objGfx;
};

extern const struct Background D_087A8D34[];
extern const void *const D_087A9478[][8];
extern const void *const D_087AC010[][8];
extern const u32 D_08735FD0[][2];

void func_080C8B84(const void *, void *);
void func_080C8B88(const void *, void *);
void func_080C8B78(const void *, void *, u32);
void func_0807F860(const void *, void *, void *);
u32 func_08077DF0(u32, u32, u32);

u32 func_0807F8A8(u8 id, u8 pal, u8 charBase, u8 screenBase, u8 flip, u16 *buf)
{
    u32 zero;
    u16 *map;
    u16 x, y;

    func_080C8B84(D_087A8D34[id].gfx, (void *)(0x06000000 + charBase * 0x4000));
    func_0807F860(D_087A9478[id][pal], (void *)0x05000000, buf);
    map = (u16 *)(0x06000000 + screenBase * 0x800);
    if (flip == 0)
    {
        func_080C8B84(D_087A8D34[id].map, map);
    }
    else
    {
        func_080C8B88(D_087A8D34[id].map, buf);
        for (y = 0; y < 16; y++)
        {
            for (x = 0; x < 32; x++)
                *map++ = (buf + (31 - x))[y * 32] ^ 0x400;
        }
    }
    zero = 0;
    func_080C8B78(&zero, (void *)(0x06000400 + screenBase * 0x800), 0x01000300);
    if (D_087A8D34[id].objGfx != 0)
    {
        func_080C8B84(D_087A8D34[id].objGfx, (void *)0x06010000);
        func_0807F860(D_087AC010[id][pal], (void *)0x05000200, buf);
        return func_08077DF0(flip ? 2 : 0, D_08735FD0[id][0], D_08735FD0[id][1]);
    }
    return 0;
}
