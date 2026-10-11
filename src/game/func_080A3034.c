#include "types.h"

#define OBJ_PLTT ((u16 (*)[16])0x05000200)

struct Obj
{
    u8 pad_0[0x16];
    u8 palette;
};

struct State
{
    u8 pad_0[0x8D1];
    u8 fadeLoaded;
    u8 fadeActive;
    u8 fadeStep;
    u16 fadeBuf[16];
    u8 pad_8F4[0x68];
    struct Obj **field_95C;
};

extern struct State D_02036E7C;

void func_080C8B7C(const void *src, void *dst, u32 ctrl);

void func_080A3034(void)
{
    u8 i, r, g, b;
    if (D_02036E7C.field_95C != 0 && *D_02036E7C.field_95C != 0 && D_02036E7C.fadeActive != 0)
    {
        if (D_02036E7C.fadeLoaded == 0)
        {
            func_080C8B7C(OBJ_PLTT[(*D_02036E7C.field_95C)->palette], D_02036E7C.fadeBuf, 0x04000008);
            D_02036E7C.fadeLoaded = 1;
        }
        for (i = 0; i < 16; i++)
        {
            r = D_02036E7C.fadeBuf[i] & 0x1F;
            g = (D_02036E7C.fadeBuf[i] >> 5) & 0x1F;
            b = (D_02036E7C.fadeBuf[i] >> 10) & 0x1F;
            r = r + (0x1F - r) * (32 - D_02036E7C.fadeStep) / 32;
            g = g + (0x1F - g) * (32 - D_02036E7C.fadeStep) / 32;
            b = b + (0x1F - b) * (32 - D_02036E7C.fadeStep) / 32;
            OBJ_PLTT[(*D_02036E7C.field_95C)->palette][i] = (b << 10) | (g << 5) | r;
        }
        if (++D_02036E7C.fadeStep > 32)
        {
            D_02036E7C.fadeStep = 0;
            D_02036E7C.fadeActive = 0;
        }
    }
}
