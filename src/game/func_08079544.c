#include "types.h"

extern u8 D_03005714;
extern u8 D_03005715;
extern u8 D_03005716;
extern u8 D_0300571C;
extern u8 D_0300571D;
extern s16 D_030057C4[];
extern const u8 D_087B4CBC[];

void func_080787F8(u16, u16, u8);
void func_080786DC(const void *, u16, u16, const void *, u16, u16, u16, u16, u8);
void func_08078850(u8, u8, u8);
void func_080787A4(s16 *, u16, u16, u8);
void func_080788B8(u16, u16, u8);
void func_0807981C(void);

void func_08079544(u8 type, u8 duration)
{
    u8 sub;

    D_03005714 = type;
    D_03005716 = 0;
    type &= 0x7F;
    if (type <= 4)
    {
        D_03005715 = duration;
    }
    else if (type <= 16)
    {
        if (type == 5 || type == 6)
        {
            if (type == 5)
                func_080787F8(0x3F3F, 0, 8);
            else
                func_080787F8(0, 0x3F, 8);
            D_03005715 = 0x21;
        }
        else if (type == 7 || type == 8)
        {
            if (type == 7)
                func_080786DC(D_087B4CBC, 0, 0, D_087B4CBC + 0x280, 0, 0, 0x3F3F, 0, 8);
            else
                func_080786DC(D_087B4CBC, 0, 0, D_087B4CBC + 0x280, 0, 0, 0, 0x3F, 8);
            D_03005715 = 0x24;
        }
        else if ((sub = type - 9) <= 3)
        {
            func_08078850(type != 9 && type != 11, sub > 1, 8);
            D_03005715 = 0x20;
        }
        else if (type == 13 || type == 14)
        {
            if (type == 13)
                func_080787A4(D_030057C4, 0x3F3F, 0, 8);
            else
                func_080787A4(D_030057C4, 0x3F3F, 0, 8);
            D_03005715 = 0x20;
        }
        if (type == 15 || type == 16)
        {
            if (type == 15)
                func_080788B8(0x3F3F, 0, 8);
            else
                func_080788B8(0, 0x3F, 8);
            D_03005715 = 0x14;
        }
        *(vu16 *)0x05000000 = 0;
    }
    else
    {
        D_03005715 = 0x14;
        D_0300571C = 0;
        D_0300571D = 1;
        func_0807981C();
    }
}
