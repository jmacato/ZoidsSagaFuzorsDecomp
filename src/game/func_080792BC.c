#include "types.h"

struct Entry
{
    u32 win;
    u32 field_4;
};

extern u8 D_0300569B;
extern u8 D_0300568C;
extern u8 D_03000080;
extern u16 D_030056A0;
extern u16 D_030056A2;
extern u16 D_030056A4;
extern u16 D_030056A6;
extern u8 D_030056B8[];
extern const u8 D_080006F0[];
extern u8 D_030056B6;
extern struct Entry D_02000000[2][160];
extern u16 D_0300569C;
extern u16 D_0300569E;

void func_08076F30(u8);
void func_08076EE0(u8, void (*)(void));
void func_080C8B7C(const void *, void *, u32);

void func_080792BC(u8 swap)
{
    u8 prevMode = D_0300569B & 7;
    u8 prevFlag = D_0300569B & 8;
    u8 mode = D_0300568C & 7;
    struct Entry *entry;

    switch (mode)
    {
    default:
        if (!(D_0300568C & 8))
        {
            vu16 *dma = (vu16 *)0x040000B0;
            dma[5] &= 0xC5FF;
            dma[5] &= 0x7FFF;
            dma[5];
        }
        break;
    case 0:
        if (!swap)
            goto apply;
        if (prevMode != 0)
        {
            if (prevMode != 1 && prevFlag == 8)
            {
                *(vu16 *)0x04000208 = 0;
                func_08076F30(0);
                *(vu16 *)0x04000208 = 1;
            }
            D_03000080 &= ~2;
        }
        goto done;
    case 1:
        if (!swap)
            goto apply;
        if (prevMode != 1 && prevFlag == 8)
        {
            *(vu16 *)0x04000208 = 0;
            func_08076F30(0);
            *(vu16 *)0x04000208 = 1;
        }
        *(vu16 *)0x04000040 = D_030056A0;
        *(vu16 *)0x04000044 = D_030056A2;
        *(vu16 *)0x04000042 = D_030056A4;
        *(vu16 *)0x04000046 = D_030056A6;
        goto done;
    }
    {
        if (swap)
        {
            if (prevMode <= 1 && (D_0300568C & 8))
            {
                *(vu16 *)0x04000208 = 0;
                func_08076EE0(0, (void (*)(void))D_030056B8);
                func_080C8B7C(D_080006F0, D_030056B8, 0x04000017);
                *(vu16 *)0x04000208 = 1;
            }
            D_030056B6 ^= 1;
        }
        if (!(D_0300568C & 8))
        {
            vu32 *dma = (vu32 *)0x040000B0;
            dma[0] = (u32)&D_02000000[D_030056B6][1];
            dma[1] = 0x04000040;
            dma[2] = 0xA6600002;
            dma[2];
        }
        entry = D_02000000[D_030056B6];
        *(vu32 *)0x04000040 = entry->win;
        *(vu32 *)0x04000044 = entry->field_4;
    }
done:
    if (swap)
        D_0300569B = D_0300568C;
apply:
    if (D_0300568C && swap)
    {
        *(vu16 *)0x04000048 = D_0300569C;
        *(vu16 *)0x0400004A = (*(vu16 *)0x0400004A & 0xFF00) | D_0300569E;
    }
}
