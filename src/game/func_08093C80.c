#include "types.h"

struct Cfg
{
    u8 field_0;
};

struct Big
{
    u8 field_0;
    u8 pad_1[0x4E9F];
    u8 field_4EA0;
};

extern struct Cfg D_02020E3C;
extern struct Big D_02031A0C;
extern u8 D_0201F6DC;
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern u16 D_0200C4A4;
extern const u8 D_08003E07[];
extern const u8 D_08003E3F[];
extern const u8 D_08003E52[];
extern const u8 D_08003E67[];
extern const u8 D_08003E33[];
extern const u8 D_08003E37[];
extern const u8 D_08003E3B[];
void func_0807C290(const u8 *);
void func_0807BAD4(u32, u32, u8, u32, u32, u32);
void func_0807BEF4(u32, const u8 *, u32);

s32 func_08093C80(void)
{
    u8 opts[3];
    u8 n;
    u8 i;

    if (D_0201F6DC == 0 && D_02020E3C.field_0 != 2)
    {
        opts[0] = 0;
        opts[1] = 1;
        n = 2;
        if (D_02031A0C.field_4EA0 == 0)
        {
            opts[n] = 2;
            n++;
        }
    }
    else
    {
        opts[0] = 0;
        opts[1] = 1;
        n = 2;
    }
    while (1)
    {
        func_0807C290(D_08003E07);
        func_0807BAD4(1, 0, 7 - n, 0xC, n * 2 + 2, 0x80);
        for (i = 0; i < n; i++)
        {
            switch (opts[i])
            {
            case 0:
                func_0807BEF4(1, D_08003E3F, 0);
                break;
            case 1:
                func_0807BEF4(1, D_08003E52, 0);
                break;
            case 2:
                func_0807BEF4(1, D_08003E67, 0);
                break;
            }
        }
        if (D_02031A0C.field_0 == 1)
            func_0807C290(D_08003E33);
        else
            func_0807C290(D_08003E37);
        func_0807C290(D_08003E3B);
        switch (D_0200C4A2)
        {
        case 0:
            if (D_0200C4A4 & 0x200)
                return -2;
            return -3;
        case 1:
            return opts[D_0200C4A0];
        case 2:
            return -1;
        }
    }
}
