#include "types.h"

struct Cfg
{
    u8 field_0;
    u8 pad_1[3];
    u32 field_4;
};

struct Big
{
    u8 pad_0[0x4EA0];
    u8 field_4EA0;
};

extern struct Cfg D_02020E3C;
extern struct Big D_02031A0C;
extern u8 D_0201F6DC;
extern u8 D_0200C4A0;
extern const u8 D_08003D7A[];
extern const u8 D_08003DA4[];
extern const u8 D_08003DB5[];
extern const u8 D_08003DC4[];
extern const u8 D_08003DD9[];
extern const u8 D_08003D9C[];
extern const u8 D_08003DA0[];
void func_0807C290(const u8 *);
void func_0807BAD4(u32, u32, u8, u32, u8, u32);
void func_0807BEF4(u32, const u8 *, u32);

u8 func_08093400(void)
{
    u8 opts[4];
    u8 n;
    u8 i;

    if (D_02020E3C.field_4 == 0 && D_02020E3C.field_0 == 0)
    {
        opts[0] = 0;
        opts[1] = 1;
        opts[2] = 2;
        n = 3;
        if (D_0201F6DC == 0 && D_02031A0C.field_4EA0 == 0)
        {
            opts[n] = 3;
            n++;
        }
    }
    else if (D_02020E3C.field_0 == 1)
    {
        opts[0] = 0;
        n = 1;
        if (D_02031A0C.field_4EA0 == 0)
        {
            opts[n] = 3;
            n++;
        }
    }
    else
    {
        opts[0] = 0;
        opts[1] = 2;
        n = 2;
    }
    func_0807C290(D_08003D7A);
    func_0807BAD4(1, 0, 7 - n, 0xC, n * 2 + 2, 0x80);
    for (i = 0; i < n; i++)
    {
        switch (opts[i])
        {
        case 0:
            func_0807BEF4(1, D_08003DA4, 0);
            break;
        case 1:
            func_0807BEF4(1, D_08003DB5, 0);
            break;
        case 2:
            func_0807BEF4(1, D_08003DC4, 0);
            break;
        case 3:
            func_0807BEF4(1, D_08003DD9, 0);
            break;
        }
    }
    func_0807C290(D_08003D9C);
    func_0807C290(D_08003DA0);
    return opts[D_0200C4A0];
}
