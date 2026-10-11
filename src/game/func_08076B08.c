#include "types.h"

struct Unk030025A8
{
    u8 pad0[0xC];
    u16 field_C;
    u8 padE[0x1E];
    u16 field_2C;
};

extern u8 D_03002610;
extern u8 D_03002611;
extern u8 D_03002614[];
extern u32 D_0300260C;
extern struct Unk030025A8 D_030025A8;
extern const u8 D_08000680[];

void func_08076EE0(u8, void (*)(void));
void func_080C8B7C(const void *, void *, u32);
void func_08076B98(void);

void func_08076B08(u32 arg, u8 mode)
{
    *(vu16 *)0x04000208 = 0;
    D_03002610 = 0;
    D_03002611 = mode;
    if (mode == 1)
    {
        func_08076EE0(0, (void (*)(void))D_03002614);
        func_080C8B7C(D_08000680, D_03002614, 0x0400001C);
    }
    D_0300260C = arg;
    D_030025A8.field_2C = D_030025A8.field_C + 1;
    func_08076B98();
    *(vu16 *)0x04000208 = 1;
}
