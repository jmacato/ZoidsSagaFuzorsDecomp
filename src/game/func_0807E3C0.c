#include "types.h"

extern u8 D_0201F6DC;
extern u16 D_0300000E;
extern u8 D_03000081;
extern u8 D_030057F5;

void func_080C8FCC(u32);
u8 func_080796EC(void);
u8 func_08079724(void);
void func_08079544(u8, u8);
void func_0807970C(void);
void func_08075E28(u8);
void func_080836FC(void);
void func_080A1204(void);
void func_080A3370(void);

void func_0807E3C0(void)
{
    for (;;)
    {
        if (D_0300000E & 8)
        {
            if (func_080796EC())
            {
                if (func_08079724())
                    break;
                func_08079544(0x12, 0);
                func_0807970C();
                break;
            }
            if (func_08079724())
            {
                func_0807970C();
                break;
            }
            func_0807970C();
            func_08079544(0x12, 0);
            func_0807970C();
            break;
        }
        func_080C8FCC(1);
        if (D_0201F6DC == 0)
            break;
    }
    func_08075E28(5);
    func_08075E28(6);
    func_080836FC();
    func_080A1204();
    func_080A3370();
    D_03000081 = D_030057F5 = 1;
}
