#include "types.h"

#define DmaSet(src, dest, control)                \
{                                                 \
    vu32 *dmaRegs = (vu32 *)0x040000D4;           \
    dmaRegs[0] = (u32)(src);                      \
    dmaRegs[1] = (u32)(dest);                     \
    dmaRegs[2] = (u32)(control);                  \
    dmaRegs[2];                                   \
}

extern const u8 D_08000104[];
extern u8 D_0300008C[];
extern void *D_03007FFC;
extern const u8 D_087345A0[];
extern u8 D_03000014[];
extern const u8 D_080004C8[];
extern u8 D_03000690[];
extern const u8 D_08000520[];
extern u8 D_0300089C[];
extern const u8 D_080005AC[];
extern u8 D_03000940[];
extern u16 (*D_03000010)(void);
extern u16 D_030009C2[];
extern u16 D_030009C0;
extern u8 D_0300028C[];
extern s32 D_03000060[8];
extern u16 D_03000056;
extern u16 D_03000058;
extern u16 D_0300005A;
extern u8 D_0300068C;
extern u8 D_0300068D;
extern u16 D_03000B18;
extern u32 D_03000B14;

void func_08075D3C(void);
void func_080758B8(void);
void func_08075474(void);
void func_08075488(void);
void func_08075E48(void);
void func_080C8EE8(u32);

void func_08075624(void)
{
    vu16 fill16;
    vu32 fill32;
    u8 i;

    DmaSet(D_08000104, D_0300008C, 0x84000080);
    D_03007FFC = D_0300008C;
    DmaSet(D_087345A0, D_03000014, 0x8400000E);
    DmaSet(D_080004C8, D_03000690, 0x84000080);
    DmaSet(D_08000520, D_0300089C, 0x84000029);
    DmaSet(D_080005AC, D_03000940, 0x8400001F);
    D_03000010 = (u16 (*)(void))D_03000940;
    for (i = 0; i < 128; i++)
        D_030009C2[i] = D_03000010();
    D_030009C0 = 0x7FFF;
    fill16 = 0;
    DmaSet(&fill16, 0x06000000, 0x8100C000);
    fill16 = 0x7FFF;
    DmaSet(&fill16, 0x05000000, 0x81000002);
    fill32 = 0;
    DmaSet(&fill32, D_0300028C, 0x85000100);
    DmaSet(D_0300028C, 0x07000000, 0x84000100);
    func_08075D3C();
    func_080758B8();
    func_08075474();
    func_08075488();
    D_03000060[0] = D_03000060[1] = D_03000060[2] = D_03000060[3] = D_03000060[4] = D_03000060[5] = D_03000060[6] = D_03000060[7] = 0;
    D_03000056 = D_03000058 = D_0300005A = 0;
    func_08075E48();
    func_080C8EE8(1);
    D_0300068C = 0;
    D_0300068D = 0;
    D_03000B18 = D_03000B14 = 0;
}
