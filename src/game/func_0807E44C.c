#include "types.h"

extern u8 D_0201F5F4;
extern const u8 D_08000868[];
extern const u8 D_0800087D[];
extern const u8 D_080008B4[];
extern const u8 D_08000930[];
extern const u8 D_080008F5[];

void func_0807EC08(void);
void func_0807EC28(void);
void func_0807EC70(void);
void func_0807EB78(void);
u8 func_0807DA78(void);
u8 func_0807DAC4(void);
u8 func_0807DB5C(void);
u8 func_0807DB10(void);
void func_0807DAA0(void);
void func_0807DAEC(void);
void func_0807DB84(void);
void func_0807DB38(void);
void func_08091DB4(void);
void func_0807C290(const u8 *);
void func_08079544(u8, u8);
void func_0807970C(void);

void func_0807E44C(void)
{
    s32 shown;

    func_0807EC08();
    func_0807EC28();
    func_0807EC70();
    func_0807EB78();
    D_0201F5F4 = shown = 0;
    switch (func_0807DA78())
    {
    case 0:
        func_08091DB4();
        func_0807C290(D_08000868);
        func_08079544(0xF, 0);
        func_0807C290(D_0800087D);
        func_0807DAA0();
        shown = 1;
        break;
    case 1:
        D_0201F5F4 = 1;
        break;
    }
    if (!func_0807DAC4())
    {
        if (!shown)
        {
            func_08091DB4();
            func_0807C290(D_08000868);
            func_08079544(0xF, 0);
        }
        func_0807C290(D_080008B4);
        func_0807DAEC();
        shown = 1;
    }
    if (!func_0807DB5C())
    {
        if (!shown)
        {
            func_08091DB4();
            func_0807C290(D_08000868);
            func_08079544(0xF, 0);
        }
        func_0807C290(D_08000930);
        func_0807DB84();
        shown = 1;
    }
    if (!func_0807DB10())
    {
        if (!shown)
        {
            func_08091DB4();
            func_0807C290(D_08000868);
            func_08079544(0xF, 0);
        }
        func_0807C290(D_080008F5);
        func_0807DB38();
        shown = 1;
    }
    if (shown)
    {
        func_08079544(0x10, 0);
        func_0807970C();
    }
}
