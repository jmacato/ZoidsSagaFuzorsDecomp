#include "types.h"

struct Link
{
    u8 pad0[0x14];
    u32 field_14;
    u32 field_18;
    u8 *field_1C;
    u8 *field_20;
    u8 *field_24;
    u8 *field_28;
    u8 *field_2C;
    u8 buf0[0x18];
    u8 buf1[0x18];
    u8 buf2[0x30];
    u8 buf3[0x30];
    u8 buf4[0x30];
};

extern struct Link D_030024B8;
extern const u8 D_08000640[];

void func_080C8B7C(const void *, void *, u32);
void func_08076400(void);

void func_08076018(void)
{
    u32 zero;

    *(vu16 *)0x04000208 = 0;
    *(vu16 *)0x04000200 &= 0xFF3F;
    *(vu16 *)0x04000208 = 1;
    *(vu16 *)0x04000134 = 0;
    *(vu16 *)0x04000128 = 0x2000;
    *(vu16 *)0x04000128 |= 0x4003;
    *(vu16 *)0x04000128 |= 0x80;
    zero = 0;
    func_080C8B7C(&zero, &D_030024B8, 0x0500003C);
    func_080C8B7C(D_08000640, (void *)0x03002358, 0x04000010);
    func_080C8B7C(func_08076400, (void *)0x03002398, 0x04000048);
    D_030024B8.field_14 = 12;
    D_030024B8.field_18 = 12;
    D_030024B8.field_1C = D_030024B8.buf0;
    D_030024B8.field_20 = D_030024B8.buf1;
    D_030024B8.field_24 = D_030024B8.buf2;
    D_030024B8.field_28 = D_030024B8.buf3;
    D_030024B8.field_2C = D_030024B8.buf4;
    *(vu16 *)0x04000208 = 0;
    *(vu16 *)0x04000200 |= 0x80;
    *(vu16 *)0x04000208 = 1;
}
