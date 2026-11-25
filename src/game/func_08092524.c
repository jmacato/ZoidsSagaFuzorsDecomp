#include "types.h"

struct Pic
{
    u16 w;
    u16 h;
    u8 pad_4[0x14];
    u8 *data;
    u8 pad_1C[8];
};

struct Cfg
{
    u8 pad_0[0x1A];
    u16 pic;
};

extern struct Cfg D_020209D8;
extern const struct Pic D_0877E074[];
extern const u8 D_080F687C[];
extern u8 D_02001480[];
void func_080C8B7C(const void *, void *, u32);
void func_0807F860(const u8 *, void *, u8 *);

void func_08092524(u8 charBase, u8 screenBase)
{
    vu16 zero;
    vu16 zero2;
    u16 w;
    u16 h;
    u8 *src;
    u16 y;
    u16 x;
    u8 i;
    u32 row;

    zero = 0;
    func_080C8B7C((void *)&zero, (void *)(0x06000000 + charBase * 0x4000), 0x01002410);
    zero2 = 0;
    func_080C8B7C((void *)&zero2, (void *)(0x06000000 + screenBase * 0x800), 0x01000400);
    func_0807F860(D_080F687C, (void *)0x05000000, D_02001480);
    w = D_0877E074[D_020209D8.pic].w / 2;
    h = D_0877E074[D_020209D8.pic].h / 2;
    src = D_0877E074[D_020209D8.pic].data;
    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x += 8)
        {
            row = 0;
            for (i = 0; i < 8; i++)
            {
                if (x + i < w)
                {
                    if (*src & 0x40)
                        row |= 0xF << (i * 4);
                    else
                        row |= ((*src & 0x1F) + 1) << (i * 4);
                    src++;
                }
                else
                {
                    break;
                }
            }
            *(u32 *)(0x06000000 + charBase * 0x4000 + ((y / 8) * 24 + x / 8 + 1) * 32 + (y % 8) * 4) = row;
        }
    }
    for (y = 0; y < 32; y++)
    {
        for (x = 0; x < 32; x++)
        {
            if (x < 24 && y < 24)
                *(u16 *)(0x06000000 + screenBase * 0x800 + (y * 32 + x) * 2) = x + y * 24 + 1;
            else
                *(u16 *)(0x06000000 + screenBase * 0x800 + (y * 32 + x) * 2) = 0;
        }
    }
}
