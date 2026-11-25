#include "types.h"

struct Pilot
{
    u8 pad_0[3];
    u8 flags;
    u8 pad_4[0x3A];
    u8 field_3E;
    u8 pad_3F;
};

struct Big
{
    u8 pad_0[0x4E3C];
    u8 field_4E3C;
    u8 pad_4E3D[0x33];
    u8 field_4E70;
    u8 pad_4E71[0x4F7B - 0x4E71];
    u8 field_4F7B;
};

struct Cfg
{
    u8 field_0;
};

extern struct Pilot D_0203378C[];
extern struct Big D_02031A0C;
extern struct Cfg D_02020E3C;
extern u8 D_0203124F;
extern u8 D_02031250;
extern u8 D_0200C4A0;
extern u8 D_0200C4A2;
extern u16 D_0200C4A4;
extern const u8 D_08003EB6[];
extern const u8 D_08003EBF[];
extern const u8 D_08003EC6[];
extern const u8 D_08003ECF[];
extern const u8 D_08003EDC[];
extern const u8 D_08003EE5[];
extern const u8 D_08003EEC[];
extern const u8 D_08003EF5[];
extern const u8 D_08003EFC[];
extern const u8 D_08003EAE[];
extern const u8 D_08003EAA[];
extern const u8 D_08003EB2[];
u8 func_0809B834(u32, u8, u32, u32);
void func_0807BAD4(u32, u32, u8, u32, u8, u32);
void func_0807BEF4(u32, const u8 *, u32);
void func_0807C290(const u8 *);

s32 func_08094058(u8 side, u8 unit)
{
    u8 opts[9];
    u8 n;
    u8 i;
    struct Pilot *pilot;

    opts[0] = 0;
    opts[1] = 1;
    opts[2] = 2;
    n = 3;
    pilot = &D_0203378C[unit];
    if (pilot->field_3E != 0 && !(pilot->flags & 0x80))
    {
        opts[n] = 3;
        n++;
    }
    if (D_02031A0C.field_4E70 != 0x35 && D_02031A0C.field_4E3C != 0)
    {
        opts[n] = 4;
        n++;
    }
    if (D_0203124F > 1 && func_0809B834(0, side, 0x29, 0) == 0xFF)
    {
        opts[n] = D_02031250 + 4;
        n++;
    }
    while (1)
    {
        func_0807BAD4(1, 0, 7 - n, 8, n * 2 + 2, 0x80);
        for (i = 0; i < n; i++)
        {
            switch (opts[i])
            {
            case 0:
                func_0807BEF4(1, D_08003EB6, 0);
                break;
            case 1:
                func_0807BEF4(1, D_08003EBF, 0);
                break;
            case 2:
                func_0807BEF4(1, D_08003EC6, 0);
                break;
            case 3:
                func_0807BEF4(1, D_08003ECF, 0);
                break;
            case 4:
                func_0807BEF4(1, D_08003EDC, 0);
                break;
            case 5:
                func_0807BEF4(1, D_08003EE5, 0);
                break;
            case 6:
                func_0807BEF4(1, D_08003EEC, 0);
                break;
            case 7:
                func_0807BEF4(1, D_08003EF5, 0);
                break;
            case 8:
                func_0807BEF4(1, D_08003EFC, 0);
                break;
            }
        }
        if (D_02031A0C.field_4F7B == 0)
        {
            D_02031A0C.field_4F7B |= 4;
            func_0807C290(D_08003EAE);
        }
        else
        {
            func_0807C290(D_08003EAA);
        }
        func_0807C290(D_08003EB2);
        switch (D_0200C4A2)
        {
        case 0:
            if (D_0200C4A4 & 0x200)
                return -2;
            if (D_0200C4A4 & 0x100)
                return -3;
            if (D_02020E3C.field_0 == 0 && (D_0200C4A4 & 4))
                return -4;
            break;
        case 1:
            return opts[D_0200C4A0];
        case 2:
            return -1;
        }
    }
}
