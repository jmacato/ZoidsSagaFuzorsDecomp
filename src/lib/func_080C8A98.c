#include "types.h"

#define REG_WAITCNT (*(vu16 *)0x04000204)

extern u16 D_030062E0[];
extern u16 D_03006240[];
extern void (*D_030076F0)(const u8 *, u8 *, u32);
extern u32 (*D_030076F4)(const u8 *, u8 *, u32);

void func_080C89CC(const u8 *, u8 *, u32);
void func_080C8A0C(const u8 *, u8 *, u32);
u32 func_080C8A4C(const u8 *, u8 *, u32);

void func_080C8A98(void)
{
    u16 *src;
    u16 *dest;
    u16 size;

    src = (u16 *)func_080C89CC;
    src = (u16 *)((s32)src & ~1);
    dest = D_030062E0;
    size = ((s32)func_080C8A0C - (s32)func_080C89CC) >> 1;
    while (size != 0)
    {
        *dest++ = *src++;
        size--;
    }
    D_030076F0 = (void (*)(const u8 *, u8 *, u32))((s32)D_030062E0 + 1);

    src = (u16 *)func_080C8A4C;
    src = (u16 *)((s32)src & ~1);
    dest = D_03006240;
    size = ((s32)func_080C8A98 - (s32)func_080C8A4C) >> 1;
    while (size != 0)
    {
        *dest++ = *src++;
        size--;
    }
    D_030076F4 = (u32 (*)(const u8 *, u8 *, u32))((s32)D_03006240 + 1);

    REG_WAITCNT = (REG_WAITCNT & ~3) | 3;
}
