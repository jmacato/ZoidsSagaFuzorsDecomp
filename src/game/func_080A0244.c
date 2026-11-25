#include "types.h"

struct Info
{
    u8 field_0;
    u8 field_1;
};

extern u16 D_0300004C;
extern u16 D_0300004E;
extern u16 D_03000052;
extern struct Info D_0201F6DC;
extern const u8 D_08003D35[];
extern const u8 D_08500694[];
extern const u8 D_080F4350[];
extern u8 D_02037D0C[];
extern u8 D_03000080;
extern u8 D_03000081;
extern u8 D_030057F5;

void func_08076FA0(void);
void func_0809F4F4(void);
void func_080B3A18(void);
void func_08079EF4(u8 a, u8 b, u16 c, u16 d, u16 e, u8 f, u8 g, u8 h, u16 i, u8 j);
void func_0807C290(const u8 *script);
void func_0807A1A4(void);
void func_0807FDD8(u8 a, u8 b, u8 c, u8 d, u8 e);
void func_080C8B78(const void *src, void *dst, u32 size);
void func_080C8B84(const void *src, void *dst);
void func_08076B08(void *a, u8 b);
void func_080785C0(u8 a, u8 b, u8 c, u8 d, u8 e);
void func_08078688(u8 a);
void func_08075DA8(u8 id, void (*fn)(void));
void func_080A01A8(void);

void func_080A0244(u8 arg)
{
    D_0300004C = 0x1741;
    D_0300004E = 0x87;
    D_03000052 = 0x218B;
    func_08076FA0();
    func_0809F4F4();
    func_080B3A18();
    func_08079EF4(1, 2, 0x80, 0x340, 0x3C0, 2, 0xE, 0, 0x3E6, 0xF);
    if (D_0201F6DC.field_0 == 0 || D_0201F6DC.field_1 == 0xFF)
    {
        func_0807C290(D_08003D35);
        func_0807A1A4();
    }
    func_0807FDD8(arg, 2, 1, 1, 0);
    func_080C8B78(D_08500694, (void *)0x050003C0, 8);
    func_080C8B84(D_080F4350, (void *)0x06017A80);
    func_08076B08(D_02037D0C, 1);
    D_03000080 |= 1;
    func_080785C0(0, 0, 0xF0, 0, 0x3B);
    func_08078688(0x3E);
    D_03000081 = D_030057F5 = 2;
    func_08075DA8(3, func_080A01A8);
}
