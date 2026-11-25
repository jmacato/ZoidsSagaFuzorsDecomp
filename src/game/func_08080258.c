#include "types.h"

extern u16 D_03000B18;
extern u32 D_0201F5F0;
extern u8 D_0201F5F6;
extern u8 D_03000081;
extern u8 D_030057F5;
extern const u8 D_0802461E[];

u8 func_080796EC(void);
u8 func_08079724(void);
u8 func_080801F4(u8);
void func_080C8FCC(u32);
void func_08075E28(u8);
void func_080801D0(void);
void func_0807C290(const u8 *);
void func_08079544(u8, u8);
void func_0807970C(void);
void func_08075DA8(u8, void (*)(void));
void func_0807DDE0(void);

void func_08080258(void)
{
    while (1)
    {
        if (func_080796EC() && !func_08079724())
        {
            switch (func_080801F4(1))
            {
            case 2:
                goto done;
            case 0:
                D_03000081 = 1;
                break;
            }
        }
        func_080C8FCC(1);
    }
done:
    func_08075E28(1);
    func_08075E28(3);
    func_08075E28(4);
    func_08075E28(5);
    func_080801D0();
    D_03000B18 |= 4;
    func_0807C290(D_0802461E);
    func_08079544(0x12, 0);
    func_0807970C();
    D_0201F5F0 = 1;
    D_0201F5F6 = 1;
    D_03000081 = D_030057F5 = 1;
    func_08075DA8(1, func_0807DDE0);
}
