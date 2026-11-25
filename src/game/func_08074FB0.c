#include "types.h"

extern const u16 D_087345D8;
extern u16 D_0300004C;
extern u8 D_03000088;
extern u8 D_03000089;
extern u8 D_03000081;
extern u8 D_030057F5;
extern u8 D_03000080;
extern u32 D_0201F5F0;

void func_08075624(void);
void func_080C7550(void);
void func_080C8A98(void);
void func_08075520(void);
void func_080784DC(void);
void func_08079514(void);
void func_08079544(u8, u8);
void func_0807981C(void);
void func_080750F0(u8);
u8 func_080796EC(void);
void func_08079E70(void);
void func_08075DA8(u8, void (*)(void));
void func_0807DDE0(void);
void func_080750B4(void);

void func_08074FB0(void)
{
    vu32 zero;
    vu32 *dma;

    *(vu16 *)0x04000204 = D_087345D8;
    zero = 0;
    dma = (vu32 *)0x040000D4;
    dma[0] = (u32)&zero;
    dma[1] = 0x02000000;
    dma[2] = 0x85010000;
    dma[2];
    zero = 0;
    dma[0] = (u32)&zero;
    dma[1] = 0x03000000;
    dma[2] = 0x85001EC0;
    dma[2];
    func_08075624();
    *(vu16 *)0x04000208 = 1;
    *(vu16 *)0x04000200 = 0x2001;
    *(vu16 *)0x04000004 = 8;
    D_0300004C = *(vu16 *)0x04000000 = 0;
    func_080C7550();
    func_080C8A98();
    D_03000088 = 1;
    D_03000089 = 0;
    D_03000081 = D_030057F5 = 1;
    D_03000080 = 0;
    func_08075520();
    func_080784DC();
    func_08079514();
    func_08079544(4, 8);
    while (!func_080796EC())
    {
        func_0807981C();
        func_080750F0(D_03000081);
    }
    func_08079E70();
    D_0201F5F0 = 0;
    func_08075DA8(1, func_0807DDE0);
    func_080750B4();
}
