#include "types.h"

extern u8 D_0300068C;
extern u8 D_03000080;
extern s32 D_03000060[8];
extern u16 D_0300004C;
extern u16 D_0300004E;
extern u16 D_03000050;
extern u16 D_03000052;
extern u16 D_03000054;
extern u16 D_03000056;
extern u16 D_03000058;
extern u16 D_0300005A;
extern u16 D_0300005C;
extern void (*D_03000010)(void);

void func_080C6E7C(void);
void func_08075158(void);
void func_08076DB4(u8);
void func_080792BC(u8);
void func_0807DC5C(u8);
void func_080A2278(u8);
void func_080751FC(void);
void func_08075928(void);
void func_080783AC(void);
void func_08079C48(u8);
void func_08075850(void);
void func_08075FF4(void);
void func_08075294(void);
void func_08075298(void);

void func_080752C4(void)
{
    u8 odd = D_0300068C & 1;

    func_080C6E7C();
    func_08075158();
    if (D_03000080)
    {
        if (D_03000080 & 1)
            func_08076DB4(odd);
        if (D_03000080 & 2)
            func_080792BC(odd);
        if (D_03000080 & 4)
            func_0807DC5C(odd);
        if (D_03000080 & 8)
            func_080A2278(odd);
    }
    func_080751FC();
    if (D_0300068C)
        func_08075928();
    if (odd)
    {
        *(vu16 *)0x04000010 = D_03000060[0] / 256;
        *(vu16 *)0x04000012 = D_03000060[1] / 256;
        *(vu16 *)0x04000014 = D_03000060[2] / 256;
        *(vu16 *)0x04000016 = D_03000060[3] / 256;
        *(vu16 *)0x04000018 = D_03000060[4] / 256;
        *(vu16 *)0x0400001A = D_03000060[5] / 256;
        *(vu16 *)0x0400001C = D_03000060[6] / 256;
        *(vu16 *)0x0400001E = D_03000060[7] / 256;
        *(vu16 *)0x04000000 = D_0300004C;
        *(vu16 *)0x04000008 = D_0300004E;
        *(vu16 *)0x0400000A = D_03000050;
        *(vu16 *)0x0400000C = D_03000052;
        *(vu16 *)0x0400000E = D_03000054;
        *(vu16 *)0x04000050 = D_03000056;
        *(vu16 *)0x04000052 = D_03000058;
        *(vu16 *)0x04000054 = D_0300005A;
        *(vu16 *)0x0400004C = D_0300005C;
        func_080783AC();
        D_03000010();
    }
    func_08079C48(odd);
    if (!odd)
    {
        func_08075850();
        func_08075FF4();
    }
    func_08075294();
    func_08075298();
}
