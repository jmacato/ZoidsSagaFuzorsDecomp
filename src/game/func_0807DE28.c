#include "types.h"

struct Unk03000060
{
    u32 field_0;
    u32 field_4;
};

extern u16 D_0300004C;
extern u16 D_0300004E;
extern struct Unk03000060 D_03000060;
extern u16 D_0300000E;
extern u8 D_0201F5F6;
extern const u8 D_080E67F8[];
extern const u8 D_080E7024[];
extern const u8 D_080E704C[];

void func_080C8B84(const void *, void *);
void func_08079544(u8, u8);
void func_080C8FCC(u32);
u8 func_080796EC(void);
void func_0807970C(void);

void func_0807DE28(void)
{
    u16 i;

    D_0300004C = 0x1140;
    D_0300004E = 4;
    D_03000060.field_0 = D_03000060.field_4 = 0;
    func_080C8B84(D_080E67F8, (void *)0x06004000);
    func_080C8B84(D_080E7024, (void *)0x05000000);
    func_080C8B84(D_080E704C, (void *)0x06000000);
    func_08079544(3, 16);
    for (i = 0; i < 180; i++)
    {
        if (func_080796EC() && (D_0300000E & 8))
            break;
        func_080C8FCC(1);
    }
    func_08079544(2, 16);
    func_0807970C();
    D_0201F5F6 = 0;
}
